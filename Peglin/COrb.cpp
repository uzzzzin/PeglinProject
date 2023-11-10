#include "pch.h"
#include "COrb.h"

#include "CAssetMgr.h"
#include "CKeyMgr.h"
#include "CLogMgr.h"

#include "components.h"

COrb::COrb()
	: m_Collider(nullptr)
	, m_Animator(nullptr)
	, m_Movement(nullptr)
{

	m_Animator = AddComponent<CAnimator>(L"OrbAnimator");
	m_Animator->LoadAnimation(L"animdata\\BouncyBall.txt");
	m_Animator->Play(L"BouncyBall", true);

	// 충돌체 컴포넌트 추가
	m_Collider = AddComponent<CColliderCircle>(L"OrbCollider");
	m_Collider->SetOffsetPos(Vec2(0.f, 0.f));
	m_Collider->SetScale(Vec2(24.f, 24.f));

	// Movement 컴포넌트 추가
	m_Movement = AddComponent<CMovement>(L"OrbMovement");
	m_Movement->SetMass(1.f);
	m_Movement->SetInitSpeed(200.f);
	m_Movement->SetMaxSpeed(1000.f);
	m_Movement->SetFrictionScale(1000.f);

	m_Movement->UseGravity(false);
	m_Movement->SetGravity(Vec2(0.f, 980.f));
	m_Movement->SetGround(false);
}

COrb::~COrb()
{
}

void COrb::tick(float _DT)
{
	Super::tick(_DT);
	curPos = GetPos();
	if (GetLBoundaryX() > curPos.x)
	{
		//LOG(ERR, L"LEFT holy....");

		m_Movement->SetVelocity(Vec2((m_Movement->GetVelocity().x * -1), m_Movement->GetVelocity().y));
	}
	if (GetRBoundaryX() < curPos.x)
	{
		//	LOG(ERR, L"RIGHT holy....");
		m_Movement->SetVelocity(Vec2((m_Movement->GetVelocity().x * -1), m_Movement->GetVelocity().y));
	}
	if (GetUBoundaryY() > curPos.y)
	{
		//	LOG(ERR, L"UP holy....");
		m_Movement->SetVelocity(Vec2(m_Movement->GetVelocity().x, (m_Movement->GetVelocity().y) * -1));
	}
	if (GetDBoundaryY() < curPos.y)
	{
		LOG(ERR, L" 페글린 지옥행");
		m_Movement->SetVelocity(Vec2(m_Movement->GetVelocity().x, (m_Movement->GetVelocity().y) * -1));
	}


	if (KEY_PRESSED(SPACE))
	{
		m_Movement->UseGravity(true);
	}


	if (KEY_PRESSED(A))
	{
		m_Movement->AddForce(Vec2(-300.f, 0.f));
	}
	if (KEY_PRESSED(D))
	{
		m_Movement->AddForce(Vec2(300.f, 0.f));
	}
	if (KEY_PRESSED(W))
	{
		m_Movement->AddForce(Vec2(0.f, -300.f));
	}
	if (KEY_PRESSED(S))
	{
		m_Movement->AddForce(Vec2(0.f, 300.f));
	}


	if (KEY_PRESSED(V))
	{
		SetPos(REALCENTER);
		m_Movement->UseGravity(false);
	}
	if (KEY_TAP(LBTN)) {
		SetPos(CKeyMgr::GetInst()->GetMousePos());
		m_Movement->SetVelocity({ 0,0 });
		m_Movement->UseGravity(false);
	}
	prevPos = curPos;
}

void COrb::BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol)
{
	if (GetLBoundaryX() > curPos.x)
	{
		curPos.x = GetLBoundaryX();
		SetPos(Vec2(curPos.x, curPos.y));
	}
	if (GetRBoundaryX() < curPos.x)
	{
		curPos.x = GetRBoundaryX();
		SetPos(Vec2(curPos.x, curPos.y));
	}
	if (GetUBoundaryY() > curPos.y)
	{
		curPos.y = GetUBoundaryY();
		SetPos(Vec2(curPos.x, curPos.y));
	}
	if (GetDBoundaryY() < curPos.y)
	{
		curPos.y = GetDBoundaryY();
		SetPos(Vec2(curPos.x, curPos.y));
	}
}

void COrb::Overlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol)
{
	if (GetLBoundaryX() > curPos.x)
	{
		curPos.x = GetLBoundaryX();
		SetPos(Vec2(curPos.x, curPos.y));
	}
	if (GetRBoundaryX() < curPos.x)
	{
		curPos.x = GetRBoundaryX();
		SetPos(Vec2(curPos.x, curPos.y));
	}
	if (GetUBoundaryY() > curPos.y)
	{
		curPos.y = GetUBoundaryY();
		SetPos(Vec2(curPos.x, curPos.y));
	}
	if (GetDBoundaryY() < curPos.y)
	{
		curPos.y = GetDBoundaryY();
		SetPos(Vec2(curPos.x, curPos.y));
	}
}