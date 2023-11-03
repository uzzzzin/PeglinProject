#include "pch.h"
#include "CGreyPeg.h"

#include "CAssetMgr.h"
#include "CKeyMgr.h"


#include "components.h"

CGreyPeg::CGreyPeg()
	: iDieCnt(1)
	, iCurCnt(0)
	, bDied(false)
	, m_Collider(nullptr)
	,m_Animator(nullptr)
{
	m_Animator = AddComponent<CAnimator>(L"Animator");
	m_Collider = AddComponent<CCollider>(L"Collider");

	m_Animator->LoadAnimation(L"animdata\\firstGreyPeg.txt");

	m_Animator->Play(L"firstGreyPeg", true);
}


//CGreyPeg::CGreyPeg(const CGreyPeg& _Origin)
//{
//}

CGreyPeg::~CGreyPeg()
{
}

void CGreyPeg::begin()
{
	
}

void CGreyPeg::tick(float _DT)
{
	Super::tick(_DT);

	if (KEY_TAP(KEY::NUM9))
	{
		m_Animator->LoadAnimation(L"animdata\\GreyPeg.txt");
		m_Animator->Play(L"GreyPeg", true);
	}

}

void CGreyPeg::render(HDC _dc)
{
	Super::render(_dc);
}

void CGreyPeg::Reload()
{
}