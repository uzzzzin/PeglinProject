#include "pch.h"
#include "CMonsterAttackState.h"

#include "CEnemy.h"
#include "CPeglinPlayer.h"
#include "CGeneralLevel.h"

CMonsterAttackState::CMonsterAttackState()
{
}

CMonsterAttackState::~CMonsterAttackState()
{
}

void CMonsterAttackState::finaltick(float _DT)
{

	if (m_curLevel->EnemyXPos[0] == m_AttackEnemy->GetPos().x) // 몬스터의 공격 사거리에 페글린이 들어옴
	{
		int damage = m_AttackEnemy->GetDamage();
		m_Peglin->ReduceHP(damage);

		if (0 >= m_Peglin->GetHP())
		{
			GetOwnerSM()->ChangeState((UINT)PEGLIN_DIE);
		}
		else
		{
			GetOwnerSM()->ChangeState((UINT)STATE_INIT);
		}
	}
	else
	{
		GetOwnerSM()->ChangeState((UINT)STATE_INIT);
	}


	
}

void CMonsterAttackState::Enter()
{
	LOG(LOGLOG, L"현재 상태 : Monster Attack State");
	m_Peglin = dynamic_cast<CPeglinPlayer*>(GetOwnerSM()->GetOwner());
	m_curLevel = dynamic_cast<CGeneralLevel*>(CLevelMgr::GetInst()->GetCurLevel());
	if (0 == m_curLevel->GetEnemyCheck().size())
	{
		GetOwnerSM()->ChangeState((UINT)STAGE_CLEAR);
		return;
	}
	else
	{
		m_AttackEnemy = m_curLevel->GetEnemyCheck()[0].first;
	}
	
}

void CMonsterAttackState::Exit()
{
}
