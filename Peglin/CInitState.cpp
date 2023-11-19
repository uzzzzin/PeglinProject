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
	// 몬스터 한칸씩 땡겨주기

	for (int i = 0; i < EnemysInLevel.size(); ++i)
	{
		if (0 == i)
		{
			if (0 == EnemysInLevel[i].second)
			{

			}
			else // 맨 처음에 있는 애가 0번째 idx에 있지 않다면
			{
				--EnemysInLevel[i].second;
				EnemysInLevel[i].first->SetPos(Vec2(m_curLevel->EnemyXPos[i], EnemysInLevel[i].first->GetPos().y));
			}
		}
		else // 맨 처음에 있는 에너미가 아닌 경우
		{
			if (EnemysInLevel[i - 1].second == ((EnemysInLevel[i].second) - 1)) // 내 바로 앞에 있는 적의 idx가 내가 앞으로 갈 idx와 같다면
			{
				// 아무것도 안 해야 함
			}
			else
			{
				--EnemysInLevel[i].second;
				EnemysInLevel[i].first->SetPos(Vec2(m_curLevel->EnemyXPos[i], EnemysInLevel[i].first->GetPos().y));
			}

		}
	}

		// 구슬 큐
		if (0 == turn)
		{
			//NoneState = true;
 			GetOwnerSM()->ChangeState((UINT)BEFORE_SHOOT);
			return;
		}
		else
		{
			if (380.f >= m_Queue->OrbCases[m_Queue->OrbCases.size() - 1]->GetPos().y) // 구슬 큐 리로드
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
	LOG(WARNING, L"현재 상태 : Init_State");

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

