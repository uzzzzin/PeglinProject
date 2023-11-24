#include "pch.h"
#include "CObstacle.h"

#include "CAssetMgr.h"
#include "CSound.h"

CObstacle::CObstacle()
	:m_Collider(nullptr)
	, m_SE(nullptr)
{
	SetName(L"Obstacle");
	m_Collider = AddComponent<CColliderCircle>(L"ObstacleCollider");
	m_Collider->SetScale(Vec2(45.f, 40.f));
	m_Collider->SetOffsetPos(Vec2(0.f, 0.f));

	m_SE = CAssetMgr::GetInst()->LoadSound(L"ObstacleColSE", L"sound\\ObstacleColSE.wav");
}

CObstacle::~CObstacle()
{
}

void CObstacle::begin()
{
	m_Collider->SetScale(GetScale());
}

void CObstacle::tick(float _DT)
{

}

float rightshadow(Vec2 _this, Vec2 _other)
{
	float ret;
	ret =  _this.Length() * _other.Length();
	Vec2 tanz = _other.Normalize() - _this.Normalize();
	
	float coss = cosf(atanf(tanz.y/tanz.x));
	ret *=  coss;
	return ret;
}


void CObstacle::BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol)
{
	CMovement* othMove = _OtherObj->GetComponent<CMovement>();

	m_SE->Play(false);
}

void CObstacle::Overlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol)
{


}

