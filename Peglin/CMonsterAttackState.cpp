#include "pch.h"
#include "CMonsterAttackState.h"

#include "CAssetMgr.h"
#include "CTexture.h"
#include "CSound.h"
#include "CEnemy.h"
#include "CPeglinPlayer.h"
#include "CGeneralLevel.h"
#include "CPeglinDamaged.h"

CMonsterAttackState::CMonsterAttackState()
	: m_PeglinDamageUI(nullptr)
{
	m_PeglinDamageUI = new CPeglinDamaged;
	m_PeglinDamageUI->SetPos(Vec2(435.f, 160.f));
	m_PeglinDamageUI->SetScale(Vec2(15, 15));

	m_PeglinDamageUI->SetInitPos(m_PeglinDamageUI->GetPos());

}

CMonsterAttackState::~CMonsterAttackState()
{
	delete m_PeglinDamageUI;
}

void CMonsterAttackState::finaltick(float _DT)
{
	
	if (m_curLevel->EnemyXPos[0] == m_AttackEnemy->GetPos().x) // 몬스터의 공격 사거리에 페글린이 들어옴
	{
		m_AccTime += _DT;
		m_PeglinDamageUI->alphaCntMM();
		m_PeglinDamageUI->SetPos((Vec2(m_PeglinDamageUI->GetPos().x, m_PeglinDamageUI->GetPos().y - 40.f * _DT)));//GetComponent<CTransform>()->MoveTo(Vec2(m_PeglinDamageUI->GetPos().x, m_PeglinDamageUI->GetPos().y - 10.f), 0);
		if (m_Duration <= m_AccTime)
		{
			m_PeglinDamageUI->finaltick(_DT);
			int damage = m_AttackEnemy->GetDamage();
			m_Peglin->ReduceHP(damage);
			CCamera::GetInst()->Shake(0.7f, 10);
			m_Peglin->GetAttackedSound()->Play(false);

			if (0 >= m_Peglin->GetHP())
			{
				GetOwnerSM()->ChangeState((UINT)PEGLIN_DIE);
			}
			else
			{
				GetOwnerSM()->ChangeState((UINT)STATE_INIT);
			}
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
		m_PeglinDamageUI->SetDamageNum(m_AttackEnemy->GetDamage());
	}
	m_Duration = 1.f;
	m_AccTime = 0;
	
}

void CMonsterAttackState::render(HDC _dc)
{
	if (m_curLevel->EnemyXPos[0] == m_AttackEnemy->GetPos().x)
	{
		m_PeglinDamageUI->render(_dc);
	}
}



void CMonsterAttackState::Exit()
{

	m_PeglinDamageUI->alphaCntReset();
	m_PeglinDamageUI->SetPos(m_PeglinDamageUI->GetInitPos());
}

