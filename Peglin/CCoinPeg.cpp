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
	m_Animator->Play(L"CoinPeg", true);
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
}

void CCoinPeg::render(HDC _dc)
{
	Super::render(_dc);
}

void CCoinPeg::Reload()
{
}
