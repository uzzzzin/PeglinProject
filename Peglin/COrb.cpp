#include "pch.h"
#include "COrb.h"

#include "CEngine.h"

#include "CLevelMgr.h"
#include "CLevel.h"
#include "CAssetMgr.h"
#include "CKeyMgr.h"
#include "CLogMgr.h"

#include "components.h"
#include "CPeglinPlayer.h"

#include "CInitState.h"
#include "CShootingState.h"
#include "CPeglinAttackState.h"
#include "CMonsterAttackState.h"
#include "CPeglinDieState.h"

COrb::COrb()
	: m_Collider(nullptr)
	, m_Animator(nullptr)
	, m_Movement(nullptr)
	, m_AI(nullptr)
{
	SetName(L"Orb");
	OrbInfo Pebball = { PEBBALL, 2,4,200.f,1.f, 1, L"animdata\\Pebball.txt", L"Pebball"};
	OrbInfo Daggorb = { DAGGORB, 1,7,200.f,1.f, 1, L"animdata\\Daggorb.txt", L"Daggorb"};
	OrbInfo Infernorb = { INFERNORB, 3,5,400.f,1.f, 1, L"animdata\\Infernorb.txt", L"Infernorb"};
	OrbInfo Sphear = { SPHEAR, 2,4,200.f,1.f, 2, L"animdata\\Sphear.txt", L"Sphear"};
	OrbInfo Rubborb = { RUBBORB, 2,4,200.f,0.5f, 1 , L"animdata\\Rubborb.txt", L"Rubborb"};
	orbs.push_back(Pebball);
	orbs.push_back(Daggorb);
	orbs.push_back(Infernorb);
	orbs.push_back(Sphear);
	orbs.push_back(Rubborb);

	m_Animator = AddComponent<CAnimator>(L"OrbAnimator");
	m_Collider = AddComponent<CColliderCircle>(L"OrbCollider");
	m_Movement = AddComponent<CMovement>(L"OrbMovement");

	m_Collider->SetOffsetPos(Vec2(0.f, 0.f));
	m_Collider->SetScale(Vec2(24.f, 24.f));

	SetCurTurnOrb(DAGGORB);


	//m_Animator->LoadAnimation(L"animdata\\Pebball.txt");
	//m_Animator->Play(L"Pebball", true);
	
	//m_Movement->SetMass(1.f);
	//m_Movement->SetInitSpeed(200.f);
	m_Movement->SetMaxSpeed(400.f); 
	m_Movement->SetFrictionScale(1000.f);
	m_Movement->UseGravity(false);
	m_Movement->SetGravity(Vec2(0.f, 980.f));
	m_Movement->SetGround(false);

	m_AI = AddComponent<CStateMachine>(L"AI");
	m_AI->AddState((UINT)STATE_INIT, new CInitState);
	m_AI->AddState((UINT)SHOOTING, new CShootingState);
	m_AI->AddState((UINT)PEGLIN_ATTACK, new CPeglinAttackState);
	m_AI->AddState((UINT)MONSTER_ATTACK, new CMonsterAttackState);
	m_AI->AddState((UINT)PEGLIN_DIE, new CPeglinDieState);
}

COrb::~COrb()
{
}

void COrb::SetCurTurnOrb(ORB_TYPE _type)
{

	if (curOrbType != _type)
	{
		return;
	}

	UINT a = (UINT)_type;
	curOrbType = orbs[a].type;
	curDamage = orbs[a].damage;
	curCritDamage = orbs[a].critDamage;
	curAttackCnt = orbs[a].attackCnt;

	m_Movement->SetInitSpeed(orbs[a].initSpeed);
	m_Movement->SetMass(orbs[a].mass);

	m_Animator->LoadAnimation(orbs[a].animPath);
	m_Animator->Play(orbs[a].animName, true);
}

void COrb::begin()
{
	CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();
	pPlayer = dynamic_cast<CPeglinPlayer*>(pCurLevel->FindObjectByName(L"PeglinPlayer"));
}

void COrb::tick(float _DT)
{
	Super::tick(_DT);

	/*CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();
	CPeglinPlayer* pPlayer = dynamic_cast<CPeglinPlayer*>(pCurLevel->FindObjectByName(L"PeglinPlayer"));*/
	curOrbType = pPlayer->GetCurOrbType();
	SetCurTurnOrb(curOrbType);




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
		//m_AI->ChangeState((UINT)PEGLIN_ATTACK);
		SetPos(REALCENTER);
		m_Movement->SetVelocity({ 0,0 });
		m_Movement->UseGravity(false);
		m_Movement->SetVelocity(Vec2(m_Movement->GetVelocity().x, (m_Movement->GetVelocity().y) * -1));
	}


	if (KEY_TAP(SPACE))
	{
		m_Movement->UseGravity(true);
		m_AI->ChangeState((UINT)SHOOTING);
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
//	// 입사각
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
//	// 반사각
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
//	// 대칭 선분
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

	// 입사각
	FSelectPen redpen(_dc, RED_PEN);

	MoveToEx(_dc, int(m_pPos.x - m_cPos.x) * (300) + m_cPos.x, int(m_pPos.y - m_cPos.y) * (300) + m_cPos.y, nullptr);
	LineTo(_dc, int(m_cPos.x), (int)m_cPos.y);

	Rectangle(_dc, int(m_pPos.x - 3.f)
		, int(m_pPos.y - 3.f)
		, int(m_pPos.x + 3.f)
		, int(m_pPos.y + 3.f));

	// 반사각
	FSelectPen greenpen(_dc, GREEN_PEN);

	MoveToEx(_dc, int(m_rPos.x - m_cPos.x) * 300 + m_cPos.x, int(m_rPos.y - m_cPos.y) * (300) + m_cPos.y, nullptr);
	LineTo(_dc, int(m_cPos.x), (int)m_cPos.y);

	Rectangle(_dc, int(m_cPos.x - 3.f)
		, int(m_cPos.y - 3.f)
		, int(m_cPos.x + 3.f)
		, int(m_cPos.y + 3.f));

	// 대칭 선분
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

		if (false == _OtherCol->GetBOnOff())
			return;
		
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
		
		// 오브 타입별로 알맞는 데미지 가져와서 입히게..
		//pPlayer->AttackDamage = pPlayer->AttackDamage + orbs[UINT(curOrbType)].damage;
		pPlayer->AddAttackDamage(orbs[UINT(curOrbType)].damage);
		LOG(LOGLOG, L"이게 되네");
		if ((_OtherObj->GetName() == L"Obstacle"))
		{
			_OtherCol->SetBOnOff(false);
			pPlayer->AttackDamage -= pPlayer->AttackDamage + orbs[UINT(curOrbType)].damage;
		}


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
