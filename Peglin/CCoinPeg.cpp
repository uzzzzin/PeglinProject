#include "pch.h"
#include "CCoinPeg.h"


#include "CAssetMgr.h"
#include "CKeyMgr.h"
#include "CSound.h"

#include "components.h"


CCoinPeg::CCoinPeg()
	:bSlimed(false)
	, m_SE(nullptr)
	, m_SE2(nullptr)
{
	SetName(L"CoinPeg");
	m_Animator->LoadAnimation(L"animdata\\CoinPeg.txt");
	m_Animator->LoadAnimation(L"animdata\\SlimedCoinPeg.txt");
	m_Animator->LoadAnimation(L"animdata\\CritCoinPeg.txt");

	m_Collider->SetOffsetPos(Vec2(0.f, 0.f));
	m_Collider->SetScale(Vec2(24, 24));
	m_Collider->SetOffsetPos(Vec2(0.f, 0.f));

	m_SE = CAssetMgr::GetInst()->LoadSound(L"CoinPegColSE", L"sound\\CoinPegColSE.wav");
	m_SE2 = CAssetMgr::GetInst()->LoadSound(L"CoinPegColSE2", L"sound\\CoinPegColSE2.wav");

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

void CCoinPeg::BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol)
{
	Super::BeginOverlap(_OwnCol, _OtherObj, _OtherCol);

	if (!(m_Collider->GetBOnOff()))
	{
		return;
	}

	if (bColSnd == true)
	{
		m_SE->Play(false);
		bColSnd = false;
	}
	else
	{
		m_SE2->Play(false);
		bColSnd = true;
	}
}
