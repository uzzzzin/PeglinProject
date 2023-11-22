#include "pch.h"
#include "CPeglinDamaged.h"

#include "CAssetMgr.h"
#include "CTexture.h"

CPeglinDamaged::CPeglinDamaged()
	:m_PeglinDamagedUI(nullptr)
	, m_Transform(nullptr)
	, damageNum(0)
	, alphaCnt(255)
{

	m_Transform = AddComponent<CTransform>(L"Transform");

	RedNums.resize(10);

	for (int i = 0; i < 10; ++i)
	{
		wstring name = L"RedNumber";
		name += std::to_wstring(i);
		wstring pngname = name;
		pngname = L"texture\\" + name + L".png";
		CTexture* pTexture = CAssetMgr::GetInst()->LoadTexture(name, pngname);
		RedNums[i] = pTexture;
	}
}

CPeglinDamaged::~CPeglinDamaged()
{
}


void CPeglinDamaged::render(HDC _dc)
{

	Vec2 vRenderPos = GetPos();
	Vec2 vScale = GetScale();


	//Blood
	BLENDFUNCTION blend2 = {};
	blend2.BlendOp = AC_SRC_OVER;
	blend2.BlendFlags = 0;

	blend2.SourceConstantAlpha = alphaCnt; // 0 ~ 255
	blend2.AlphaFormat = AC_SRC_ALPHA; // 0

	AlphaBlend(_dc
		, int((vRenderPos.x - vScale.x / 2.f))
		, int((vRenderPos.y - vScale.y / 2.f) )
		, RedNums[damageNum]->GetWidth() * 0.5
		, RedNums[damageNum]->GetHeight() * 0.5
		, RedNums[damageNum]->GetDC()
		, 0, 0
		, RedNums[damageNum]->GetWidth()
		, RedNums[damageNum]->GetHeight()
		, blend2);

	Super::render(_dc);
}

void CPeglinDamaged::finaltick(float _DT)
{
	Super::finaltick(_DT);
}
