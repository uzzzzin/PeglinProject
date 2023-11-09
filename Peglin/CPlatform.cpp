#include "pch.h"
#include "CPlatform.h"

#include "components.h"

CPlatform::CPlatform()
{
	m_Collider = AddComponent<CCollider>(L"FloorCollider");
}

CPlatform::CPlatform(const CPlatform& _Origin)
	: CObj(_Origin)
	, m_Collider(nullptr)
{
	m_Collider = GetComponent<CCollider>();
}

CPlatform::~CPlatform()
{
}

void CPlatform::begin()
{
	m_Collider->SetScale(GetScale());
}

void CPlatform::tick(float _DT)
{

}

//void CPlatform::BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol)
//{
//	float up = (_OwnCol->GetScale().y / 2.f + _OtherCol->GetScale().y / 2.f - abs(_OwnCol->GetPos().y - _OtherCol->GetPos().y)) / 2.f;
//	_OtherObj->SetPos(Vec2(_OtherObj->GetPos().x, _OtherObj->GetPos().y - up));
//}
//
//
//void CPlatform::Overlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol)
//{
//	float up = (_OwnCol->GetScale().y / 2.f + _OtherCol->GetScale().y / 2.f - abs(_OwnCol->GetPos().y - _OtherCol->GetPos().y)) / 2.f;
//	_OtherObj->SetPos(Vec2(_OtherObj->GetPos().x, _OtherObj->GetPos().y - up));
//}