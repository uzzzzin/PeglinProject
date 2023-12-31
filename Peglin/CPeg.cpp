#include "pch.h"
#include "CPeg.h"

#include "CAssetMgr.h"
#include "CSound.h"

#include "CColliderWall.h"
#include "COrb.h"

CPeg::CPeg()
: iDieCnt(1)
, iCurCnt(0)
, bCrashed(false)
, bCritMode(false)
, m_Animator(nullptr)

, m_Collider(nullptr)
{
	m_Animator = AddComponent<CAnimator>(L"PegAnimator");
	m_Animator->LoadAnimation(L"animdata\\CrashedPeg.txt");	
	m_Collider = AddComponent<CColliderCircle>(L"PegCollider");


}

//CPeg::CPeg(const CPeg& _Origin)
//{
//}

CPeg::~CPeg()
{
}

void CPeg::begin()
{
}

void CPeg::tick(float _DT)
{
	CObj::tick(_DT);
}

void CPeg::BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol)
{
	if (!(m_Collider->GetBOnOff()))
	{
		return;
	}
	if (_OtherObj->GetLayerIdx() == ORB)
	{
		// 데미지 여기에 띄워주세요
		COrb* orb = dynamic_cast<COrb*>(_OtherObj);
		orb->SetAccDamagePos(Vec2(GetPos().x, GetPos().y - (GetScale().y/2) - 2.f));

		++iCurCnt;
		if (0 >=iDieCnt- iCurCnt)
		{
			bCrashed = true;
			// 죽어있는 척 할거면 페그 사라질 때의 애니메이션 처리를 해줘야 함.
			m_Animator->Play(L"CrashedPeg",false);
			//m_Collider->SetBOnOff(false);
		}
		if (!(dynamic_cast<COrb*>(_OtherObj)->GetCurOrbType() == ORB_TYPE(RUBBORB)))
		{
			//dynamic_cast<COrb*>(_OtherObj)->GetComponent<CMovement>()->AddVelocity(Vec2(800.f, 800.f));
		}
		else
		{
			dynamic_cast<COrb*>(_OtherObj)->GetComponent<CMovement>()->AddVelocity(Vec2(800.f, 800.f));
		}
	}
}

