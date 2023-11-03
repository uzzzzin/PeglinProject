#include "pch.h"
#include "CCoinPeg.h"

CCoinPeg::CCoinPeg()
	: iDieCnt(1)
	, iCurCnt(0)
	, bDied(false)
	,m_Collider(nullptr)
	, m_Animator(nullptr)
{
	m_Animator = AddComponent<CAnimator>(L"Animator");
	m_Collider = AddComponent<CCollider>(L"Collider");
}

CCoinPeg::~CCoinPeg()
{
}




void CCoinPeg::begin()
{
}

void CCoinPeg::tick(float _DT)
{
}

void CCoinPeg::render(HDC _dc)
{
}

void CCoinPeg::Reload()
{
}
