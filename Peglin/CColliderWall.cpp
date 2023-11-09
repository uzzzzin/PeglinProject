#include "pch.h"
#include "CColliderWall.h"

#include "CKeyMgr.h"

CColliderWall::CColliderWall()
	: m_Collider(nullptr)
{
	// 충돌체 컴포넌트 추가
	m_Collider = AddComponent<CCollider>(L"LWallCollider");
	m_Collider->SetOffsetPos(Vec2(0.f,0.f));
	m_Collider->SetScale(Vec2(45.f, 630.f));
	m_Collider->SetOffsetPos(Vec2(0.f, 0.f));
}

CColliderWall::~CColliderWall()
{
}

void CColliderWall::begin()
{
	m_Collider->SetScale(GetScale());
}

void CColliderWall::tick(float _DT)
{
}

//
//void CColliderWall::BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol)
//{
//	//float up = (_OwnCol->GetScale().y / 2.f + _OtherCol->GetScale().y / 2.f - abs(_OwnCol->GetPos().y - _OtherCol->GetPos().y)) / 2.f;
//	//_OtherObj->SetPos(Vec2(_OtherObj->GetPos().x, _OtherObj->GetPos().y - up));
//
//}
//
//
//void CColliderWall::Overlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol)
//{
//
//	if (GetLBoundaryX() > _OtherObj->GetPos().x)
//	{
//		LOG(ERR, L"LEFT holy....");
//
//	}
//	if (GetRBoundaryX() < _OtherObj->GetPos().x)
//	{
//		LOG(ERR, L"RIGHT holy....");
//	}
//	if (GetUBoundaryY() > _OtherObj->GetPos().y)
//	{
//		LOG(ERR, L"UP holy....");
//	}
//	if (GetDBoundaryY() < _OtherObj->GetPos().y)
//	{
//		LOG(ERR, L"DOWN holy....");
//	}
//}
