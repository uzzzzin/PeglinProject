#include "pch.h"
#include "CShootingState.h"

#include "CLogMgr.h"

#include "COrb.h"

CShootingState::CShootingState()
{
}

CShootingState::~CShootingState()
{
}

void CShootingState::finaltick(float _DT)
{
	if (m_Orb->GetDBoundaryY() < m_Orb->curPos.y)
	{
		m_Orb->SetPos(REALCENTER);
		m_Orb->GetComponent<CMovement>()->SetVelocity({0,0});
		m_Orb->GetComponent<CMovement>()->UseGravity(false);
		//m_Orb->GetComponent<CMovement>()->SetVelocity(Vec2(m_Movement->GetVelocity().x, (m_Movement->GetVelocity().y) * -1));
		GetOwnerSM()->ChangeState((UINT)PEGLIN_ATTACK);
	}

}

void CShootingState::Enter()
{
	LOG(LOGLOG, L"현재 상태 : Shooting State");
	m_Orb = dynamic_cast<COrb*>(CLevelMgr::GetInst()->GetCurLevel()->FindObjectByName(L"Orb"));
}

void CShootingState::Exit()
{
}