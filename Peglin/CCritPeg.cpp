#include "pch.h"
#include "CCritPeg.h"


#include "CAssetMgr.h"
#include "CSound.h"
#include "CLevelMgr.h"
#include "CLevel.h"

#include "components.h"


CCritPeg::CCritPeg()
	: m_SE(nullptr)
{
	SetName(L"CritPeg");
	m_Animator->LoadAnimation(L"animdata\\CritPeg.txt");

	m_Collider->SetOffsetPos(Vec2(0.f, 0.f));
	m_Collider->SetScale(Vec2(24, 24));
	m_Collider->SetOffsetPos(Vec2(0.f, 0.f));
	
	m_SE = CAssetMgr::GetInst()->LoadSound(L"CritPegColSE", L"sound\\CritPegColSE.wav");
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
	if(!bCrashed)
		m_Animator->Play(L"CritPeg", true);

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
	m_Collider->SetBOnOff(true);
	bCrashed = false;
	iDieCnt = 0;
}

void CCritPeg::BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol)
{
	Super::BeginOverlap(_OwnCol, _OtherObj, _OtherCol);

	if (!(m_Collider->GetBOnOff()))
	{
		return;
	}


	m_SE->Play(false);
	CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();
	vector <CPeg*> allPegs = pCurLevel->GetPegs();

	for (int i = 0; i < pCurLevel->GetPegs().size(); ++i)
	{		
		allPegs[i]->CritModeOn();
		m_Collider->GetBOnOff();
	}
	CCamera::GetInst()->Shake(0.06f, 4);

}

