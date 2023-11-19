#include "pch.h"
#include "CInitState.h"

#include "CLogMgr.h"
#include "CGeneralLevel.h"
#include "CEnemy.h"
#include "CPeglinPlayer.h"

#include "COrb.h"
#include "COrbQueue.h"
#include "COrbQueueBody.h"
#include "COrbQueueHead.h"
#include "COrbQueueChain.h"
#include "COrbQueueBodyOrbCase.h"
#include "CImg.h"

CInitState::CInitState()
	: NoneState(false)
{
}

CInitState::~CInitState()
{
}


void CInitState::finaltick(float _DT)
{
	int turn = m_curLevel->GetCurTurn();

	if (0 == turn)
	{
		//NoneState = true;
		GetOwnerSM()->ChangeState((UINT)BEFORE_SHOOT);
		return;
	}
	// ���� ��ĭ�� �����ֱ�

	for (int i = 0; i < EnemysInLevel.size(); ++i)
	{
		if (0 == i)
		{
			if (0 == EnemysInLevel[i].second)
			{

			}
			else // �� ó���� �ִ� �ְ� 0��° idx�� ���� �ʴٸ�
			{
				--EnemysInLevel[i].second;
				EnemysInLevel[i].first->SetPos(Vec2(m_curLevel->EnemyXPos[i], EnemysInLevel[i].first->GetPos().y));
			}
		}
		else // �� ó���� �ִ� ���ʹ̰� �ƴ� ���
		{
			if (EnemysInLevel[i - 1].second == ((EnemysInLevel[i].second) - 1)) // �� �ٷ� �տ� �ִ� ���� idx�� ���� ������ �� idx�� ���ٸ�
			{
				// �ƹ��͵� �� �ؾ� ��
			}
			else
			{
				--EnemysInLevel[i].second;
				EnemysInLevel[i].first->SetPos(Vec2(m_curLevel->EnemyXPos[i], EnemysInLevel[i].first->GetPos().y));
			}

		}
	}

		// ���� ť
		if (0 == turn)
		{
			//NoneState = true;
 			GetOwnerSM()->ChangeState((UINT)BEFORE_SHOOT);
			return;
		}
		else
		{
			if (380.f >= m_Queue->OrbCases[m_Queue->OrbCases.size() - 1]->GetPos().y) // ���� ť ���ε�
			{
				for (int i = 0; i < m_Queue->nextOrbs.size() - 1; ++i)
				{
					float SetPosY = 425.f + 45 * (i + 1);        //425.f - 45 * i;
					m_Queue->OrbChains[i]->SetPos(Vec2(444.5f, SetPosY));
					m_Queue->OrbCases[i]->SetPos(Vec2(444.5f, SetPosY));
					m_Queue->OrbImgs[i]->SetPos(Vec2(444.5f, SetPosY));
				}
				//GetOwnerSM()->ChangeState((UINT)BEFORE_SHOOT);
			}
			else
			{
				for (int i = 0; i < m_Queue->nextOrbs.size() - 1; ++i)
				{
					float SetPosY = m_Queue->OrbChains[i]->GetPos().y - 45;         //425.f - 45 * i;
					m_Queue->OrbChains[i]->SetPos(Vec2(444.5f, SetPosY));
					m_Queue->OrbCases[i]->SetPos(Vec2(444.5f, SetPosY));
					m_Queue->OrbImgs[i]->SetPos(Vec2(444.5f, SetPosY));
				}
				//GetOwnerSM()->ChangeState((UINT)BEFORE_SHOOT);
			}
			//m_Orb->SetCurTurnOrb(ORB_TYPE(m_Queue->nextOrbs[turn% m_Queue->nextOrbs.size()]));
			m_Orb->SetCurTurnOrb(m_Peglin->GetNextOrbType());
			GetOwnerSM()->ChangeState((UINT)BEFORE_SHOOT);
		}
		// here !!!!!!!!!!!!!!!!
	
}

void CInitState::Enter()
{
	LOG(WARNING, L"���� ���� : Init_State");

	m_curLevel = dynamic_cast<CGeneralLevel*>(CLevelMgr::GetInst()->GetCurLevel());
	m_Peglin = dynamic_cast<CPeglinPlayer*>(m_curLevel->FindObjectByName(L"PeglinPlayer"));
	EnemysInLevel = m_curLevel->GetEnemyCheck();
	m_Queue = dynamic_cast<COrbQueue*>(m_curLevel->FindObjectByName(L"OrbQueue"));
	m_Orb = dynamic_cast<COrb*>(m_curLevel->FindObjectByName(L"Orb"));
}

void CInitState::Exit()
{
	m_curLevel->CurTurnPP();
	m_Peglin->AddMyOrbsIdx();
}

