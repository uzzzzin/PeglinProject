#include "pch.h"
#include "CNormalMonIdle.h"



CNormalMonIdle::CNormalMonIdle()
{
}

CNormalMonIdle::~CNormalMonIdle()
{
}

void CNormalMonIdle::finaltick(float _DT)
{
	if (nullptr == m_pTarget)
		return;

	// �÷��̾ Ž������ ���� �ִ��� Ȯ��
	// 1. �����忡 ����Ǿ��ִ� Ž�������� �����´�/
	float* pDetectRange = (float*)GetOwnerSM()->GetDataFromBlackboard(L"Detect Range");
	float DetectRange = *pDetectRange;

	// 2. �÷��̾�� ���Ͱ��� �Ÿ��� üũ
	Vec2 vPlayerPos = m_pTarget->GetPos();
	CMonster* pMonster = dynamic_cast<CMonster*>(GetOwnerSM()->GetOwner());
	if (nullptr == pMonster)
		return;

	Vec2 vMonsterPos = pMonster->GetPos();

	float fDist = vPlayerPos.Distance(vMonsterPos);

	if (fDist < DetectRange)
	{
		GetOwnerSM()->ChangeState((UINT)ENORMAL_MON_STATE::NORMAL_MON_TRACE);
	}
}

void CNormalMonIdle::Enter()
{
	//CAnimator* pAnimator = GetOwnerSM()->GetOwner()->GetComponent<CAnimator>();
	//pAnimator->Play(L"")

	// ������ �ִ� �÷��̾ �˾Ƴ���.
	m_pTarget = dynamic_cast<CPlayer*>(CLevelMgr::GetInst()->GetCurLevel()->FindObjectByName(L"Player"));
}

void CNormalMonIdle::Exit()
{
}


