#include "pch.h"
#include "CPeg.h"

CPeg::CPeg()
: iDieCnt(1)
, iCurCnt(0)
,  bDied(false)
, m_Collider(nullptr)
, m_Animator(nullptr)
{
	m_Animator = AddComponent<CAnimator>(L"Animator");
	m_Collider = AddComponent<CCollider>(L"Collider");
}

//CPeg::CPeg(const CPeg& _Origin)
//{
//}

CPeg::~CPeg()
{
}

