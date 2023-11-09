#include "pch.h"
#include "CPeg.h"

#include "CColliderWall.h"

CPeg::CPeg()
: iDieCnt(1)
, iCurCnt(0)
,  bDied(false)
, m_Animator(nullptr)
, m_Collider(nullptr)
{
	m_Animator = AddComponent<CAnimator>(L"PegAnimator");
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

//void CPeg::BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol)
//{
//	SetPos(GetPos());
//}


