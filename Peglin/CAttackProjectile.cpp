#include "pch.h"
#include "CAttackProjectile.h"

#include "CLevelMgr.h"

#include "COrb.h"
#include "components.h"
#include "CGeneralLevel.h"

CAttackProjectile::CAttackProjectile()
	:m_Transform(nullptr)
	, m_Animator(nullptr)
	, m_Collider(nullptr)
{
	m_Transform = AddComponent<CTransform>(L"Transform");
	m_Animator = AddComponent<CAnimator>(L"Animator");

	m_Animator->LoadAnimation(L"animdata\\Pebball.txt");
	m_Animator->LoadAnimation(L"animdata\\Daggorb.txt");
	m_Animator->LoadAnimation(L"animdata\\Infernorb.txt");
	m_Animator->LoadAnimation(L"animdata\\Sphear.txt");
	m_Animator->LoadAnimation(L"animdata\\Rubborb.txt");
	m_Animator->LoadAnimation(L"animdata\\EnemyStoneProjectile.txt");

	m_Animator->Play(L"Infernorb", true);
}

CAttackProjectile::~CAttackProjectile()
{
}

void CAttackProjectile::tick(float _DT)
{
	Super::tick(_DT);

	 //GetOwnerSM()->ChangeState((UINT)MONSTER_ATTACK);
}

void CAttackProjectile::finaltick(float _DT)
{
	Super::finaltick(_DT);
}

void CAttackProjectile::begin()
{
	//m_Transform->MoveTo(), 2.f);
	// 
	//CGeneralLevel* pCurLevel = dynamic_cast<CGeneralLevel*>(CLevelMgr::GetInst()->GetCurLevel());
}

