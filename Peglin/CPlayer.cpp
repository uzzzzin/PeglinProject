#include "pch.h"
#include "CPlayer.h"

#include "CTimeMgr.h"
#include "CKeyMgr.h"
#include "CLevelMgr.h"
#include "CLevel.h"

#include "CProjectile.h"
#include "CGuided.h"

#include "CPathMgr.h"
#include "CEngine.h"

#include "CAssetMgr.h"
#include "CTexture.h"
#include "CLogMgr.h"
#include "CPlatform.h"

#include "components.h"

CPlayer::CPlayer()
	: m_Collider(nullptr)
	, m_Animator(nullptr)
	, m_Movement(nullptr)
{
	SetName(L"Player");

	// 애니메이터 컴포넌트 추가
	CTexture* pAtlas = CAssetMgr::GetInst()->LoadTexture(L"PlayerAtlas", L"texture\\link_alpha.bmp");
	m_Animator = AddComponent<CAnimator>(L"Animator");
	//m_Animator->CreateAnimation(L"IdleDown", pAtlas, Vec2(0.f, 0.f), Vec2(120, 130), Vec2(0.f, 0.f), 0.05f, 3);
	//m_Animator->SaveAnimations(L"animdata");
	m_Animator->LoadAnimation(L"animdata\\IdleDown.txt");

	m_Animator->Play(L"IdleDown", true);

	// 충돌체 컴포넌트 추가
	m_Collider = AddComponent<CColliderCircle>(L"PlayerCollider");
	m_Collider->SetOffsetPos(Vec2(0.f, 0.f));
	m_Collider->SetScale(Vec2(24.f, 24.f));

	// Movement 컴포넌트 추가
	m_Movement = AddComponent<CMovement>(L"PlayerMovement");
	m_Movement->SetMass(1.f);
	m_Movement->SetInitSpeed(200.f);
	m_Movement->SetMaxSpeed(1000.f);
	m_Movement->SetFrictionScale(1000.f);

	m_Movement->UseGravity(false);
	m_Movement->SetGravity(Vec2(0.f, 980.f));
	m_Movement->SetGround(false);
}

CPlayer::CPlayer(const CPlayer& _Origin)
	: CObj(_Origin)
	, m_Collider(nullptr)
	, m_Animator(nullptr)
	, m_Movement(nullptr)
{
	m_Collider = GetComponent<CColliderCircle>();
	m_Animator = GetComponent<CAnimator>();
	m_Movement = GetComponent<CMovement>();
}

CPlayer::~CPlayer()
{
}

void CPlayer::tick(float _DT)
{
	Super::tick(_DT);

	curPos = GetPos();
	vDest = curPos - prevPos;
	vDest.Normalize();

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
		m_Movement->SetVelocity({0,0});
		m_Movement->UseGravity(false);
	}
	prevPos = curPos;
}

void CPlayer::BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol)
{
	if (GetLBoundaryX() > curPos.x)
	{
		curPos.x = GetLBoundaryX();
		SetPos(Vec2(curPos.x,curPos.y));
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

		//CMovement* othMove = _OtherObj->GetComponent<CMovement>();

		//// 직선의 방정식
		//Vec2 _otherPos = _OtherCol->GetPos();
		//float a = (_otherPos.x - GetPos().x) / (_otherPos.y - GetPos().y); // 기울기
		//float b = GetPos().y - a * GetPos().x; // y 절편


		//// 원하는 점의 좌표 구하기.
		//float al;
		//float be;
		//al = prevPos.x - ((2 * a * (a * prevPos.x - prevPos.y + b)) / (a * a + 1));
		//be = prevPos.y - ((2 * (a * prevPos.x - prevPos.y + b) / (a * a + 1)));

		//Vec2 wantPoint = Vec2(al, be);

		//Vec2 wantVec = Vec2(wantPoint.x - GetPos().x, wantPoint.y - GetPos().y);

		//wantPoint = wantPoint.Normalize();

		////SetPos(Vec2(wantPoint.x, wantPoint.y));

		//m_Movement->SetVelocity(wantPoint);


}

void CPlayer::Overlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol)
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

		//CMovement* othMove = _OtherObj->GetComponent<CMovement>();

		//// 직선의 방정식
		//Vec2 _otherPos = _OtherCol->GetPos();
		//float a = (_otherPos.x - GetPos().x) / (_otherPos.y - GetPos().y); // 기울기
		//float b = GetPos().y - a * GetPos().x; // y 절편


		//// 원하는 점의 좌표 구하기.
		//float al;
		//float be;
		//al = prevPos.x - ((2 * a * (a * prevPos.x - prevPos.y + b)) / (a * a + 1));
		//be = prevPos.y - ((2 * (a * prevPos.x - prevPos.y + b) / (a * a + 1)));

		//Vec2 wantPoint = Vec2(al, be);

		//Vec2 wantVec = Vec2(wantPoint.x - GetPos().x, wantPoint.y - GetPos().y);

		//wantVec = wantVec.Normalize();

		////SetPos(Vec2(wantPoint.x, wantPoint.y));

		////m_Movement->SetVelocity();
		//m_Movement->SetVelocity(wantVec);

	

}



