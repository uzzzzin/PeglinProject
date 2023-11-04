#include "pch.h"
#include "CCoinPeg.h"


#include "CAssetMgr.h"
#include "CKeyMgr.h"

#include "components.h"


CCoinPeg::CCoinPeg()
	:bSlimed(true)
{
	SetiDieCnt(1);
	SetiCurCnt(0);
	SetbDied(false);

	m_Animator->LoadAnimation(L"animdata\\CoinPeg.txt");
	m_Animator->LoadAnimation(L"animdata\\SlimedCoinPeg.txt");
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
	if (bSlimed && KEY_PRESSED(S))
	{
		m_Animator->Play(L"SlimedCoinPeg", true);
	}
	else
	{
		m_Animator->Play(L"CoinPeg", true);
	}
}

void CCoinPeg::render(HDC _dc)
{
	Super::render(_dc);
}

void CCoinPeg::Reload()
{
}
