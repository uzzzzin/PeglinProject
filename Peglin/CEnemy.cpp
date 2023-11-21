#include "pch.h"
#include "CEnemy.h"

#include "CLevelMgr.h"
#include "CAssetMgr.h"
#include "CTexture.h"

#include "CUI.h"
#include "CImg.h"
#include "components.h"
#include "CLevel.h"

CEnemy::CEnemy()
	: EnemyInitInfo{}
	, m_Animator(nullptr)
	, m_Transform(nullptr)
	, m_blood(nullptr)
	, m_HealthUI(nullptr)
	, m_slash(nullptr)
{
	EnemyInfo BlueSlime = {BLUE_SLIME, L"BlueSlime", 80, 3, L"animdata\\BlueSlimeIdle.txt", L"BlueSlimeIdle",  L"animdata\\BlueSlimeDie.txt", L"BlueSlimeDie",  L"animdata\\BlueSlimeIdle.txt", L"BlueSlimeIdle" };

	Enemys.push_back(BlueSlime);

	m_Animator = AddComponent<CAnimator>(L"EnemyAnimator");
	m_Transform = AddComponent<CTransform>(L"EnemyTransform");
	//m_AI = AddComponent<CStateMachine>(L"EnemyAI");

	SetEnemyInfo(BLUE_SLIME);

	//m_Movement->SetMaxSpeed(400.f);
	//m_Movement->SetFrictionScale(1000.f);
	//m_Movement->UseGravity(false);
	//m_Movement->SetGravity(Vec2(0.f, 980.f));
	//m_Movement->SetGround(true);

	m_blood = CAssetMgr::GetInst()->LoadTexture(L"MonsterBlood", L"texture\\MonsterBlood.png");
	m_HealthUI = CAssetMgr::GetInst()->LoadTexture(L"SlimeHealth", L"texture\\EnemyHealth.png");
	m_slash = CAssetMgr::GetInst()->LoadTexture(L"Slash", L"texture\\Slash.png");

	Nums.resize(10);

	for (int i = 0; i < 10; ++i)
	{
		wstring name = L"Number";
		name += std::to_wstring(i);
		wstring pngname = name;
		pngname = L"texture\\" + name + L".png";
		CTexture* pTexture = CAssetMgr::GetInst()->LoadTexture(name, pngname);
		Nums[i] = pTexture;
	}

}

CEnemy::~CEnemy()
{
}

//void CEnemy::begin()
//{
//	//CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();
//	//pCurLevel->AddObject(UI, hpUI);
//
//		//hpUI->SetPos(Vec2(GetPos().x, GetPos().y - 100.f));
//	//hpUI->SetScale(Vec2(96.f, 42.f));
//	//hpUI->SetImg(L"animdata\\EnemyHealthUI.txt", L"EnemyHealthUI");
//}

void CEnemy::SetEnemyInfo(ENEMY_TYPE _type)
{
	/*if ( !_type)
	{
		LOG(ERR, "몬스터 정보가 이상한데?");
		return;
	}*/

	type = _type;
	UINT a = (UINT)_type;

	curHP = Enemys[a].hp;
	fullHP = Enemys[a].hp;
	damage = Enemys[a].damage;

	m_Animator->LoadAnimation(Enemys[a].idleAnimPath);
	m_Animator->Play(Enemys[a].idleAnimName,true);
}


