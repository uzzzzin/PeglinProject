#include "pch.h"
#include "CInitState.h"

#include "CLogMgr.h"

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
	if (false == NoneState)
	{
		NoneState = true;
		GetOwnerSM()->ChangeState((UINT)BEFORE_SHOOT);
		return;
	}

	if (380.f >= m_Queue->OrbCases[m_Queue->OrbCases.size() - 1]->GetPos().y) // 구슬 큐 리로드
	{
		for (int i = 0; i < m_Queue->nextOrbs.size() - 1; ++i)
		{
			float SetPosY = 425.f + 45 * (i + 1);        //425.f - 45 * i;
			m_Queue->OrbChains[i]->SetPos(Vec2(444.5f, SetPosY));
			m_Queue->OrbCases[i]->SetPos(Vec2(444.5f, SetPosY));
			m_Queue->OrbImgs[i]->SetPos(Vec2(444.5f, SetPosY));
		}
		GetOwnerSM()->ChangeState((UINT)BEFORE_SHOOT);
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
		GetOwnerSM()->ChangeState((UINT)BEFORE_SHOOT);
	}
	

	
}

void CInitState::Enter()
{
	LOG(WARNING, L"현재 상태 : Init_State");
	m_Queue = dynamic_cast<COrbQueue*>(CLevelMgr::GetInst()->GetCurLevel()->FindObjectByName(L"OrbQueue"));
}

void CInitState::Exit()
{
}

