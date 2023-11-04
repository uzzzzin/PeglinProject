#include "pch.h"
#include "CBombPeg.h"

#include "CAssetMgr.h"
#include "CTexture.h"
#include "CKeyMgr.h"

#include "components.h"

CBombPeg::CBombPeg()
{
	SetiDieCnt(2);
	SetiCurCnt(0);
	SetbDied(false);

	//CTexture* pTex = CAssetMgr::GetInst()->LoadTexture(L"BombPeg", L"texture\\BombPeg.png");
	//m_Animator->LoadAnimation(pTex, L"BombPeg", L"animdata\\BombPegMeta.txt",false);

	m_Animator->LoadAnimation(L"animdata\\BombPeg.txt");
	//m_Animator->Play(L"BombPeg", true);
}

CBombPeg::~CBombPeg()
{
}

void CBombPeg::begin()
{
}

void CBombPeg::tick(float _DT)
{
	Super::tick(_DT);
	if (KEY_RELEASED(A))
	{
		m_Animator->Play(L"BombPeg", true);
	}
}

void CBombPeg::render(HDC _dc)
{
	Super::render(_dc);
}

void CBombPeg::Reload()
{
}
