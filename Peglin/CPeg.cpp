#include "pch.h"
#include "CPeg.h"

#include "CColliderWall.h"

CPeg::CPeg()
: iDieCnt(1)
, iCurCnt(0)
, bCrashed(false)
, bCritMode(false)
, m_Animator(nullptr)
, m_Collider(nullptr)
{
	m_Animator = AddComponent<CAnimator>(L"PegAnimator");
	m_Animator->LoadAnimation(L"animdata\\CrashedPeg.txt");	
	m_Collider = AddComponent<CColliderCircle>(L"PegCollider");
}

//CPeg::CPeg(const CPeg& _Origin)
//{
//}

CPeg::~CPeg()
{
}

void CPeg::begin()
{
}

void CPeg::tick(float _DT)
{
	CObj::tick(_DT);
}

void CPeg::BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol)
{
	if (!(m_Collider->GetBOnOff()))
	{
		return;
	}
	if (_OtherObj->GetLayerIdx() == ORB)
	{
		++iCurCnt;
		if (0 >=iDieCnt- iCurCnt)
		{
			bCrashed = true;
			// 죽어있는 척 할거면 페그 사라질 때의 애니메이션 처리를 해줘야 함.
			m_Animator->Play(L"CrashedPeg",false);
			//m_Collider->SetBOnOff(false);
		}
	}
}

