#include "pch.h"
#include "CCoinPeg.h"


#include "CAssetMgr.h"
#include "CKeyMgr.h"

#include "components.h"


CCoinPeg::CCoinPeg()
	:bSlimed(false)
{
	SetiDieCnt(1);
	SetiCurCnt(0);
	SetbDied(false);

	m_Animator->LoadAnimation(L"animdata\\CoinPeg.txt");
	m_Animator->LoadAnimation(L"animdata\\SlimedCoinPeg.txt");

	m_Collider->SetOffsetPos(Vec2(0.f, 0.f));
	m_Collider->SetScale(Vec2(24, 24));
	m_Collider->SetOffsetPos(Vec2(0.f, 0.f));
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
	if (bSlimed)
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
