#include "pch.h"
#include "CStartLogo.h"
#include "CKeyMgr.h"
#include "CAssetMgr.h"
#include "CTexture.h"
#include "components.h"



CStartLogo::CStartLogo()
	: m_Texture(nullptr)
	, m_Animator(nullptr)
{
	CTexture* pAtlas = CAssetMgr::GetInst()->LoadTexture(L"StartLogoAtlas", L"texture\\StartLogo.png");

	m_Animator = AddComponent<CAnimator>(L"StartLogoAnim");
	m_Animator->LoadAnimation(L"animdata\\StartLogo.txt");
	m_Animator->Play(L"StartLogo", true);
}

CStartLogo::~CStartLogo()
{
}

void CStartLogo::begin()
{
}

void CStartLogo::tick(float _DT)
{
	Super::tick(_DT);
}

void CStartLogo::render(HDC _dc)
{
	Super::render(_dc);
}

