#include "pch.h"
#include "CCritPeg.h"


#include "CAssetMgr.h"
#include "CLevelMgr.h"
#include "CLevel.h"

#include "components.h"


CCritPeg::CCritPeg()
{
	SetName(L"CritPeg");
	m_Animator->LoadAnimation(L"animdata\\CritPeg.txt");

	m_Collider->SetOffsetPos(Vec2(0.f, 0.f));
	m_Collider->SetScale(Vec2(24, 24));
	m_Collider->SetOffsetPos(Vec2(0.f, 0.f));
	
}

CCritPeg::~CCritPeg()
{
}

void CCritPeg::begin()
{
	m_Animator->Play(L"CritPeg", true);
}

void CCritPeg::tick(float _DT)
{
	Super::tick(_DT);

}

void CCritPeg::render(HDC _dc)
{
	Super::render(_dc);
}

void CCritPeg::Reload()
{
}

void CCritPeg::Refresh()
{
}

void CCritPeg::BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol)
{

	CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();
	vector <CPeg*> allPegs = pCurLevel->GetPegs();

	for (int i = 0; i < pCurLevel->GetPegs().size(); ++i)
	{		
		allPegs[i]->CritModeOn();
	}
	CCamera::GetInst()->Shake(0.06f, 4);
	Super::BeginOverlap(_OwnCol, _OtherObj, _OtherCol);
}

