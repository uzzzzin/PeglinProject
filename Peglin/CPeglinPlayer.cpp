#include "pch.h"
#include "CPeglinPlayer.h"

#include "CKeyMgr.h"

CPeglinPlayer::CPeglinPlayer()
	: m_Animator(nullptr)
	, m_Collider(nullptr)
	, myOrbsIdx(0)
	//, m_Movement(nullptr)
{
	SetName(L"PeglinPlayer");

	m_Animator = AddComponent<CAnimator>(L"Animator");
	m_Collider = AddComponent<CCollider>(L"Collider");
	//m_Movement = AddComponent<CMovement>(L"Movement");

	m_Animator->LoadAnimation(L"animdata\\PeglinIdle.txt");
	m_Animator->Play(L"PeglinIdle", true);

	m_Collider->SetScale(Vec2(76.f,90.f));

	myOrbs.push_back(PEBBALL);
	myOrbs.push_back(DAGGORB);
	myOrbs.push_back(INFERNORB);
	myOrbs.push_back(SPHEAR);
	myOrbs.push_back(RUBBORB);
}

CPeglinPlayer::~CPeglinPlayer()
{
}

void CPeglinPlayer::tick(float _DT)
{
	Super::tick(_DT);
	if (KEY_TAP(F))
	{
		++myOrbsIdx;
		if (myOrbsIdx == myOrbs.size())
		{
			myOrbsIdx = 0;
		}
		
	}
}
