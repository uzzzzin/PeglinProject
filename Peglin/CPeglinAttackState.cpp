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
	 LOG(LOGLOG, L"뀨");
}

void CPeglinAttackState::Enter()
{
	LOG(LOGLOG, L"현재 상태 : Peglin Attack State");

	m_Peglin = dynamic_cast<CPeglinPlayer*>(CLevelMgr::GetInst()->GetCurLevel()->FindObjectByName(L"PeglinPlayer"));

	m_curLevel = dynamic_cast<CGeneralLevel*>(CLevelMgr::GetInst()->GetCurLevel());

	 m_Target = m_curLevel->GetEnemyCheck()[0].first;
}

void CPeglinAttackState::Exit()
{
}

