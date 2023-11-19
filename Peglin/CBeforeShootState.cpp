#include "pch.h"
#include "CBeforeShootState.h"
#include "COrb.h"
#include "CPeglinPlayer.h"

#include "CKeyMgr.h"

CBeforeShootState::CBeforeShootState()
{
}

CBeforeShootState::~CBeforeShootState()
{
}

void CBeforeShootState::finaltick(float _DT)
{
	if (KEY_TAP(SPACE))
	{
		GetOwnerSM()->ChangeState((UINT)SHOOTING);
	}
}

void CBeforeShootState::Enter()
{
	LOG(WARNING, L"현재 상태 : BeforeShoot_State");
	m_Peglin = dynamic_cast<CPeglinPlayer*>(CLevelMgr::GetInst()->GetCurLevel()->FindObjectByName(L"PeglinPlayer"));
	m_Orb = dynamic_cast<COrb*>(CLevelMgr::GetInst()->GetCurLevel()->FindObjectByName(L"Orb"));
}

void CBeforeShootState::Exit()
{
}
