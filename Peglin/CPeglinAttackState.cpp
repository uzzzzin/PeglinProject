#include "pch.h"
#include "CPeglinAttackState.h"

#include "CEnemy.h"
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
}

void CPeglinAttackState::Enter()
{
	LOG(LOGLOG, L"현재 상태 : Peglin Attack State");
	//m_Target = dynamic_cast<CEnemy*>(CLevelMgr::GetInst()->GetCurLevel()->);
}

void CPeglinAttackState::Exit()
{
}

//CEnemy* CPeglinAttackState::FindTarget()
//{
//	CGeneralLevel* pCurLevel = dynamic_cast<CGeneralLevel*>(CLevelMgr::GetInst()->GetCurLevel());
//	vector<std::pair<class CEnemy*, int>> Targets = pCurLevel->GetEnemyCheck();
//
//	int tmpMinIdx = Targets[0].second;
//
//	for (int i = 0; i < Targets.size(); ++i)
//	{
//		/*if (0 == Targets[i].second)
//		{
//			return Targets[i].first;
//		}
//
//		if (tmpMinIdx > Targets[i].second)
//		{
//			tmpMinIdx = i;
//		}
//
//		if (i == Targets.size() - 1)
//			return tmpMinIdx */
//	}
//}
