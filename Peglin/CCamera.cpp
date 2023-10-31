#include "pch.h"
#include "CCamera.h"

#include "CEngine.h"
#include "CKeyMgr.h"
#include "CTimeMgr.h"

#include "CAssetMgr.h"
#include "CTexture.h"

CCamera::CCamera()
	: m_Veil(nullptr)
	, m_Alpha(0.f)
{
	//Vec2 vResol = CEngine::GetInst()->GetResolution();
	//m_Veil = CAssetMgr::GetInst()->CreateTexture(L"VeilTex", vResol.x, vResol.y);

}

CCamera::~CCamera()
{
}

void CCamera::tick()
{
	//// ����Ű�� ī�޶� �ٶ󺸰� �ִ� ��ġ�� ����
	if (KEY_PRESSED(KEY::LEFT))
	{
		m_vLookAt.x -= 200.f * DT;
	}

	if (KEY_PRESSED(KEY::RIGHT))
	{
		m_vLookAt.x += 200.f * DT;
	}

	if (KEY_PRESSED(KEY::UP))
	{
		m_vLookAt.y -= 200.f * DT;
	}

	if (KEY_PRESSED(KEY::DOWN))
	{
		m_vLookAt.y += 200.f * DT;
	}

	// ȭ�� �ػ��� �߽���ġ�� �˾Ƴ���.
	Vec2 vResolution = CEngine::GetInst()->GetResolution();
	Vec2 vCenter = vResolution / 2.f;

	// �ػ� �߽ɰ�, ī�޶� ���� �����ִ� ��ǥ�� ���̰��� ���Ѵ�.
	m_vDiff = m_vLookAt - vCenter;

	// ī�޶� �̺�Ʈ�� ������ ����
	if (m_EventList.empty())
		return;

	// ī�޶� �̺�Ʈ�� �����Ѵٸ�
	FCamEvent& evnt = m_EventList.front();

	if (evnt.Type == CAM_EFFECT::FADE_IN)
	{
		evnt.AccTime += DT;

		if (evnt.Duration <= evnt.AccTime)
		{
			m_Alpha = 0;
			m_EventList.pop_front();
		}
		else
		{
			float fRatio = evnt.AccTime / evnt.Duration;
			float alpha = 1.f - fRatio;
			m_Alpha = (UINT)(alpha * 255);
		}
	}

	else if (evnt.Type == CAM_EFFECT::FADE_OUT)
	{
		evnt.AccTime += DT;

		if (evnt.Duration <= evnt.AccTime)
		{
			m_EventList.pop_front();
			m_Alpha = 255;
		}
		else
		{
			float fRatio = evnt.AccTime / evnt.Duration;
			float alpha = fRatio;
			m_Alpha = (UINT)(alpha * 255);
		}
	}
}

void CCamera::render(HDC _dc)
{
	//if (0 == m_Alpha)
	//	return;

	//BLENDFUNCTION blend = {};
	//blend.BlendOp = AC_SRC_OVER;
	//blend.BlendFlags = 0;

	//blend.SourceConstantAlpha = m_Alpha; // 0 ~ 255
	//blend.AlphaFormat = 0; // 0

	//AlphaBlend(_dc
	//	, 0, 0, m_Veil->GetWidth(), m_Veil->GetHeight()
	//	, m_Veil->GetDC()
	//	, 0, 0
	//	, m_Veil->GetWidth(), m_Veil->GetHeight()
	//	, blend);


	if (!DEBUG_RENDER)
		return;

	SELECT_PEN(_dc, RED_PEN);

	Vec2 vRenderPos = GetRenderPos(m_vLookAt);
	MoveToEx(_dc, int(vRenderPos.x - 7.f), (int)vRenderPos.y, nullptr);
	LineTo(_dc, int(vRenderPos.x + 7.f), (int)vRenderPos.y);

	MoveToEx(_dc, int(vRenderPos.x), int(vRenderPos.y - 7.f), nullptr);
	LineTo(_dc, int(vRenderPos.x), int(vRenderPos.y + 7.f));
}