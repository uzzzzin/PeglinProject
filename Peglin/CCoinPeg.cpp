#include "pch.h"
#include "CCoinPeg.h"


#include "CAssetMgr.h"


#include "components.h"


CCoinPeg::CCoinPeg()
{
	SetiDieCnt(1);
	SetiCurCnt(0);
	SetbDied(false);

	m_Animator->LoadAnimation(L"animdata\\CoinPeg.txt");
}

CCoinPeg::~CCoinPeg()
{
}

void CCoinPeg::begin()
{
}

void CCoinPeg::tick(float _DT)
{
	Super::tick(_DT);
	m_Animator->Play(L"CoinPeg", true);
}

void CCoinPeg::render(HDC _dc)
{
	Super::render(_dc);
}

void CCoinPeg::Reload()
{
}
