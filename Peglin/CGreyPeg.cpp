#include "pch.h"
#include "CGreyPeg.h"

#include "CAssetMgr.h"
#include "CKeyMgr.h"
#include "components.h"



//CGreyPeg::CGreyPeg(const CGreyPeg& _Origin)
//{
//}

CGreyPeg::CGreyPeg()
	:bSlimed(true)
{
	SetiDieCnt(1);
	SetiCurCnt(0);
	SetbDied(false);

	m_Animator->LoadAnimation(L"animdata\\firstGreyPeg.txt");
	m_Animator->LoadAnimation(L"animdata\\GreyPeg.txt");
	m_Animator->LoadAnimation(L"animdata\\SlimedGreyPeg.txt");

}

CGreyPeg::~CGreyPeg()
{
}

void CGreyPeg::begin()
{
}

void CGreyPeg::tick(float _DT)
{
	Super::tick(_DT);

	if (bSlimed && KEY_PRESSED(S))
	{
		m_Animator->Play(L"SlimedGreyPeg", true);
	}
	else
	{
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