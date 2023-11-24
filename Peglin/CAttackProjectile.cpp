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

}

CAttackProjectile::~CAttackProjectile()
{
}

void CAttackProjectile::tick(float _DT)
{
	Super::tick(_DT);

	 //GetOwnerSM()->ChangeState((UINT)MONSTER_ATTACK);
}

void CAttackProjectile::begin()
{
	//m_Transform->MoveTo(), 2.f);
	// 
	//CGeneralLevel* pCurLevel = dynamic_cast<CGeneralLevel*>(CLevelMgr::GetInst()->GetCurLevel());
}

void CAttackProjectile::PlayAnimation(ORB_TYPE _type)
{
	ORB_TYPE orb_type = _type;
	switch (orb_type)
	{
	case PEBBALL:
	{
		m_Animator->Play(L"Pebball", true);
		break;
	}
	case DAGGORB:
	{
		m_Animator->Play(L"Daggorb", true);
		break;
	}
	case INFERNORB:
	{
		m_Animator->Play(L"Infernorb", true);
		break;
	}
	case SPHEAR:
	{
		m_Animator->Play(L"Sphear", true);
		break;
	}
	case RUBBORB:
	{
		m_Animator->Play(L"Rubborb", true);
		break;
	}
	default:
		LOG(LOGLOG, L"ภฬป๓วั Projectile");
		break;
	}
}

