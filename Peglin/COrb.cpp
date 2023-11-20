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
	, curOrbType(ORB_TYPE_END)
	//, m_AI(nullptr)
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

	hitOrbs.push_back(make_pair(GREY_PEG, 0 ));
	hitOrbs.push_back(make_pair(COIN_PEG, 0));
	hitOrbs.push_back(make_pair(CRITICAL_PEG, 0));
	hitOrbs.push_back(make_pair(REFRESH_PEG, 0));
	hitOrbs.push_back(make_pair(BOMB_PEG, 0));



	m_Animator = AddComponent<CAnimator>(L"OrbAnimator");
	m_Collider = AddComponent<CColliderCircle>(L"OrbCollider");
	m_Movement = AddComponent<CMovement>(L"OrbMovement");

	m_Collider->SetOffsetPos(Vec2(0.f, 0.f));
	m_Collider->SetScale(Vec2(24.f, 24.f));


	//m_Animator->LoadAnimation(L"animdata\\Pebball.txt");
	//m_Animator->Play(L"Pebball", true);
	
	//m_Movement->SetMass(1.f);
	//m_Movement->SetInitSpeed(200.f);
	m_Movement->SetMaxSpeed(400.f); 
	m_Movement->SetFrictionScale(1000.f);
	m_Movement->UseGravity(false);
	m_Movement->SetGravity(Vec2(0.f, 980.f));
	m_Movement->SetGround(false);

	/*m_AI = AddComponent<CStateMachine>(L"AI");
	m_AI->AddState((UINT)STATE_INIT, new CInitState);
	m_AI->AddState((UINT)SHOOTING, new CShootingState);
	m_AI->AddState((UINT)PEGLIN_ATTACK, new CPeglinAttackState);
	m_AI->AddState((UINT)MONSTER_ATTACK, new CMonsterAttackState);
	m_AI->AddState((UINT)PEGLIN_DIE, new CPeglinDieState);*/
}

COrb::~COrb()
{
}

void COrb::SetCurTurnOrb(ORB_TYPE _type)
{

	if (curOrbType == _type) // 지금 오브 옷이 나중 오브와 같다면
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
	SetCurTurnOrb(dynamic_cast<CPeglinPlayer*>(pCurLevel->FindObjectByName(L"PeglinPlayer"))->myOrbs[0]); //이거 오브말고 스테이트에서 해야 함
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
		//m_AI->ChangeState((UINT)PEGLIN_ATTACK);
		SetPos(REALCENTER);
		m_Movement->SetVelocity({ 0,0 });
		m_Movement->UseGravity(false);
		m_Movement->SetVelocity(Vec2(m_Movement->GetVelocity().x, (m_Movement->GetVelocity().y) * -1));
	}


	if (KEY_TAP(SPACE))
	{
		m_Movement->UseGravity(true);
		//pPlayer->m_AI->ChangeState((UINT)SHOOTING); // BeforeShooting 으로 가라
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
		m_Movement->SetVelocity(Vec2((m_Movement->GetVelocity().x * -1), m_Movement->GetVelocity().y));
		return;
	}
	if (GetRBoundaryX() <= curPos.x)
	{
		curPos.x = GetRBoundaryX();
		m_Movement->SetVelocity(Vec2((m_Movement->GetVelocity().x * -1), m_Movement->GetVelocity().y));
		return;
	}
	if (GetUBoundaryY() >= curPos.y)
	{
		curPos.y = GetUBoundaryY();
		m_Movement->SetVelocity(Vec2(m_Movement->GetVelocity().x, (m_Movement->GetVelocity().y) * -1));
		return;
	}
	if (GetDBoundaryY() <= curPos.y)
	{
		curPos.y = GetDBoundaryY();
		m_Movement->SetVelocity(Vec2(m_Movement->GetVelocity().x, (m_Movement->GetVelocity().y) * -1));
		return;
	}
	if (_OtherCol->GetPos().x - _OwnCol->GetPos().x != 0 && _OtherCol->GetPos().y - _OwnCol->GetPos().y != 0)
	{ // 일반적인 충돌인 상황
		m_pPos = _OwnCol->GetPrevColPos();
		m_cPos = _OwnCol->GetPos();
		m_colPos = _OtherCol->GetPos();

		if (false == _OtherCol->GetBOnOff())
			return;
		
		auto movement = GetComponent<CMovement>();

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

		if (!(_OtherObj->GetName() == L"Obstacle")) // 정상적인 페그에 부딪힘
		{
			//LOG(LOGLOG, L"Obstacle에 부딪힌 게 아님.");
			_OtherCol->SetBOnOff(false);

			if (L"GreyPeg" == _OtherObj->GetName())
			{
				++(hitOrbs[0].second);
			}
			else if (L"CoinPeg" == _OtherObj->GetName())
			{
				++(hitOrbs[1].second);
			}
			else if (L"CritPeg" == _OtherObj->GetName())
			{
				++(hitOrbs[2].second);
			}
			else if (L"RefreshPeg" == _OtherObj->GetName())
			{
				++(hitOrbs[3].second);
			}
			else if (L"BombPeg" == _OtherObj->GetName())
			{
				++(hitOrbs[4].second);
			}
			else
			{
				LOG(ERR, L"페그 데미지 이상한 게 들어왔는데? 사곤데?");
			}
			//pPlayer->AddAttackDamage(orbs[UINT(curOrbType)].damage);
		}

		if ((_OtherObj->GetName() == L"Obstacle"))
		{
			//pPlayer->AttackDamage -= pPlayer->AttackDamage + orbs[UINT(curOrbType)].damage;
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
