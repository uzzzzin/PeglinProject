#include "pch.h"
#include "COrb.h"

#include "CEngine.h"

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

	// �浹ü ������Ʈ �߰�
	m_Collider = AddComponent<CColliderCircle>(L"OrbCollider");
	m_Collider->SetOffsetPos(Vec2(0.f, 0.f));
	m_Collider->SetScale(Vec2(24.f, 24.f));

	// Movement ������Ʈ �߰�
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
	else if (GetRBoundaryX() < curPos.x)
	{
		//	LOG(ERR, L"RIGHT holy....");
		m_Movement->SetVelocity(Vec2((m_Movement->GetVelocity().x * -1), m_Movement->GetVelocity().y));
	}
	else if (GetUBoundaryY() > curPos.y)
	{
		//	LOG(ERR, L"UP holy....");
		m_Movement->SetVelocity(Vec2(m_Movement->GetVelocity().x, (m_Movement->GetVelocity().y) * -1));
	}
	else if (GetDBoundaryY() < curPos.y)
	{
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

//void COrb::render(HDC _dc)
//{
//	Super::render(_dc);
//
//	if (!DEBUG_RENDER)
//		return;
//
//	// �Ի簢
//	FSelectPen redpen(_dc, RED_PEN);
//
//	MoveToEx(_dc, int(prevPos.x - curPos.x) * (300) + curPos.x, int(prevPos.y - curPos.y) * (300) + curPos.y, nullptr);
//	LineTo(_dc, int(curPos.x), (int)curPos.y);
//
//	Rectangle(_dc, int(prevPos.x - 3.f)
//		, int(prevPos.y - 3.f)
//		, int(prevPos.x + 3.f)
//		, int(prevPos.y + 3.f));
//
//	// �ݻ簢
//	FSelectPen greenpen(_dc, GREEN_PEN);
//
//	MoveToEx(_dc, int(rPos.x - curPos.x) * 300 + curPos.x, int(rPos.y - curPos.y) * (300) + curPos.y, nullptr);
//	LineTo(_dc, int(curPos.x), (int)curPos.y);
//
//	Rectangle(_dc, int(curPos.x - 3.f)
//		, int(curPos.y - 3.f)
//		, int(curPos.x + 3.f)
//		, int(curPos.y + 3.f));
//
//	// ��Ī ����
//	FSelectPen bluepen(_dc, BLUE_PEN);
//	MoveToEx(_dc, int(rPos.x - colPos.x) * 300 + colPos.x, int(rPos.y - colPos.y) * (300) + colPos.y, nullptr);
//	LineTo(_dc, int(colPos.x), (int)colPos.y);
//
//	Rectangle(_dc, int(colPos.x - 3.f)
//		, int(colPos.y - 3.f)
//		, int(colPos.x + 3.f)
//		, int(colPos.y + 3.f));
//}

//void COrb::render(HDC _dc)
void COrb::render(HDC _dc)
{
	Super::render(_dc);


	if (!DEBUG_RENDER)
		return;

	// �Ի簢
	FSelectPen redpen(_dc, RED_PEN);

	MoveToEx(_dc, int(m_pPos.x - m_cPos.x) * (300) + m_cPos.x, int(m_pPos.y - m_cPos.y) * (300) + m_cPos.y, nullptr);
	LineTo(_dc, int(m_cPos.x), (int)m_cPos.y);

	Rectangle(_dc, int(m_pPos.x - 3.f)
		, int(m_pPos.y - 3.f)
		, int(m_pPos.x + 3.f)
		, int(m_pPos.y + 3.f));

	// �ݻ簢
	FSelectPen greenpen(_dc, GREEN_PEN);

	MoveToEx(_dc, int(m_rPos.x - m_cPos.x) * 300 + m_cPos.x, int(m_rPos.y - m_cPos.y) * (300) + m_cPos.y, nullptr);
	LineTo(_dc, int(m_cPos.x), (int)m_cPos.y);

	Rectangle(_dc, int(m_cPos.x - 3.f)
		, int(m_cPos.y - 3.f)
		, int(m_cPos.x + 3.f)
		, int(m_cPos.y + 3.f));

	// ��Ī ����
	FSelectPen bluepen(_dc, BLUE_PEN);
	MoveToEx(_dc, int(m_rPos.x - m_colPos.x) * 300 + m_colPos.x, int(m_rPos.y - m_colPos.y) * (300) + m_colPos.y, nullptr);
	LineTo(_dc, int(m_colPos.x), (int)m_colPos.y);

	Rectangle(_dc, int(m_colPos.x - 3.f)
		, int(m_colPos.y - 3.f)
		, int(m_colPos.x + 3.f)
		, int(m_colPos.y + 3.f));
}


void COrb::BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol)
{
	// collision wall
	if (GetLBoundaryX() >= curPos.x)
	{
		curPos.x = GetLBoundaryX();
		//SetPos(Vec2(curPos.x, curPos.y));
		m_Movement->SetVelocity(Vec2((m_Movement->GetVelocity().x * -1), m_Movement->GetVelocity().y));
		return;
	}
	if (GetRBoundaryX() <= curPos.x)
	{
		curPos.x = GetRBoundaryX();
		//SetPos(Vec2(curPos.x, curPos.y));
		m_Movement->SetVelocity(Vec2((m_Movement->GetVelocity().x * -1), m_Movement->GetVelocity().y));
		return;
	}
	if (GetUBoundaryY() >= curPos.y)
	{
		curPos.y = GetUBoundaryY();
		//SetPos(Vec2(curPos.x, curPos.y));
		m_Movement->SetVelocity(Vec2(m_Movement->GetVelocity().x, (m_Movement->GetVelocity().y) * -1));
		return;
	}
	if (GetDBoundaryY() <= curPos.y)
	{
		curPos.y = GetDBoundaryY();
		//SetPos(Vec2(curPos.x, curPos.y));
		m_Movement->SetVelocity(Vec2(m_Movement->GetVelocity().x, (m_Movement->GetVelocity().y) * -1));
		return;
	}
	if (_OtherCol->GetPos().x - _OwnCol->GetPos().x != 0 && _OtherCol->GetPos().y - _OwnCol->GetPos().y != 0)
	{
		m_pPos = _OwnCol->GetPrevColPos();
		m_cPos = _OwnCol->GetPos();
		m_colPos = _OtherCol->GetPos();

		auto movement = GetComponent<CMovement>();

		
		//if (_OtherCol->GetPos().x - _OwnCol->GetPos().x == 0) 
		//{
		//	movement->SetVelocity({ -vel.x, -vel.y });
		//	return;
		//}

		float a = (_OtherCol->GetPos().y - _OwnCol->GetPos().y) / (_OtherCol->GetPos().x - _OwnCol->GetPos().x);
		float b = _OwnCol->GetPos().y - a * _OwnCol->GetPos().x;

		


		m_rPos.x = m_pPos.x - ((2 * a * (a * m_pPos.x - m_pPos.y + b)) / (a * a + 1));
		m_rPos.y = m_pPos.y + ((2 * (a * m_pPos.x - m_pPos.y + b) / (a * a + 1)));

		Vec2 vel = movement->GetVelocity();
		Vec2 vReflect = m_rPos - m_cPos;
		float speed = vel.Length();

		vReflect.Normalize();
		movement->SetVelocity({ vReflect.x * speed, vReflect.y * speed });
	}
	else if (_OtherCol->GetPos().x - _OwnCol->GetPos().x == 0 && (_OtherCol->GetPos().y - _OwnCol->GetPos().y != 0))
	{
	m_Movement->SetVelocity(Vec2((m_Movement->GetVelocity().x ), m_Movement->GetVelocity().y*-1));
	}
	else if (_OtherCol->GetPos().y - _OwnCol->GetPos().y == 0 && _OtherCol->GetPos().x - _OwnCol->GetPos().x != 0)
	{
		m_Movement->SetVelocity(Vec2(m_Movement->GetVelocity().x*-1, (m_Movement->GetVelocity().y)) );
	}
	else if (_OtherCol->GetPos().y - _OwnCol->GetPos().y == 0 && _OtherCol->GetPos().x - _OwnCol->GetPos().x == 0)
	{
		m_Movement->SetVelocity(Vec2(m_Movement->GetVelocity().x*( -1), (m_Movement->GetVelocity().y) * -1));
	}
	else
	{
		LOG(ERR, L"?????????");
	}

}
//void COrb::BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol)
////void COrb::BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol)
//{
//	if (_OtherCol->GetType() == ColliderType::CIRCLE)
//	{
//		prevPos = _OwnCol->GetPrevColPos();
//		curPos = _OwnCol->GetPos();
//		colPos = _OtherCol->GetPos();
//
//		auto movement = GetComponent<CMovement>();
//
//		Vec2 vel = movement->GetVelocity();
//		Vec2 vReflect = rPos - curPos;
//		float speed = vel.Length();
//
//		//if (_OtherCol->GetPos().x - _OwnCol->GetPos().x == 0) 
//		//{
//		//	movement->SetVelocity({ -vel.x, -vel.y });
//		//	return;
//		//}
//
//		float a = (_OtherCol->GetPos().y - _OwnCol->GetPos().y) / (_OtherCol->GetPos().x - _OwnCol->GetPos().x);
//		float b = _OwnCol->GetPos().y - a * _OwnCol->GetPos().x;
//
//		rPos.x = prevPos.x - ((2 * a * (a * prevPos.x - prevPos.y + b)) / (a * a + 1));
//		rPos.y = prevPos.y + ((2 * (a * prevPos.x - prevPos.y + b) / (a * a + 1)));
//
//		vReflect.Normalize();
//		movement->SetVelocity({ vReflect.x * speed, vReflect.y * speed });
//
//	}
//	else
//	{
//		if (GetLBoundaryX() > curPos.x)
//		{
//			curPos.x = GetLBoundaryX();
//			SetPos(Vec2(curPos.x, curPos.y));
//		}
//		if (GetRBoundaryX() < curPos.x)
//		{
//			curPos.x = GetRBoundaryX();
//			SetPos(Vec2(curPos.x, curPos.y));
//		}
//		if (GetUBoundaryY() > curPos.y)
//		{
//			curPos.y = GetUBoundaryY();
//			SetPos(Vec2(curPos.x, curPos.y));
//		}
//		if (GetDBoundaryY() < curPos.y)
//		{
//			curPos.y = GetDBoundaryY();
//			SetPos(Vec2(curPos.x, curPos.y));
//		}
//	}
//}
// 
// 
// 
// 
// 
// 
//{
//	Vec2 PushVec;
//
//	if (_OtherCol->GetType() == ColliderType::CIRCLE)
//	{
//		//Vec2 vColVec = _OtherObj->GetPos() - GetPos();
//
//		//vColVec = Rotate(vColVec, PI / 90.f);
//
//
//		//float fDot = vColVec.x * vDir.x + vColVec.y * vDir.y;
//		//float fAngle = acosf(fDot);
//
//		////if (fAngle > PI/90.f)
//		////{
//		////	LOG(LOGLOG, L"ss");
//		//if (vColVec.y > 0)
//		//{
//		//	vDir = Rotate(vColVec, PI - 2 * fAngle);
//		//}
//		//else
//		//{
//		//	vDir = Rotate(vColVec, (-1)*(PI - 2 * fAngle));
//		//}
//
//		//}
//		//else
//		//{
//		//	LOG(ERR, L"dd");
//		//	vDir = Rotate(vColVec, PI - 2 * fAngle + fAngle);
//		//}
//		
//
//		//SetPos();
//		m_Movement->SetVelocity(Vec2(abs(m_Movement->GetVelocity().x), abs(m_Movement->GetVelocity().y) )* vDir);
//	}
//	else
//	{
//		if (GetLBoundaryX() > curPos.x)
//		{
//			curPos.x = GetLBoundaryX();
//			SetPos(Vec2(curPos.x, curPos.y));
//		}
//		if (GetRBoundaryX() < curPos.x)
//		{
//			curPos.x = GetRBoundaryX();
//			SetPos(Vec2(curPos.x, curPos.y));
//		}
//		if (GetUBoundaryY() > curPos.y)
//		{
//			curPos.y = GetUBoundaryY();
//			SetPos(Vec2(curPos.x, curPos.y));
//		}
//		if (GetDBoundaryY() < curPos.y)
//		{
//			curPos.y = GetDBoundaryY();
//			SetPos(Vec2(curPos.x, curPos.y));
//		}
//	}
//
//}

void COrb::Overlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol)
{
	//if (_OtherCol->GetType() == ColliderType::CIRCLE)
	//{
		//Vec2 vel = m_Movement->GetVelocity();
		//m_Movement->SetVelocity(vel);
	//}
	//else
	//{
		//if (GetLBoundaryX() > curPos.x)
		//{
		//	curPos.x = GetLBoundaryX();
		//	SetPos(Vec2(curPos.x, curPos.y));
		//}
		//if (GetRBoundaryX() < curPos.x)
		//{
		//	curPos.x = GetRBoundaryX();
		//	SetPos(Vec2(curPos.x, curPos.y));
		//}
		//if (GetUBoundaryY() > curPos.y)
		//{
		//	curPos.y = GetUBoundaryY();
		//	SetPos(Vec2(curPos.x, curPos.y));
		//}
		//if (GetDBoundaryY() < curPos.y)
		//{
		//	curPos.y = GetDBoundaryY();
		//	SetPos(Vec2(curPos.x, curPos.y));
		//}
	//	}
	//}

}