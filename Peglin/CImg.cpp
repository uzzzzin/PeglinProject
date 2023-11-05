#include "pch.h"
#include "CImg.h"

#include "CTexture.h"
#include "CAssetMgr.h"
#include "components.h"

CImg::CImg()
	: m_Animator(nullptr)
{
	m_Animator = AddComponent<CAnimator>(L"Animator");
}

CImg::~CImg()
{
}

void CImg::SetImg(const wstring& _strRelativePath, const wstring& _animName)
{
	m_Animator->LoadAnimation(_strRelativePath);
	m_AnimName = _animName;
	m_Animator->Play(m_AnimName, true);
}

void CImg::tick(float _DT)
{
	Super::tick(_DT);
}

void CImg::render(HDC _dc)
{
	Super::render(_dc);
}
