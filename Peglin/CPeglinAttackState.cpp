#include "pch.h"
#include "CPeglinAttackState.h"

#include "CEnemy.h"
#include "CPeglinPlayer.h"
#include "CStage1Level.h"
#include "CLogMgr.h"

CPeglinAttackState::CPeglinAttackState()
{
}

CPeglinAttackState::~CPeglinAttackState()
{
}

void CPeglinAttackState::finaltick(float _DT)
{
	 int damage = m_Peglin->GetAttackDamage();

	 m_Target->DealDamage(damage);
	 if (0 >= m_Target->GetCurHP())
	 {
		 m_Target->Destroy();
		 LOG(ERR, L"²ó");
		 //m_curLevel->GetEnemyCheck().erase(m_curLevel->GetEnemyCheck().begin());
	 }
	 //LOG(ERR, L"²ó");
	 GetOwnerSM()->ChangeState((UINT)MONSTER_ATTACK);
}

void CPeglinAttackState::Enter()
{
	LOG(LOGLOG, L"ÇöÀç »óÅÂ : Peglin Attack State");

	m_Peglin = dynamic_cast<CPeglinPlayer*>(CLevelMgr::GetInst()->GetCurLevel()->FindObjectByName(L"PeglinPlayer"));

	m_curLevel = dynamic_cast<CGeneralLevel*>(CLevelMgr::GetInst()->GetCurLevel());

	//for (int i = 0; i < m_curLevel->GetEnemyCheck().size(); ++i)
	//{
	//	if (m_curLevel->GetEnemyCheck()[i].first->IsDead())
	//	{
	//		LOG(ERR, L"¸ó½ºÅÍ Á×À½");
	//		m_curLevel->GetEnemyCheck().erase(m_curLevel->GetEnemyCheck().begin() + i);
	//		--i;
	//	}
	//}

	 m_Target = m_curLevel->GetEnemyCheck()[0].first;

}

void CPeglinAttackState::Exit()
{
	/*for (int i = 0; i < m_curLevel->GetEnemyCheck().size(); ++i)
	{
		if (m_curLevel->GetEnemyCheck()[0].first->IsDead())
		{
			LOG(ERR, L"¸ó½ºÅÍ Á×À½");
		}
	}*/
}

