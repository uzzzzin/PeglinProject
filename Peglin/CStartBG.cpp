#include "pch.h"
#include "CStartBG.h"

#include "CCamera.h"
#include "CCamera.h"
#include "CAssetMgr.h"
#include "CTexture.h"

CStartBG::CStartBG()
	: m_Texture(nullptr)
{
	m_Texture = CAssetMgr::GetInst()->LoadTexture(L"StartBGTex", L"texture\\BoardBG.png");
}

CStartBG::~CStartBG()
{
}

void CStartBG::begin()

{
}

void CStartBG::tick(float _DT)
{
	Super::tick(_DT);
}

void CStartBG::render(HDC _dc)
{
	//Vec2 vPos = GetPos();
	Vec2 vRenderPos = GetPos();
	//Vec2 vRenderPos = GetRenderPos();
	Vec2 vScale = GetScale();
	//m_Texture->SetTexScale(GetScale());

	BLENDFUNCTION blend = {};
	blend.BlendOp = AC_SRC_OVER;
	blend.BlendFlags = 0;

	blend.SourceConstantAlpha = 255; // 0 ~ 255
	blend.AlphaFormat = AC_SRC_ALPHA; // 0

	AlphaBlend(_dc
		, int(vRenderPos.x - vScale.x / 2.f)
		, int(vRenderPos.y - vScale.y/ 2.f)

		, vScale.x
		, vScale.y

		, m_Texture->GetDC()
		, 0, 0
		, m_Texture->GetWidth()
		, m_Texture->GetHeight()

		//, int(vRenderPos.x - m_Texture->GetWidth() / 2.f)
		//, int(vRenderPos.y - m_Texture->GetHeight() / 2.f)

		//, m_Texture->GetWidth()
		//, m_Texture->GetHeight()

		//, m_Texture->GetDC()
		//, 0,0
		//, m_Texture->GetWidth()
		//, m_Texture->GetHeight()

		, blend);

	Super::render(_dc);
}
