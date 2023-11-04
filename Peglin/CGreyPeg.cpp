#include "pch.h"
#include "CGreyPeg.h"

#include "CAssetMgr.h"
#include "CKeyMgr.h"
#include "components.h"



//CGreyPeg::CGreyPeg(const CGreyPeg& _Origin)
//{
//}

CGreyPeg::CGreyPeg()
{
	SetiDieCnt(1);
	SetiCurCnt(0);
	SetbDied(false);

	m_Animator->LoadAnimation(L"animdata\\firstGreyPeg.txt");
	m_Animator->Play(L"firstGreyPeg", true);
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

	if (KEY_TAP(KEY::P))
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