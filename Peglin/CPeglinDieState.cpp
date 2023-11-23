#include "pch.h"
#include "CPeglinDieState.h"

#include "CLogMgr.h"
#include "CGeneralLevel.h"
#include "CPeglinPlayer.h"


void CPeglinDieState::finaltick(float _DT)
{

}

void CPeglinDieState::Enter()
{
	LOG(LOGLOG, L"���� ���� : Peglin Die State");

	m_curLevel = dynamic_cast<CGeneralLevel*>(CLevelMgr::GetInst()->GetCurLevel());
	m_Peglin = dynamic_cast<CPeglinPlayer*>(GetOwnerSM()->GetOwner());

	m_Peglin->GetComponent<CAnimator>()->LoadAnimation(L"animdata\\PeglinDie.txt");
	m_Peglin->GetComponent<CAnimator>()->Play(L"PeglinDie",false);
	CCamera::GetInst()->FadeOut(1.f);

}

void CPeglinDieState::Exit()
{
	m_curLevel->ResetTurn();
}
