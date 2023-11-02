#include "pch.h"
#include "CBtnUI.h"

#include "CEngine.h"
#include "resource.h"
#include "CKeyMgr.h"
#include "CAssetMgr.h"

#include "CTexture.h"

CBtnUI::CBtnUI()
	: m_CallBackFunc(nullptr)
	, m_Animator(nullptr)
	, m_Inst(nullptr)
	, m_Delegate(nullptr)
	, wNAnimName(L"")
	, wHAnimName(L"")
	, wPAnimName(L"")

{
	m_Animator = AddComponent<CAnimator>();
}

CBtnUI::CBtnUI(const wstring& _strName, const wstring& _strKey, const wstring& _strRelativePath)
{
}

CBtnUI::~CBtnUI()
{
}

void CBtnUI::SetNormalImg(const wstring& _strKey, const wstring& _strRelativePath, const wstring& _strName, const wstring& _strRelativePath2, const wstring& _animName)
{
	
	m_Animator->LoadAnimation(_strRelativePath2);
	wNAnimName = _animName;
	m_Animator->Play(wNAnimName, true);
}

void CBtnUI::SetPressedImg(const wstring& _strKey, const wstring& _strRelativePath, const wstring& _strName, const wstring& _strRelativePath2, const wstring& _animName)
{
	m_Animator->LoadAnimation(_strRelativePath2);
	wPAnimName = _animName;

}

void CBtnUI::SetHoverImg(const wstring& _strKey, const wstring& _strRelativePath, const wstring& _strName, const wstring& _strRelativePath2, const wstring& _animName)
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
	if (nullptr != m_CallBackFunc)
	{
		m_CallBackFunc();
	}

	if (nullptr != m_Inst && nullptr != m_Delegate)
	{
		(m_Inst->*m_Delegate)();
	}
}
