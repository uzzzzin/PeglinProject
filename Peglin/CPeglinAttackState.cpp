#include "pch.h"
#include "CPeglinAttackState.h"

#include "CLevelMgr.h"
#include "CLevel.h"
#include "CEnemy.h"
#include "CPeglinPlayer.h"

#include "CGeneralLevel.h"
#include "CStage1Level.h"
#include "CLogMgr.h"

#include "COrb.h"
#include "CAttackProjectile.h"

CPeglinAttackState::CPeglinAttackState()
{
}

CPeglinAttackState::~CPeglinAttackState()
{
}

void CPeglinAttackState::finaltick(float _DT)
{
	int damage = dynamic_cast<CPeglinPlayer*>(GetOwnerSM()->GetOwner())->GetAttackDamage();

	 m_Target->DealDamage(damage);
	 if (0 >= m_Target->GetCurHP())
	 {
		 m_Target->Destroy();
		 LOG(ERR, L"몬스터는 사망할 예정");
	 }
	 //m_Projectile->GetComponent<CTransform>()->MoveTo(m_Target->GetPos(), 2.f);
	 
	 GetOwnerSM()->ChangeState((UINT)MONSTER_ATTACK);
}

void CPeglinAttackState::Enter()
{
	LOG(LOGLOG, L"현재 상태 : Peglin Attack State");
	m_curLevel = dynamic_cast<CGeneralLevel*>(CLevelMgr::GetInst()->GetCurLevel());

	 m_Target = m_curLevel->GetEnemyCheck()[0].first;

	 // m_Peglin->GetCurOrbType()].animName, true

	 UINT curOrb = (UINT)dynamic_cast<CPeglinPlayer*>(GetOwnerSM()->GetOwner())->GetCurOrbType();
	  //vector<OrbInfo>* vv = (vector<OrbInfo>*)GetOwnerSM()->GetDataFromBlackboard(L"orbs");
	 
	  //&vv[0].


	// m_Projectile = new CAttackProjectile;
	//// m_Projectile->GetComponent<CAnimator>()->Play( );
	// m_Projectile->GetComponent<CTransform>()->MoveTo(m_Target->GetPos(), 4.f);
	// //m_Projectile->GetComponent<CTransform>()->SetTargetPoint(m_Target->GetPos());
	//
}

void CPeglinAttackState::Exit()
{

	/*for (int i = 0; i < m_curLevel->GetEnemyCheck().size(); ++i)
	{
		if (m_curLevel->GetEnemyCheck()[0].first->IsDead())
		{
			LOG(ERR, L"몬스터 죽음");
		}
	}*/
	//for (int i = 0; i < m_curLevel->GetEnemyCheck().size(); ++i)
//{
//	if (m_curLevel->GetEnemyCheck()[i].first->IsDead())
//	{
//		LOG(ERR, L"몬스터 죽음");
//		m_curLevel->GetEnemyCheck().erase(m_curLevel->GetEnemyCheck().begin() + i);
//		--i;
//	}
//}
}

