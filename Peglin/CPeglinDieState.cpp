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
	LOG(LOGLOG, L"현재 상태 : Peglin Die State");

	m_curLevel = dynamic_cast<CGeneralLevel*>(CLevelMgr::GetInst()->GetCurLevel());
	m_Peglin = dynamic_cast<CPeglinPlayer*>(m_curLevel->FindObjectByName(L"PeglinPlayer"));

	m_Peglin->GetComponent<CAnimator>()->LoadAnimation(L"animdata\\PeglinDie.txt");
	m_Peglin->GetComponent<CAnimator>()->Play(L"PeglinDie",false);
}

void CPeglinDieState::Exit()
{
}
