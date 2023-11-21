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
	SetName(L"GreyPeg");
	m_Animator->LoadAnimation(L"animdata\\firstGreyPeg.txt");
	m_Animator->LoadAnimation(L"animdata\\GreyPeg.txt");
	m_Animator->LoadAnimation(L"animdata\\SlimedGreyPeg.txt");
	m_Animator->LoadAnimation(L"animdata\\CritGreyPeg.txt");

	m_Collider->SetOffsetPos(Vec2(0.f, 0.f));
	m_Collider->SetScale(Vec2(24,24));
	m_Collider->SetOffsetPos(Vec2(0.f, 0.f));

	m_Animator->Play(L"firstGreyPeg", true);

}

CGreyPeg::~CGreyPeg()
{
}

void CGreyPeg::begin()
{
	m_Animator->Play(L"firstGreyPeg", true);
}

void CGreyPeg::tick(float _DT)
{
	if (!m_Collider->GetBOnOff())
	{
		Super::tick(_DT);
		return;
	}
	if (GetCritMode())
	{
		m_Animator->Play(L"CritGreyPeg", true);
	}
	else
	{
		m_Animator->Play(L"firstGreyPeg", true);
	}
	Super::tick(_DT);
}

void CGreyPeg::render(HDC _dc)
{
	Super::render(_dc);
}

void CGreyPeg::Reload()
{
}

void CGreyPeg::Refresh()
{
	m_Collider->SetBOnOff(true);
	bCrashed = false;
	iDieCnt = 0;
}

//void CGreyPeg::BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol)
//{
//	Super::BeginOverlap(_OwnCol, _OtherObj, _OtherCol);
//
//	
//}

