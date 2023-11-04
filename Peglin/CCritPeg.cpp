#include "pch.h"
#include "CCritPeg.h"

#include "CAssetMgr.h"
#include "components.h"

CCritPeg::CCritPeg()
{
	SetiDieCnt(1);
	SetiCurCnt(0);
	SetbDied(false);

	m_Animator->LoadAnimation(L"animdata\\CritPeg.txt");
	
}

CCritPeg::~CCritPeg()
{
}

void CCritPeg::begin()
{
}

void CCritPeg::tick(float _DT)
{
	Super::tick(_DT);
	m_Animator->Play(L"CritPeg", true);
}

void CCritPeg::render(HDC _dc)
{
	Super::render(_dc);
}

void CCritPeg::Reload()
{
}

