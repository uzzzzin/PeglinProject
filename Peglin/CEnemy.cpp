#include "pch.h"
#include "CEnemy.h"

#include "components.h"

CEnemy::CEnemy()
	: EnemyInitInfo{}
	, m_Animator(nullptr)
	, m_Movement(nullptr)
	, m_AI(nullptr)
{
	EnemyInfo BlueSlime = {BLUE_SLIME, L"BlueSlime", 80, 3, L"animdata\\BlueSlimeIdle.txt", L"BlueSlimeIdle",  L"animdata\\BlueSlimeDie.txt", L"BlueSlimeDie",  L"animdata\\BlueSlimeIdle.txt", L"BlueSlimeIdle" };

	Enemys.push_back(BlueSlime);

	m_Animator = AddComponent<CAnimator>(L"EnemyAnimator");
	m_Movement = AddComponent<CMovement>(L"EnemyMovement");
	m_AI = AddComponent<CStateMachine>(L"EnemyAI");


	SetEnemyInfo(BLUE_SLIME);

	m_Movement->SetMaxSpeed(400.f);
	m_Movement->SetFrictionScale(1000.f);
	m_Movement->UseGravity(false);
	m_Movement->SetGravity(Vec2(0.f, 980.f));
	m_Movement->SetGround(true);

}

CEnemy::~CEnemy()
{
}

void CEnemy::SetEnemyInfo(ENEMY_TYPE _type)
{
	/*if ( !_type)
	{
		LOG(ERR, "몬스터 정보가 이상한데?");
		return;
	}*/

	type = _type;
	UINT a = (UINT)_type;

	curHP = Enemys[a].hp;
	fullHP = Enemys[a].hp;
	damage = Enemys[a].damage;

	m_Animator->LoadAnimation(Enemys[a].idleAnimPath);
	m_Animator->Play(Enemys[a].idleAnimName,true);
}

//void CEnemy::tick(float _DT)
//{
//	Super::tick(_DT);
//}
