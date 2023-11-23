#include "pch.h"
#include "CPeglinDieState.h"

#include "CBtnUI.h"

#include "CLogMgr.h"
#include "CGeneralLevel.h"
#include "CPeglinPlayer.h"


void CPeglinDieState::finaltick(float _DT)
{
	m_AccTime_Die += _DT;
	m_AccTime_Last += _DT;

	if (m_Duration_Die <= m_AccTime_Die)
	{
		m_Peglin->GetComponent<CAnimator>()->Play(L"PeglinAngel", true);
		m_AccTime_Die = 0; // 2초 지나면 플레이

		if (m_Duration_Last >= m_AccTime_Last)
		{
			//int a = 0;
	
		}
		else
		{
			GetOwnerSM()->ChangeState((UINT)START_LEVEL_ENTER);
		}
	}

}

void CPeglinDieState::Enter()
{
	LOG(LOGLOG, L"현재 상태 : Peglin Die State");

	m_Duration_Die = 2.f;
	m_AccTime_Die = 0;

	m_Duration_Last = 3.f;

	m_AccTime_Last = 0;


	m_curLevel = dynamic_cast<CGeneralLevel*>(CLevelMgr::GetInst()->GetCurLevel());
	m_Peglin = dynamic_cast<CPeglinPlayer*>(GetOwnerSM()->GetOwner());


	m_Peglin->GetComponent<CAnimator>()->LoadAnimation(L"animdata\\PeglinDie.txt");
	m_Peglin->GetComponent<CAnimator>()->LoadAnimation(L"animdata\\PeglinAngel.txt");
	m_Peglin->GetComponent<CAnimator>()->Play(L"PeglinDie",false);

	CCamera::GetInst()->Shake(1.f, 20);
	CCamera::GetInst()->FadeOut(m_Duration_Last);


}

void CPeglinDieState::Exit()
{
	m_curLevel->ResetTurn();

}

CPeglinDieState::CPeglinDieState()
{
}

CPeglinDieState::~CPeglinDieState()
{
}

