#include "pch.h"
#include "CShootingState.h"

#include "CLogMgr.h"

#include "COrb.h"
#include "CPeglinPlayer.h"

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
		return;
	}

}

void CShootingState::Enter()
{
	LOG(LOGLOG, L"���� ���� : Shooting State");
	m_Orb = dynamic_cast<COrb*>(CLevelMgr::GetInst()->GetCurLevel()->FindObjectByName(L"Orb"));
}

void CShootingState::Exit()
{
	CPeglinPlayer* pPeglin = dynamic_cast<CPeglinPlayer*>(GetOwnerSM()->GetOwner());
	// ������� �浹�� ��� -> ������ ��ġ ���
	//int damage = 0;

	vector<OrbInfo >&info = m_Orb->GetOrbsInfo();
	for (int i = 0; i < m_Orb->GetHitOrbsCnt().size(); ++i)
	{
		pPeglin->AddAttackDamage((info[i].damage)* (m_Orb->GetHitOrbsCnt()[i].second));
		m_Orb->GetHitOrbsCnt()[i].second = 0;
		 // ���� ������ +  ������ ���� �Ϲ� ������ *  ��� ���� ���� 
	}


}