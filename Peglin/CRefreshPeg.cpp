#include "pch.h"
#include "CRefreshPeg.h"


CRefreshPeg::CRefreshPeg()
{
	SetiDieCnt(1);
	SetiCurCnt(0);
	SetbDied(false);

	m_Animator->LoadAnimation(L"animdata\\RefreshPeg.txt");
	m_Animator->Play(L"RefreshPeg", true);

	m_Collider->SetOffsetPos(Vec2(0.f, 0.f));
	m_Collider->SetScale(Vec2(24, 24));
	m_Collider->SetOffsetPos(Vec2(0.f, 0.f));
}

CRefreshPeg::~CRefreshPeg()
{
}

void CRefreshPeg::begin()
{
}

void CRefreshPeg::tick(float _DT)
{
	Super::tick(_DT);
}

void CRefreshPeg::render(HDC _dc)
{
	Super::render(_dc);
}

void CRefreshPeg::Reload()
{
}