#include "pch.h"
#include "CBtnUI.h"

#include "CEngine.h"
#include "resource.h"
#include "CKeyMgr.h"
#include "CAssetMgr.h"
#include "CLogMgr.h"
#include "CSound.h"

#include "CTexture.h"

CBtnUI::CBtnUI()
	: m_CallBackFunc(nullptr)
	, m_Animator(nullptr)
	, m_SndEffectH(nullptr)
	, m_SndEffectC(nullptr)
	, m_Inst(nullptr)
	, m_Delegate(nullptr)
	, wNAnimName(L"")
	, wHAnimName(L"")
	, wPAnimName(L"")

{
	m_Animator = AddComponent<CAnimator>();
	m_SndEffectH = CAssetMgr::GetInst()->LoadSound(L"BtnHovered", L"sound\\BtnHovered.wav");
	m_SndEffectC= CAssetMgr::GetInst()->LoadSound(L"BtnClicked", L"sound\\BtnClicked.wav");
}

CBtnUI::CBtnUI(const wstring& _strName, const wstring& _strKey, const wstring& _strRelativePath)
{
}

CBtnUI::~CBtnUI()
{
}

void CBtnUI::SetNormalImg(const wstring& _strRelativePath2, const wstring& _animName)
{
	
	m_Animator->LoadAnimation(_strRelativePath2);
	wNAnimName = _animName;
	m_Animator->Play(wNAnimName, true);
}

void CBtnUI::SetPressedImg(const wstring& _strRelativePath2, const wstring& _animName)
{
	m_Animator->LoadAnimation(_strRelativePath2);
	wPAnimName = _animName;

}

void CBtnUI::SetHoverImg(const wstring& _strRelativePath2, const wstring& _animName)
{
	m_Animator->LoadAnimation(_strRelativePath2);
	wHAnimName = _animName;
}

void CBtnUI::tick(float _DT)
{
	Super::tick(_DT);
}

void CBtnUI::render(HDC _dc)
{
	Vec2 vPos = GetFinalPos();
	Vec2 vScale = GetScale();

	Super::render(_dc);
}

void CBtnUI::begin()
{
	
}

void CBtnUI::OnHovered(Vec2 _vMousePos)
{
	m_Animator->Play(wHAnimName, true);
	m_SndEffectH->Play(false);
}

void CBtnUI::MouseOn(Vec2 _vMousePos)
{
}

void CBtnUI::OnUnHovered(Vec2 _vMousePos)
{
	m_Animator->Play(wNAnimName, true);
}


void CBtnUI::LBtnDown(Vec2 _vMousePos)
{
	m_Animator->Play(wPAnimName, true);
}

void CBtnUI::LBtnUp(Vec2 _vMousePos)
{
	m_Animator->Play(wHAnimName, true);
}


void CBtnUI::LBtnClicked(Vec2 _vMousePos)
{
	float curPosX = _vMousePos.x;
	float curPosY = _vMousePos.y;
	wstring buffer = L"";
	buffer += L"vPos x : " + std::to_wstring(curPosX) + L" y: " + std::to_wstring(curPosY);
	CLogMgr::GetInst()->AddLog(FLog{ LOG_LEVEL::ERR, buffer });
	//LOG(ERR, buffer);

	if (nullptr != m_CallBackFunc)
	{
		m_SndEffectC->Play(false);
		m_CallBackFunc();
	}
	

	if (nullptr != m_Inst && nullptr != m_Delegate)
	{
		(m_Inst->*m_Delegate)();
	}
}

