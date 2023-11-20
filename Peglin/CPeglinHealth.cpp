#include "pch.h"
#include "CPeglinHealth.h"

#include "CAssetMgr.h"
#include "CTexture.h"

#include "CLevelMgr.h"
#include "CGeneralLevel.h"
#include "CPeglinPlayer.h"


CPeglinHealth::CPeglinHealth()
	: m_blood(nullptr)
	, m_HealthUI(nullptr)
	, m_100(nullptr)
	,m_Num100(nullptr)
{
	m_blood = CAssetMgr::GetInst()->LoadTexture(L"PeglinBlood", L"texture\\PeglinBlood.png");
	m_HealthUI = CAssetMgr::GetInst()->LoadTexture(L"PeglinHealth", L"texture\\PeglinHealth.png");
	m_100 = CAssetMgr::GetInst()->LoadTexture(L"Number100Slash", L"texture\\Number100Slash.png");

	m_Num100 = CAssetMgr::GetInst()->LoadTexture(L"Number100", L"texture\\Number100.png");

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

CPeglinHealth::~CPeglinHealth()
{
}


void CPeglinHealth::begin()
{
}

void CPeglinHealth::tick(float _DT)
{
	Super::tick(_DT);
}

void CPeglinHealth::render(HDC _dc)
{
	Vec2 vRenderPos = GetRenderPos();
	Vec2 vScale = GetScale();

	CGeneralLevel* pCurLevel = dynamic_cast<CGeneralLevel*>(CLevelMgr::GetInst()->GetCurLevel());
	CPeglinPlayer* pPeglin = dynamic_cast<CPeglinPlayer*>(pCurLevel->FindObjectByName(L"PeglinPlayer"));

	//int hp = pPeglin->GetHP();

	int hp = 50;

	// HealthUI
	BLENDFUNCTION blend = {};
	blend.BlendOp = AC_SRC_OVER;
	blend.BlendFlags = 0;

	blend.SourceConstantAlpha = 255; // 0 ~ 255
	blend.AlphaFormat = AC_SRC_ALPHA; // 0

	AlphaBlend(_dc
		, int(vRenderPos.x - vScale.x / 2.f)
		, int(vRenderPos.y - vScale.y / 2.f)
		, vScale.x
		, vScale.y
		, m_HealthUI->GetDC()
		, 0, 0
		, m_HealthUI->GetWidth()
		, m_HealthUI->GetHeight()
		, blend);

	//Blood
	BLENDFUNCTION blend2 = {};
	blend2.BlendOp = AC_SRC_OVER;
	blend2.BlendFlags = 0;

	blend2.SourceConstantAlpha = 255; // 0 ~ 255
	blend2.AlphaFormat = AC_SRC_ALPHA; // 0

	AlphaBlend(_dc
		, int(   (vRenderPos.x - vScale.x / 2.f) + 68.f  )
		, int(   (vRenderPos.y - vScale.y / 2.f)  +28.f )
		, vScale.x * 172/vScale.x * hp / 100
		, vScale.y * 8 / vScale.y
		, m_blood->GetDC()
		, 0, 0
		, m_blood->GetWidth()
		, m_blood->GetHeight()
		, blend2);


	// m_100
	BLENDFUNCTION blend3 = {};
	blend3.BlendOp = AC_SRC_OVER;
	blend3.BlendFlags = 0;

	blend3.SourceConstantAlpha = 255; // 0 ~ 255
	blend3.AlphaFormat = AC_SRC_ALPHA; // 0

	AlphaBlend(_dc
		, int((vRenderPos.x - vScale.x / 2.f) + 133.f)
		, int((vRenderPos.y - vScale.y / 2.f) -  20.f)
		, m_100->GetWidth() * 0.8
		, m_100->GetHeight() * 0.8
		, m_100->GetDC()
		, 0, 0
		, m_100->GetWidth()
		, m_100->GetHeight()
		, blend3);


	// HP
	int hp1 = hp / 10;
	Nums[hp1];
	int hp2 = hp % 10;

	if (!(100 == hp))
	{
		//  십의 자리
		BLENDFUNCTION blend5 = {};
		blend5.BlendOp = AC_SRC_OVER;
		blend5.BlendFlags = 0;

		blend5.SourceConstantAlpha = 255; // 0 ~ 255
		blend5.AlphaFormat = AC_SRC_ALPHA; // 0

		AlphaBlend(_dc
			, int((vRenderPos.x - vScale.x / 2.f) + 76.f)
			, int((vRenderPos.y - vScale.y / 2.f) - 20.f)
			, Nums[hp1]->GetWidth() * 0.8
			, Nums[hp1]->GetHeight() * 0.8
			, Nums[hp1]->GetDC()
			, 0, 0
			, Nums[hp1]->GetWidth()
			, Nums[hp1]->GetHeight()
			, blend5);

		// 일의 자리
		BLENDFUNCTION blend6 = {};
		blend6.BlendOp = AC_SRC_OVER;
		blend6.BlendFlags = 0;

		blend6.SourceConstantAlpha = 255; // 0 ~ 255
		blend6.AlphaFormat = AC_SRC_ALPHA; // 0

		AlphaBlend(_dc
			, int((vRenderPos.x - vScale.x / 2.f) + 99.f)
			, int((vRenderPos.y - vScale.y / 2.f) - 20.f)
			, Nums[hp2]->GetWidth() * 0.8
			, Nums[hp2]->GetHeight() * 0.8
			, Nums[hp2]->GetDC()
			, 0, 0
			, Nums[hp2]->GetWidth()
			, Nums[hp2]->GetHeight()
			, blend6);

	}
	else // 풀피일 때 
	{
		BLENDFUNCTION blend4= {};
		blend4.BlendOp = AC_SRC_OVER;
		blend4.BlendFlags = 0;

		blend4.SourceConstantAlpha = 255; // 0 ~ 255
		blend4.AlphaFormat = AC_SRC_ALPHA; // 0

		AlphaBlend(_dc
			, int((vRenderPos.x - vScale.x / 2.f) + 60.f)
			, int((vRenderPos.y - vScale.y / 2.f) - 20.f)
			, m_Num100->GetWidth() * 0.8
			, m_Num100->GetHeight() * 0.8
			, m_Num100->GetDC()
			, 0, 0
			, m_Num100->GetWidth()
			, m_Num100->GetHeight()
			, blend4);
	}




	Super::render(_dc);
}
