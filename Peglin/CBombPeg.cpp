#include "pch.h"
#include "CBombPeg.h"

#include "CAssetMgr.h"
#include "CTexture.h"
#include "CKeyMgr.h"

#include "components.h"

CBombPeg::CBombPeg()
{
	SetiDieCnt(2);

	//CTexture* pTex = CAssetMgr::GetInst()->LoadTexture(L"BombPeg", L"texture\\BombPeg.png");
	//m_Animator->LoadAnimation(pTex, L"BombPeg", L"animdata\\BombPegMeta.txt",false);

	m_Animator->LoadAnimation(L"animdata\\BombPeg.txt");
	m_Animator->Play(L"BombPeg", true);

	m_Collider->SetOffsetPos(Vec2(0.f, 0.f));
	m_Collider->SetScale(Vec2(24, 24));
	m_Collider->SetOffsetPos(Vec2(0.f, 0.f));
}

CBombPeg::~CBombPeg()
{
}

void CBombPeg::begin()
{
	//SetScale(Vec2(GetScale().x, GetScale().y+5));
	SetPos(Vec2(GetPos().x, GetPos().y + 10));
}

void CBombPeg::tick(float _DT)
{
	Super::tick(_DT);
	//if (KEY_RELEASED(A))
	//{
	//	m_Animator->Play(L"BombPeg", true);
	//}
}

void CBombPeg::render(HDC _dc)
{
	Super::render(_dc);
}

void CBombPeg::Reload()
{
}
