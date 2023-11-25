#include "pch.h"
#include "CPeglinAttackState.h"

#include "CLevelMgr.h"
#include "CLevel.h"
#include "CEnemy.h"
#include "CPeglinPlayer.h"

#include "CSound.h"
#include "CAssetMgr.h"

#include "CGeneralLevel.h"
#include "CStage1Level.h"
#include "CLogMgr.h"

#include "COrb.h"
#include "CAttackProjectile.h"

CPeglinAttackState::CPeglinAttackState()
	: damage(0)
{
	m_Projectile = new CAttackProjectile;
	m_Projectile->SetScale(Vec2(26, 26));
	
}

CPeglinAttackState::~CPeglinAttackState()
{
	delete m_Projectile;
}

void CPeglinAttackState::finaltick(float _DT)
{
	 m_Projectile->finaltick(_DT);

		// m_Target = m_curLevel->GetEnemyCheck()[i].first;

		 if (m_Projectile->GetPos() == m_Target->GetPos())
		 {
			 CEnemy* curTarget = m_curLevel->GetEnemyCheck()[0].first;

			 for(int i = 0; i < attackRange; ++i)
			 {
				 curTarget = m_curLevel->GetEnemyCheck()[i].first;
				 curTarget->DealDamage(damage);

				 if (0 >= curTarget->GetCurHP())
				 {
					 CCamera::GetInst()->Shake(0.27f, 19);
				 }
				 else
				 {
					 CCamera::GetInst()->Shake(0.15f, 6);
				 }

				 if (0 >= curTarget->GetCurHP())
				 {
					 curTarget->SetEnemyDead(true);

					 vector<std::pair<class CEnemy*, int>>& vector1 = m_curLevel->GetEnemyCheck();
					 auto ii = vector1[0];
					 vector1.erase(vector1.begin());
					 delete ii.first;

					 if (vector1.size() == 0)
					 {
						 GetOwnerSM()->ChangeState((UINT)STAGE_CLEAR);
					 }
				 }
			 }

				 GetOwnerSM()->ChangeState((UINT)MONSTER_ATTACK);
		 }


	 
}

void CPeglinAttackState::Enter()
{
	LOG(LOGLOG, L"현재 상태 : Peglin Attack State");
	m_curLevel = dynamic_cast<CGeneralLevel*>(CLevelMgr::GetInst()->GetCurLevel());
	m_Orb =  dynamic_cast<COrb*>(m_curLevel->FindObjectByName(L"Orb"));
	UINT curOrb = (UINT)dynamic_cast<CPeglinPlayer*>(GetOwnerSM()->GetOwner())->GetCurOrbType();
	attackRange = m_Orb->GetOrbsInfo()[curOrb].attackCnt;
	m_Target = m_curLevel->GetEnemyCheck()[attackRange-1].first;
	 m_Projectile->SetPos(Vec2(GetOwnerSM()->GetOwner()->GetPos().x + 40.f , GetOwnerSM()->GetOwner()->GetPos().y+20.f));
	 m_Peglin = dynamic_cast<CPeglinPlayer*>(GetOwnerSM()->GetOwner());
	 m_Projectile->GetComponent<CTransform>()->MoveTo(m_Target->GetPos(), 0.3f);
	 damage = m_Peglin->GetAttackDamage();

	 m_Projectile->PlayAnimation((ORB_TYPE)curOrb);

}

void CPeglinAttackState::Exit()
{
	m_Peglin->SetAttackDamage(0);
	m_Peglin->GetProjSound()->Play(false);

	vector<std::pair<class CEnemy*, int>>& vector1 = m_curLevel->GetEnemyCheck();
	
}

void CPeglinAttackState::render(HDC _dc)
{
	m_Projectile->render(_dc);
}

