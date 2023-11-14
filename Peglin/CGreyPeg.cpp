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

	m_Collider->SetOffsetPos(Vec2(0.f, 0.f));
	m_Collider->SetScale(Vec2(24,24));
	m_Collider->SetOffsetPos(Vec2(0.f, 0.f));

}

CGreyPeg::~CGreyPeg()
{
}

void CGreyPeg::begin()
{
}

void CGreyPeg::tick(float _DT)
{
	m_Animator->Play(L"firstGreyPeg", true);
	Super::tick(_DT);
}

void CGreyPeg::render(HDC _dc)
{
	Super::render(_dc);
}

void CGreyPeg::Reload()
{
}