void CEnemy::render(HDC _dc)
{
	Vec2 vRenderPos = GetRenderPos();
	Vec2 vScale = GetScale();


	//Blood
	BLENDFUNCTION blend2 = {};
	blend2.BlendOp = AC_SRC_OVER;
	blend2.BlendFlags = 0;

	blend2.SourceConstantAlpha = 230; // 0 ~ 255
	blend2.AlphaFormat = AC_SRC_ALPHA; // 0

	AlphaBlend(_dc
		, int((vRenderPos.x - vScale.x / 2.f) + 7.7f)
		, int((vRenderPos.y - vScale.y / 2.f) - 37.f)
		, (vScale.x - 14.f)* (float(curHP) / float(fullHP))
		, vScale.y - 43.f
		, m_blood->GetDC()
		, 0, 0
		, m_blood->GetWidth()
		, m_blood->GetHeight()
		, blend2);


	// HealthUI
	BLENDFUNCTION blend = {};
	blend.BlendOp = AC_SRC_OVER;
	blend.BlendFlags = 0;

	blend.SourceConstantAlpha = 230; // 0 ~ 255
	blend.AlphaFormat = AC_SRC_ALPHA; // 0

	AlphaBlend(_dc
		, int(vRenderPos.x - vScale.x / 2.f)
		, int(vRenderPos.y - vScale.y / 2.f - 70.f )
		, vScale.x 
		, vScale.y 
		, m_HealthUI->GetDC()
		, 0, 0
		, m_HealthUI->GetWidth()
		, m_HealthUI->GetHeight()
		, blend);

	// Slash
	//BLENDFUNCTION blend10 = {};
	blend.BlendOp = AC_SRC_OVER;
	blend.BlendFlags = 0;

	blend.SourceConstantAlpha = 255; // 0 ~ 255
	blend.AlphaFormat = AC_SRC_ALPHA; // 0

	AlphaBlend(_dc
		, int(vRenderPos.x - vScale.x / 2.f + 33.f)
		, int(vRenderPos.y - vScale.y / 2.f - 65.f)
		, vScale.x * 0.2*0.95
		, vScale.y * 0.36*0.95
		, m_slash->GetDC()
		, 0, 0
		, m_slash->GetWidth()
		, m_slash->GetHeight()
		, blend);

	if (curHP <= 0) {
		curHP = 0;
	}
	// curHP
	int hp1 = curHP / 10;
	int hp2 = curHP % 10;

	//  십의 자리
	blend.BlendOp = AC_SRC_OVER;
	blend.BlendFlags = 0;

	blend.SourceConstantAlpha = 255; // 0 ~ 255
	blend.AlphaFormat = AC_SRC_ALPHA; // 0

	AlphaBlend(_dc
		, int(vRenderPos.x - vScale.x / 2.f + 10.f)
		, int(vRenderPos.y - vScale.y / 2.f - 63.5f)
		, Nums[hp1]->GetWidth() *0.4
		, Nums[hp1]->GetHeight() *0.4
		, Nums[hp1]->GetDC()
		, 0, 0
		, Nums[hp1]->GetWidth()
		, Nums[hp1]->GetHeight()
		, blend);

	// 일의 자리
	blend.BlendOp = AC_SRC_OVER;
	blend.BlendFlags = 0;

	blend.SourceConstantAlpha = 255; // 0 ~ 255
	blend.AlphaFormat = AC_SRC_ALPHA; // 0

	AlphaBlend(_dc
		, int((vRenderPos.x - vScale.x / 2.f) + 21.f)
		, int((vRenderPos.y - vScale.y / 2.f) - 63.5f)
		, Nums[hp2]->GetWidth() * 0.4
		, Nums[hp2]->GetHeight() * 0.4
		, Nums[hp2]->GetDC()
		, 0, 0
		, Nums[hp2]->GetWidth()
		, Nums[hp2]->GetHeight()
		, blend);

	// fullHP
	hp1 = fullHP / 10;
	hp2 = fullHP % 10;

	//  십의 자리
	blend.BlendOp = AC_SRC_OVER;
	blend.BlendFlags = 0;

	blend.SourceConstantAlpha = 255; // 0 ~ 255
	blend.AlphaFormat = AC_SRC_ALPHA; // 0

	AlphaBlend(_dc
		, int(vRenderPos.x - vScale.x / 2.f + 50.5f)
		, int(vRenderPos.y - vScale.y / 2.f - 63.5f)
		, Nums[hp1]->GetWidth() * 0.4
		, Nums[hp1]->GetHeight() * 0.4
		, Nums[hp1]->GetDC()
		, 0, 0
		, Nums[hp1]->GetWidth()
		, Nums[hp1]->GetHeight()
		, blend);

	// 일의 자리
	blend.BlendOp = AC_SRC_OVER;
	blend.BlendFlags = 0;

	blend.SourceConstantAlpha = 255; // 0 ~ 255
	blend.AlphaFormat = AC_SRC_ALPHA; // 0

	AlphaBlend(_dc
		, int((vRenderPos.x - vScale.x / 2.f) + 61.f)
		, int((vRenderPos.y - vScale.y / 2.f) - 63.5f)
		, Nums[hp2]->GetWidth() * 0.4
		, Nums[hp2]->GetHeight() * 0.4
		, Nums[hp2]->GetDC()
		, 0, 0
		, Nums[hp2]->GetWidth()
		, Nums[hp2]->GetHeight()
		, blend);



	Super::render(_dc);
}

void CEnemy::finaltick(float _DT)
{
	Super::finaltick(_DT);
}
