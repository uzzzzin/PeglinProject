#include "pch.h"
#include "CInitState.h"

#include "CLogMgr.h"
#include "CGeneralLevel.h"
#include "CEnemy.h"
#include "CPeglinPlayer.h"
#include "CPeg.h"

#include "COrb.h"
#include "COrbQueue.h"
#include "COrbQueueHeadOrb.h"
#include "COrbQueueBody.h"
#include "COrbQueueHead.h"
#include "COrbQueueChain.h"
#include "COrbQueueBodyOrbCase.h"
#include "CImg.h"

CInitState::CInitState()
{
}

CInitState::~CInitState()
{
}


void CInitState::Enter()
{
	LOG(WARNING, L"���� ���� : Init_State");

	m_curLevel = dynamic_cast<CGeneralLevel*>(CLevelMgr::GetInst()->GetCurLevel());
	m_Peglin = dynamic_cast<CPeglinPlayer*>(m_curLevel->FindObjectByName(L"PeglinPlayer")); // GetOwnerSM()->GetOwner()
	m_Queue = dynamic_cast<COrbQueue*>(m_curLevel->FindObjectByName(L"OrbQueue"));
	m_HeadOrb = dynamic_cast<COrbQueueHeadOrb*>(m_Queue->QueueHeadOrb);
	m_Orb = dynamic_cast<COrb*>(m_curLevel->FindObjectByName(L"Orb"));

	vector <CPeg*> allPegs = m_curLevel->GetPegs();
	vector<std::pair<class CEnemy*, int>>& EnemysInLevel = m_curLevel->GetEnemyCheck();
	for (int i = 0; i < m_curLevel->GetPegs().size(); ++i)
	{
		allPegs[i]->CritModeOff();
	}

	if (0 == m_curLevel->GetCurTurn() && !bRealInit)
	{
		m_Orb->SetCurTurnOrb(m_Peglin->GetOrbs()[0]);
		bRealInit = true;
		return;
	}

	// ���� �� �� �̻� ������ ��
	m_curLevel->CurTurnPP();
	m_Peglin->AddMyOrbsIdx();
	m_Orb->SetCurTurnOrb(m_Peglin->GetOrbs()[m_curLevel->GetCurTurn() % m_Peglin->GetOrbs().size()]);
	m_HeadOrb->OrbAnimPlay(m_Peglin->GetCurOrbType());

	// ���� ��ĭ�� �����ֱ�
	for (int i = 0; i < EnemysInLevel.size(); ++i) // vector<std::pair<class CEnemy*, int>> EnemysInLevel = m_curLevel->GetEnemyCheck();
	{
		if (0 == i) // �� ó�� ���ʹ� ���⼭ ����
		{
			if (0 == EnemysInLevel[i].second)
			{
				int a = 0;
			}
			else // �� ó���� �ִ� �ְ� 0��° idx�� ���� �ʴٸ�
			{
				--EnemysInLevel[i].second;
				//EnemysInLevel[i].first->SetPos(Vec2(m_curLevel->EnemyXPos[i], EnemysInLevel[i].first->GetPos().y));
				EnemysInLevel[i].first->GetComponent<CTransform>()->MoveTo(Vec2(m_curLevel->EnemyXPos[EnemysInLevel[i].second], EnemysInLevel[i].first->GetPos().y), 0.9f);
			}
		}

		else // �� ó���� �ִ� ���ʹ̰� �ƴ� ���
		{
			if (EnemysInLevel[i - 1].second == ((EnemysInLevel[i].second) - 1)) // �� �ٷ� �տ� �ִ� ���� idx�� ���� ������ �� idx�� ���ٸ�
			{
				// �ƹ��͵� �� �ؾ� ��
				int a = 0;
			}
			else
			{
				--EnemysInLevel[i].second;
				//EnemysInLevel[i].first->SetPos(Vec2(m_curLevel->EnemyXPos[i], EnemysInLevel[i].first->GetPos().y));
				EnemysInLevel[i].first->GetComponent<CTransform>()->MoveTo(Vec2(m_curLevel->EnemyXPos[EnemysInLevel[i].second], EnemysInLevel[i].first->GetPos().y), 0.9f);
			}

		}
	}
}


void CInitState::Exit()
{
	GetOwnerSM()->AddDataToBlackboard(L"orbs", m_Orb->GetOrbsInfo());
	GetOwnerSM()->AddDataToBlackboard(L"Pebball Range", &m_Orb->GetOrbsInfo()[0].attackCnt);
	GetOwnerSM()->AddDataToBlackboard(L"Daggorb Range", &m_Orb->GetOrbsInfo()[1].attackCnt);
	GetOwnerSM()->AddDataToBlackboard(L"Infernorb Range", &m_Orb->GetOrbsInfo()[2].attackCnt);
	GetOwnerSM()->AddDataToBlackboard(L"Sphear Range", &m_Orb->GetOrbsInfo()[3].attackCnt);
	GetOwnerSM()->AddDataToBlackboard(L"Rubborb Range", &m_Orb->GetOrbsInfo()[4].attackCnt);
}



void CInitState::finaltick(float _DT)
{
	int turn = m_curLevel->GetCurTurn();

	for (int i = 0; i < m_curLevel->GetEnemyCheck().size(); ++i)
	{
		m_curLevel->GetEnemyCheck()[i].first->finaltick(_DT);
	}


	if (0 == turn)
	{
		//NoneState = true;
		GetOwnerSM()->ChangeState((UINT)BEFORE_SHOOT);
		return;
	}


		// ���� ť
		if (0 == turn)
		{
 			GetOwnerSM()->ChangeState((UINT)BEFORE_SHOOT);
			return;
		}
		else
		{
			if ( 0 == m_Peglin->GetMyOrbIdx()) // ���� ����
			{
				for (int i = 0; i < m_Queue->nextOrbs.size() - 1; ++i)
				{
					float SetPosY = 425.f + 45 * i;        //425.f - 45 * i;
					m_Queue->OrbChains[i]->SetPos(Vec2(444.5f, SetPosY));
					m_Queue->OrbCases[i]->SetPos(Vec2(444.5f, SetPosY));
					m_Queue->OrbImgs[i]->SetPos(Vec2(444.5f, SetPosY));
				}
			}
			else
			{
				for (int i = 0; i < m_Queue->nextOrbs.size() - 1; ++i)
				{
					float SetPosY = m_Queue->OrbChains[i]->GetPos().y - 45;

						if (i < m_Peglin->GetMyOrbIdx() )
						{
							m_Queue->OrbChains[i]->SetPos(Vec2(444.5f, SetPosY + 5000.f));
							m_Queue->OrbCases[i]->SetPos(Vec2(444.5f, SetPosY + 5000.f));
							m_Queue->OrbImgs[i]->SetPos(Vec2(444.5f, SetPosY + 5000.f));
						}
						else
						{
							m_Queue->OrbChains[i]->SetPos(Vec2(444.5f, SetPosY));
							m_Queue->OrbCases[i]->SetPos(Vec2(444.5f, SetPosY));
							m_Queue->OrbImgs[i]->SetPos(Vec2(444.5f, SetPosY));
						}

				}

			}
			GetOwnerSM()->ChangeState((UINT)BEFORE_SHOOT);
		}
}

