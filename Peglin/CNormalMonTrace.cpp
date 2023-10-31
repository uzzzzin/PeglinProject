#include "pch.h"
#include "CNormalMonTrace.h"

CNormalMonTrace::CNormalMonTrace()
{
}

CNormalMonTrace::~CNormalMonTrace()
{
}

void CNormalMonTrace::finaltick(float _DT)
{
	// �÷��̾��� ��ġ�� �˾Ƴ���.
	Vec2 vPlayerPos = m_pTarget->GetPos();

	// ���� ������ ��ġ�� �˾Ƴ���.
	CMonster* pMonster = dynamic_cast<CMonster*>(GetOwnerSM()->GetOwner());
	if (nullptr == pMonster)
		return;
	Vec2 vMonsterPos = pMonster->GetPos();


	// �÷��̾ Ž�������� ����� Idle ���·� ���ư���.
	// 1. �����忡�� ������ Ž�������� �����´�.
	float* pDetectRange = (float*)GetOwnerSM()->GetDataFromBlackboard(L"Detect Range");
	float DetectRange = *pDetectRange;

	// 2. �÷��̾�� ������ �Ÿ��� ���Ѵ�.
	float fDist = vPlayerPos.Distance(vMonsterPos);

	// 3. �÷��̾�� ������ �Ÿ��� Ž������ �̻��̸� Idle ���·� �����Ѵ�.
	if (DetectRange < fDist)
	{
		GetOwnerSM()->ChangeState((UINT)ENORMAL_MON_STATE::NORMAL_MON_IDLE);
		return;
	}


	// �÷��̾ ���ݹ��� �̳��� ������ Attack ���·� �����Ѵ�.
	{


	}


	// �÷��̾ �����Ѵ�.
	// 1. ���Ͱ� �̵��� ������ �˾Ƴ���. (�÷��̾���ġ - ���� ��ġ)
	Vec2 vDir = vPlayerPos - vMonsterPos;
	vDir.Normalize();

	// 2. ����(����) �� �̵��ӵ��� �˾Ƴ���.
	float* pSpeed = (float*)GetOwnerSM()->GetDataFromBlackboard(L"Speed");
	float fSpeed = *pSpeed;

	// 3. �÷��̾ ���ؼ� �̵��Ѵ�.
	vMonsterPos += vDir * fSpeed * _DT;
	pMonster->SetPos(vMonsterPos);
}

void CNormalMonTrace::Enter()
{
	// ������ �ִ� �÷��̾ �˾Ƴ���.
	m_pTarget = dynamic_cast<CPlayer*>(CLevelMgr::GetInst()->GetCurLevel()->FindObjectByName(L"Player"));

	// Animator �� Move Animation ���
}

void CNormalMonTrace::Exit()
{
}


