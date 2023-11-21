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
	if (KEY_TAP(LBTN))
	{
		GetOwnerSM()->ChangeState((UINT)SHOOTING);
	}
}

void CBeforeShootState::Enter()
{
	LOG(WARNING, L"���� ���� : BeforeShoot_State");
	//m_Peglin = dynamic_cast<CPeglinPlayer*>(GetOwnerSM()->GetOwner());
	//m_Orb = dynamic_cast<COrb*>(CLevelMgr::GetInst()->GetCurLevel()->FindObjectByName(L"Orb"));
}

void CBeforeShootState::Exit()
{
}
