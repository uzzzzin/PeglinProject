#include "pch.h"
#include "CCritPeg.h"

#include "CAssetMgr.h"
#include "components.h"

CCritPeg::CCritPeg()
{

	m_Animator->LoadAnimation(L"animdata\\CritPeg.txt");

	m_Collider->SetOffsetPos(Vec2(0.f, 0.f));
	m_Collider->SetScale(Vec2(24, 24));
	m_Collider->SetOffsetPos(Vec2(0.f, 0.f));
	
}

CCritPeg::~CCritPeg()
{
}

void CCritPeg::begin()
{
}

void CCritPeg::tick(float _DT)
{
	Super::tick(_DT);
	m_Animator->Play(L"CritPeg", true);
}

void CCritPeg::render(HDC _dc)
{
	Super::render(_dc);
}

void CCritPeg::Reload()
{
}

