#include "pch.h"
#include "CColliderCircle.h"

#include "CEngine.h"
#include "CCamera.h"

CColliderCircle::CColliderCircle(CObj* _Owner)
	: CCollider(_Owner) 
{
}


CColliderCircle::~CColliderCircle()
{
}

void CColliderCircle::render(HDC _dc)
{
	if (!DEBUG_RENDER)
		return;

	SELECT_BRUSH(_dc, (HBRUSH)GetStockObject(HOLLOW_BRUSH));

	Vec2 vRenderPos = CCamera::GetInst()->GetRenderPos(m_vFinalPos);

	if (0 < m_iCollisionCount)
	{
		SELECT_PEN(_dc, RED_PEN);

		// render
		Ellipse(_dc, int(vRenderPos.x - m_vScale.x / 2.f)
			, int(vRenderPos.y - m_vScale.y / 2.f)
			, int(vRenderPos.x + m_vScale.x / 2.f)
			, int(vRenderPos.y + m_vScale.y / 2.f));
	}
	else
	{
		SELECT_PEN(_dc, GREEN_PEN);

		// render
		Ellipse(_dc, int(vRenderPos.x - m_vScale.x / 2.f)
			, int(vRenderPos.y - m_vScale.y / 2.f)
			, int(vRenderPos.x + m_vScale.x / 2.f)
			, int(vRenderPos.y + m_vScale.y / 2.f));
	}
}

