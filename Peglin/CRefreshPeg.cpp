#include "pch.h"
#include "CRefreshPeg.h"


CRefreshPeg::CRefreshPeg()
{
	SetiDieCnt(1);
	SetiCurCnt(0);
	SetbDied(false);

	m_Animator->LoadAnimation(L"animdata\\RefreshPeg.txt");
	m_Animator->Play(L"RefreshPeg", true);
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