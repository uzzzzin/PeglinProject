#include "pch.h"
#include "CBombPeg.h"

#include "CAssetMgr.h"
#include "CTexture.h"
#include "CKeyMgr.h"
#include "CSound.h"

#include "components.h"
#include "COrb.h"

CBombPeg::CBombPeg()
	: m_SE(nullptr)
	, m_SE2(nullptr)
{
	SetiDieCnt(2);
	SetName(L"BombPeg");
	//CTexture* pTex = CAssetMgr::GetInst()->LoadTexture(L"BombPeg", L"texture\\BombPeg.png");
	//m_Animator->LoadAnimation(pTex, L"BombPeg", L"animdata\\BombPegMeta.txt",false);

	m_Animator->LoadAnimation(L"animdata\\BombPeg.txt");
	m_Animator->LoadAnimation(L"animdata\\BombPegBefore.txt");
	m_Animator->LoadAnimation(L"animdata\\CrashedBombPeg.txt");

	m_Collider->SetOffsetPos(Vec2(0.f, 0.f));
	m_Collider->SetScale(Vec2(24, 24));
	m_Collider->SetOffsetPos(Vec2(0.f, 0.f));

	m_SE = CAssetMgr::GetInst()->LoadSound(L"BombPegColSE1", L"sound\\BombPegColSE1.wav");
	m_SE2 = CAssetMgr::GetInst()->LoadSound(L"BombPegColSE2", L"sound\\BombPegColSE2.wav");


}

CBombPeg::~CBombPeg()
{
}

void CBombPeg::begin()
{
	//SetScale(Vec2(GetScale().x, GetScale().y+5));
	SetPos(Vec2(GetPos().x, GetPos().y + 10));
	m_Animator->Play(L"BombPegBefore", true);
}

void CBombPeg::tick(float _DT)
{
	Super::tick(_DT);
}

void CBombPeg::render(HDC _dc)
{
	Super::render(_dc);
}

void CBombPeg::Reload()
{
}

void CBombPeg::Refresh()
{
}

void CBombPeg::BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol)
{
	if (0 >= iDieCnt - iCurCnt)
	{
		m_Collider->SetBOnOff(false);
		return;
	}

	++iCurCnt;
	bCrashed = false;
	m_Collider->SetBOnOff(true);

	if (0 >= iDieCnt - iCurCnt)
	{
		dynamic_cast<COrb*>(_OtherObj)->GetComponent<CMovement>()->AddVelocity(Vec2(400.f, 400.f));
		CCamera::GetInst()->Shake(0.06f, 6);
		bCrashed = true;
		m_Animator->Play(L"CrashedBombPeg", false);
		m_SE2->Play(false);
	}

	if (_OtherObj->GetLayerIdx() == ORB)
	{
		if (1 == iDieCnt - iCurCnt)
		{
			if (dynamic_cast<COrb*>(_OtherObj)->GetCurOrbType() == ORB_TYPE(INFERNORB))
			{
				dynamic_cast<COrb*>(_OtherObj)->GetComponent<CMovement>()->AddVelocity(Vec2(600.f,600.f));
				CCamera::GetInst()->Shake(0.04f, 6);
				bCrashed = true;
				m_Animator->Play(L"CrashedBombPeg", false);
				m_SE2->Play(false);
				++iCurCnt;
				return;
			}
			m_Animator->Play(L"BombPeg", true);
			m_Collider->SetBOnOff(true);
			m_SE->Play(false);
		}
		
	}

	//if (dynamic_cast<COrb*>(_OtherObj)->GetCurOrbType() == ORB_TYPE(INFERNORB)) // È­¿°±¸ ÀÏ ¶§
	//{
	//	CCamera::GetInst()->Shake(0.06f, 6);
	//	bCrashed = true;
	//	m_Animator->Play(L"CrashedBombPeg", false);
	//	m_SE2->Play(false);
	//	m_Collider->SetBOnOff(false);
	//	return;
	//}

}

