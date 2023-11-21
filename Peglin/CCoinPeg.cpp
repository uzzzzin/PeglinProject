#include "pch.h"
#include "CCoinPeg.h"


#include "CAssetMgr.h"
#include "CKeyMgr.h"

#include "components.h"


CCoinPeg::CCoinPeg()
	:bSlimed(false)
{
	SetName(L"CoinPeg");
	m_Animator->LoadAnimation(L"animdata\\CoinPeg.txt");
	m_Animator->LoadAnimation(L"animdata\\SlimedCoinPeg.txt");
	m_Animator->LoadAnimation(L"animdata\\CritCoinPeg.txt");

	m_Collider->SetOffsetPos(Vec2(0.f, 0.f));
	m_Collider->SetScale(Vec2(24, 24));
	m_Collider->SetOffsetPos(Vec2(0.f, 0.f));
}

CCoinPeg::~CCoinPeg()
{
}

void CCoinPeg::begin()
{
	if (bSlimed)
	{
		m_Animator->Play(L"SlimedCoinPeg", true);
	}
	else
	{
		m_Animator->Play(L"CoinPeg", true);
	}
}

void CCoinPeg::tick(float _DT)
{
	if (!m_Collider->GetBOnOff())
	{
		Super::tick(_DT);
		return;
	}
	if (GetCritMode())
	{
		m_Animator->Play(L"CritCoinPeg", true);
	}
	else
	{
		m_Animator->Play(L"CoinPeg", true);
	}
	Super::tick(_DT);

}

void CCoinPeg::render(HDC _dc)
{
	Super::render(_dc);
}

void CCoinPeg::Reload()
{
}

void CCoinPeg::Refresh()
{
	m_Collider->SetBOnOff(true);
	bCrashed = false;
	iDieCnt = 0;
}
