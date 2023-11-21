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
	m_Projectile = new CAttackProjectile;
	m_Projectile->SetScale(Vec2(22, 22));
	
}

CPeglinAttackState::~CPeglinAttackState()
{
}

void CPeglinAttackState::finaltick(float _DT)
{
	int damage = dynamic_cast<CPeglinPlayer*>(GetOwnerSM()->GetOwner())->GetAttackDamage();

	
	 
	 m_Projectile->finaltick(_DT);
	 if (m_Projectile->GetPos() == m_Target->GetPos())
	 {
		 m_Target->DealDamage(damage);

		 if (0 >= m_Target->GetCurHP())
		 {
			 m_Target->SetEnemyDead(true);

			 vector<std::pair<class CEnemy*, int>>& vector1 = m_curLevel->GetEnemyCheck();
			 auto ii = vector1[0];
			 vector1.erase(vector1.begin());
			 delete ii.first;
			 GetOwnerSM()->ChangeState((UINT)MONSTER_ATTACK);

			 // LOG(ERR, L"몬스터는 사망할 예정");
		 }
		 GetOwnerSM()->ChangeState((UINT)MONSTER_ATTACK);
	 }

	 
}

void CPeglinAttackState::Enter()
{
	LOG(LOGLOG, L"현재 상태 : Peglin Attack State");
	m_curLevel = dynamic_cast<CGeneralLevel*>(CLevelMgr::GetInst()->GetCurLevel());
	 m_Target = m_curLevel->GetEnemyCheck()[0].first;
	 m_Projectile->SetPos(Vec2(GetOwnerSM()->GetOwner()->GetPos().x + 40.f , GetOwnerSM()->GetOwner()->GetPos().y+20.f));

	 m_Projectile->GetComponent<CTransform>()->MoveTo(m_Target->GetPos(), 0.4f);
	 // m_Peglin->GetCurOrbType()].animName, true

	 UINT curOrb = (UINT)dynamic_cast<CPeglinPlayer*>(GetOwnerSM()->GetOwner())->GetCurOrbType();
	  //vector<OrbInfo>* vv = (vector<OrbInfo>*)GetOwnerSM()->GetDataFromBlackboard(L"orbs");
	 
	  //&vv[0].



	//// m_Projectile->GetComponent<CAnimator>()->Play( );
	// m_Projectile->GetComponent<CTransform>()->MoveTo(m_Target->GetPos(), 4.f);
	//
}

void CPeglinAttackState::Exit()
{
	vector<std::pair<class CEnemy*, int>>& vector1 = m_curLevel->GetEnemyCheck();
	if (vector1.size() == 0)
	{
		GetOwnerSM()->ChangeState((UINT)STAGE_CLEAR);
	}

}

void CPeglinAttackState::render(HDC _dc)
{
	m_Projectile->render(_dc);
}

