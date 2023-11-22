#include "pch.h"
#include "CRefreshPeg.h"

#include "CLevelMgr.h"

#include "CLevel.h"


CRefreshPeg::CRefreshPeg()
{
	SetName(L"RefreshPeg");
	m_Animator->LoadAnimation(L"animdata\\RefreshPeg.txt");
	m_Animator->Play(L"RefreshPeg", true);

	m_Collider->SetOffsetPos(Vec2(0.f, 0.f));
	m_Collider->SetScale(Vec2(24, 24));
	m_Collider->SetOffsetPos(Vec2(0.f, 0.f));
}

CRefreshPeg::~CRefreshPeg()
{
}

void CRefreshPeg::begin()
{
}

void CRefreshPeg::tick(float _DT)
{
	Super::tick(_DT);
}

void CRefreshPeg::render(HDC _dc)
{
	Super::render(_dc);
}

void CRefreshPeg::Reload()
{
}

void CRefreshPeg::BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol)
{
	CCamera::GetInst()->Shake(0.06f, 4);
	CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();
	vector <CPeg*> &allPegs = pCurLevel->GetPegs();
	for (int i = 0; i < pCurLevel->GetPegs().size(); ++i)
	{
		allPegs[i]->Refresh();

	}
	//allPegs.clear();

	//pCurLevel->LoadPegs(L"Board\\Board1.txt");

	//Super::BeginOverlap(_OwnCol, _OtherObj, _OtherCol);
}

void CRefreshPeg::Refresh()
{
	m_Collider->SetBOnOff(true);
}
