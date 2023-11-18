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

	 if (0 <= m_Target->GetCurHP())
	 {
		 m_Target->IsDead();
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

	 m_Target = m_curLevel->GetEnemyCheck()[0].first;
}

void CPeglinAttackState::Exit()
{
}

