#include "pch.h"
#include "CShootingState.h"

#include "CLogMgr.h"

#include "COrb.h"
#include "CPeglinPlayer.h"


CShootingState::CShootingState()
	: info{}
{

}

CShootingState::~CShootingState()
{

}

void CShootingState::finaltick(float _DT)
{

	//if (0 != m_Orb->GetHitOrbsCnt().size())
	//{
	//	if (prevDamage != pPeglin->GetAttackDamage() || (prevDamage == 0 && pPeglin->GetAttackDamage() == 0))
	//	{
	//		for (int i = 0; i < m_Orb->GetHitOrbsCnt().size(); ++i)
	//		{
	//			pPeglin->AddAttackDamage((info[i].damage) * (m_Orb->GetHitOrbsCnt()[i].second));
	//			// ���� ������ +  ������ ���� �Ϲ� ������ *  ��� ���� ���� 
	//			m_Orb->SetAccDamage(pPeglin->GetAttackDamage());

	//		}
	//	}
	//}


	if (m_Orb->GetDBoundaryY() < m_Orb->curPos.y)
	{
		m_Orb->SetPos(REALCENTER);
		m_Orb->GetComponent<CMovement>()->SetVelocity({0,0});
		m_Orb->GetComponent<CMovement>()->UseGravity(false);
		//m_Orb->GetComponent<CMovement>()->SetVelocity(Vec2(m_Movement->GetVelocity().x, (m_Movement->GetVelocity().y) * -1));
		GetOwnerSM()->ChangeState((UINT)PEGLIN_ATTACK);

	}
	prevDamage = m_Orb->GetAccDamage();
}

void CShootingState::Enter()
{
	LOG(LOGLOG, L"���� ���� : Shooting State");
	pPeglin = dynamic_cast<CPeglinPlayer*>(GetOwnerSM()->GetOwner());
	m_Orb = dynamic_cast<COrb*>(CLevelMgr::GetInst()->GetCurLevel()->FindObjectByName(L"Orb"));
	info =  m_Orb->GetOrbsInfo();
	prevDamage = 0;
}

void CShootingState::Exit()
{
	// ������� �浹�� ��� -> ������ ��ġ ���
	//int damage = 0;
	pPeglin->SetAttackDamage(m_Orb->GetAccDamage());
	m_Orb->SetAccDamage(0);
	for (int i = 0; i < m_Orb->GetHitOrbsCnt().size(); ++i)
	{
		//pPeglin->AddAttackDamage((info[i].damage)* (m_Orb->GetHitOrbsCnt()[i].second));
		m_Orb->GetHitOrbsCnt()[i].second = 0;
		 // ���� ������ +  ������ ���� �Ϲ� ������ *  ��� ���� ���� 
	}

}

void CShootingState::render(HDC _dc)
{
	m_Orb->render(_dc);
}