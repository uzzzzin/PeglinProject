#include "pch.h"
#include "CShootingState.h"

#include "CLogMgr.h"
#include "CKeyMgr.h"

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
	m_Orb->alphaCntMM();

	if (m_Orb->GetDBoundaryY() < m_Orb->curPos.y)
	{
		m_Orb->SetPos(REALCENTER);
		m_Orb->GetComponent<CMovement>()->SetVelocity({0,0});
		m_Orb->GetComponent<CMovement>()->UseGravity(false);
		GetOwnerSM()->ChangeState((UINT)PEGLIN_ATTACK);
	}
		prevDamage = m_Orb->GetAccDamage();
}

void CShootingState::Enter()
{
	LOG(LOGLOG, L"현재 상태 : Shooting State");
	pPeglin = dynamic_cast<CPeglinPlayer*>(GetOwnerSM()->GetOwner());
	m_Orb = dynamic_cast<COrb*>(CLevelMgr::GetInst()->GetCurLevel()->FindObjectByName(L"Orb"));
	info =  m_Orb->GetOrbsInfo();
	prevDamage = 0;
}

void CShootingState::Exit()
{
	// 오브들이 충돌한 페그 -> 데미지 수치 계산
	pPeglin->SetAttackDamage(m_Orb->GetAccDamage());


	if (KEY_PRESSED(I))
	{
		pPeglin->SetAttackDamage(3000);
	}

	m_Orb->SetAccDamage(0);
	m_Orb->SetAccCritDamage(0);
	m_Orb->SetCritMode(false);

	for (int i = 0; i < m_Orb->GetHitOrbsCnt().size(); ++i)
	{
		//pPeglin->AddAttackDamage((info[i].damage)* (m_Orb->GetHitOrbsCnt()[i].second));
		m_Orb->GetHitOrbsCnt()[i].second = 0;
		 // 현재 데미지 +  오브의 고유 일반 데미지 *  페그 맞은 개수 
	}

}

void CShootingState::render(HDC _dc)
{
	m_Orb->render(_dc);

}