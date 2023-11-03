#include "pch.h"
#include "CEngine.h"


// Manager
#include "CTimeMgr.h"
#include "CKeyMgr.h"
#include "CAssetMgr.h"
#include "CLevelMgr.h"
#include "CPathMgr.h"
#include "CTaskMgr.h"
#include "CCollisionMgr.h"
#include "CGCMgr.h"
#include "CLogMgr.h"
#include "CCamera.h"
#include "CUIMgr.h"
#include "CSoundMgr.h"

#include "CTexture.h"

CEngine::CEngine()
	: m_hWnd(nullptr)
	, m_ptResolution{}
	, m_DC(nullptr)
	, m_bDebugRender(true)
	, m_arrPen{}
{
}

CEngine::~CEngine()
{
	ReleaseDC(m_hWnd, m_DC);

	for (UINT i = 0; i < PEN_END; ++i)
	{
		DeleteObject(m_arrPen[i]);
	}
}


void CEngine::CreateDefaultGDI()
{
	m_arrPen[RED_PEN] = CreatePen(PS_SOLID, 1, RGB(255, 20, 20));
	m_arrPen[GREEN_PEN] = CreatePen(PS_SOLID, 1, RGB(20, 255, 20));
	m_arrPen[BLUE_PEN] = CreatePen(PS_SOLID, 1, RGB(20, 20, 255));
}

void CEngine::init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	ChangeWindowSize(_ptResolution, false);
	ShowWindow(m_hWnd, true);

	// DC : Device Context
	// pen : Black 
	// brush : White
	// Bitmap(�׸� �׸� ��) : �ڵ鿡 �ش��ϴ� ������ ��Ʈ��
	m_DC = GetDC(m_hWnd);

	// �߰� ��Ʈ�� ����
	m_SubTex = CAssetMgr::GetInst()->CreateTexture(L"SubTex", m_ptResolution.x, m_ptResolution.y);

	// Manager �ʱ�ȭ
	CTimeMgr::GetInst()->init();
	CKeyMgr::GetInst()->init();
	CPathMgr::init();
	CSoundMgr::GetInst()->init();
	CLevelMgr::GetInst()->init();

	// Default GDI Object ����
	CreateDefaultGDI();
}

void CEngine::tick()
{
	// Manager Update
	CTimeMgr::GetInst()->tick();
	CKeyMgr::GetInst()->tick();
	CCamera::GetInst()->tick();

	if (KEY_TAP(KEY::NUM8))
	{
		m_bDebugRender ? m_bDebugRender = false : m_bDebugRender = true;
	}

	// LevelMgr
	CLevelMgr::GetInst()->tick();
	CCollisionMgr::GetInst()->tick();
	CUIMgr::GetInst()->tick();

	CLevelMgr::GetInst()->render(m_SubTex->GetDC());

	// Camera render
	CCamera::GetInst()->render(m_SubTex->GetDC());

	// m_SubDC -> m_DC �� ��Ʈ�� ����
	BitBlt(CEngine::GetInst()->GetMainDC()
		, 0, 0
		, m_ptResolution.x, m_ptResolution.y
		, m_SubTex->GetDC()
		, 0, 0, SRCCOPY);


	// Task Execute
	CTaskMgr::GetInst()->tick();

	// CG
	CGCMgr::GetInst()->tick();
}


void CEngine::ChangeWindowSize(POINT _ptResolution, bool _bMenu)
{
	m_ptResolution = _ptResolution;

	RECT rt = { 0, 0, _ptResolution.x, _ptResolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, _bMenu);
	SetWindowPos(m_hWnd, nullptr, 10, 10, rt.right - rt.left, rt.bottom - rt.top, 0);
}