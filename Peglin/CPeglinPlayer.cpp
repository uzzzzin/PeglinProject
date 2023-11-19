#include "pch.h"
#include "CPeglinPlayer.h"

#include "CMonsterAttackState.h"

#include "CKeyMgr.h"

#include "components.h"

#include "CInitState.h"
#include "CBeforeShootState.h"
#include "CShootingState.h"
#include "CPeglinAttackState.h"
#include "CMonsterAttackState.h"
#include "CPeglinDieState.h"
#include "CGeneralLevel.h"



CPeglinPlayer::CPeglinPlayer()
	: m_Animator(nullptr)
	, m_Collider(nullptr)
	, m_AI(nullptr)
	, Coin(0)
	, HP(100)
	, AttackDamage(0)
	, myOrbsIdx(0)
	//, m_Movement(nullptr)
{
	SetName(L"PeglinPlayer");

	m_Animator = AddComponent<CAnimator>(L"Animator");
	m_Collider = AddComponent<CCollider>(L"Collider");
	m_AI = AddComponent<CStateMachine>(L"AI");
	
	m_AI->AddState((UINT)STATE_INIT, new CInitState);
	m_AI->AddState((UINT)BEFORE_SHOOT, new CBeforeShootState);
	m_AI->AddState((UINT)SHOOTING, new CShootingState);
	m_AI->AddState((UINT)PEGLIN_ATTACK, new CPeglinAttackState);
	m_AI->AddState((UINT)MONSTER_ATTACK, new CMonsterAttackState);
	m_AI->AddState((UINT)PEGLIN_DIE, new CPeglinDieState);
	
	//m_Movement = AddComponent<CMovement>(L"Movement");

	m_Animator->LoadAnimation(L"animdata\\PeglinIdle.txt");
	m_Animator->Play(L"PeglinIdle", true);

	m_Collider->SetScale(Vec2(76.f,90.f));

	myOrbs.push_back(PEBBALL);
	myOrbs.push_back(DAGGORB);
	myOrbs.push_back(INFERNORB);
	myOrbs.push_back(SPHEAR);
	myOrbs.push_back(RUBBORB);

 	//m_AI->ChangeState(UINT(STATE_INIT));
}

CPeglinPlayer::~CPeglinPlayer()
{
}

void CPeglinPlayer::AddMyOrbsIdx()
{
}

ORB_TYPE CPeglinPlayer::GetCurOrbType()
{
	CGeneralLevel* pCurLevel = dynamic_cast<CGeneralLevel*>(CLevelMgr::GetInst()->GetCurLevel());
	 int turn = pCurLevel->GetCurTurn();

	 myOrbsIdx = turn % myOrbs.size();
	 return myOrbs[myOrbsIdx];
}

ORB_TYPE CPeglinPlayer::GetNextOrbType()
{
	CGeneralLevel* pCurLevel = dynamic_cast<CGeneralLevel*>(CLevelMgr::GetInst()->GetCurLevel());
	int turn = pCurLevel->GetCurTurn();

	myOrbsIdx = turn % myOrbs.size();

	if ((myOrbsIdx + 1) >= myOrbs.size())
	{
		return myOrbs[1];
	}
	return myOrbs[myOrbsIdx + 1];
}

void CPeglinPlayer::begin()
{
	m_AI->ChangeState(UINT(STATE_INIT));
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
