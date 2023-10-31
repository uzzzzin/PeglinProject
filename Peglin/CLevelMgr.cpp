#include "pch.h"
#include "CLevelMgr.h"

#include "CEngine.h"
#include "CCamera.h"
#include "CLogMgr.h"
#include "CCollisionMgr.h"

#include "CLevel.h"
#include "CPlayLevel.h"
#include "CStartLevel.h"
//#include "CEditorLevel.h"


#include "CPlayer.h"
#include "CMonster.h"
#include "CProjectile.h"
#include "CGuided.h"
#include "CPlatform.h"

CLevelMgr::CLevelMgr()
	: m_pCurLevel(nullptr)
{

}

CLevelMgr::~CLevelMgr()
{
	for (UINT i = 0; i < (UINT)LEVEL_TYPE::END; ++i)
	{
		if (nullptr != m_arrLevels[i])
			delete m_arrLevels[i];
	}
}


void CLevelMgr::init()
{
	// ��� ���� ����
	m_arrLevels[(UINT)LEVEL_TYPE::START_LEVEL] = new CStartLevel;
	m_arrLevels[(UINT)LEVEL_TYPE::PLAY_LEVEL] = new CPlayLevel;


	// ���� �ʱ�ȭ
	for (UINT i = 0; i < (UINT)LEVEL_TYPE::END; ++i)
	{
		m_arrLevels[i]->init();
	}

	// Level
	::ChangeLevel(LEVEL_TYPE::START_LEVEL);
}

void CLevelMgr::tick()
{
	if (nullptr != m_pCurLevel)
		m_pCurLevel->tick();
}

void CLevelMgr::render(HDC _dc)
{
	if (nullptr == m_pCurLevel)
		return;

	// Level Render
	// ȭ�� Clear
	POINT ptResolution = CEngine::GetInst()->GetResolution();
	Rectangle(_dc, -1, -1, ptResolution.x + 1, ptResolution.y + 1);

	// ���� render
	m_pCurLevel->render(_dc);

	// Log
	CLogMgr::GetInst()->tick(_dc);
}


void CLevelMgr::ChangeLevel(LEVEL_TYPE _Type)
{
	if (m_pCurLevel == m_arrLevels[(UINT)_Type])
		return;

	if (nullptr != m_pCurLevel)
		m_pCurLevel->exit();

	m_pCurLevel = m_arrLevels[(UINT)_Type];

	m_pCurLevel->enter();

	m_pCurLevel->begin();
}