#include "pch.h"
#include "CObstacle.h"

CObstacle::CObstacle()
	:m_Collider(nullptr)
{
	SetName(L"Obstacle");
	m_Collider = AddComponent<CColliderCircle>(L"ObstacleCollider");
	m_Collider->SetScale(Vec2(45.f, 40.f));
	m_Collider->SetOffsetPos(Vec2(0.f, 0.f));
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

//
//float GetAngle(Vec2 _v1, Vec2 _v2)
//{
//	float angle;
//
//	float deltaX = _v2.x - _v1.x;
//	float deltaY = _v2.y - _v1.y;
//
//	float dis = sqrt(deltaX * deltaX + deltaY * deltaY);
//
//	angle = acosf(deltaX / dis);
//
//	if (deltaY > 0)
//	{
//		angle = 3.14 + (3.14 - angle);
//	}
//	return angle;
//}

void CObstacle::BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol)
{
	CMovement* othMove = _OtherObj->GetComponent<CMovement>();
	//float Angg;
	
	//if (_OwnCol->GetType() == ColliderType::CIRCLE)
	//{
	//	LOG(WARNING, L"���͹��Ⱦ�");
	//	//Angg = GetAngle(_OwnCol->GetPos(), _OtherCol->GetPos());

	//	_OtherObj->get






	//}


}

void CObstacle::Overlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol)
{


}

// ==============================================================================================









//CMovement* othMove = _OtherObj->GetComponent<CMovement>();

	//Vec2 velo = othMove->GetVelocity();
	//Vec2 Dir = _OtherObj->GetPos() - GetPos();
	//Dir.Normalize();


	//float len = (_OwnCol->GetScale().x + _OtherCol->GetScale().x) / 2;
	//
	//_OtherObj->SetPos(GetPos() + Dir * (len + 1 ));


	//Vec2 _otherColPos = _OtherCol->GetPos(); // �÷��̾� �ݶ��̴� ������
	//Vec2 _otherPrevColPos = _OtherCol->GetPrevColPos(); // �÷��̾� prev �ݶ��̴� ������

	//Vec2 _otherCur = Vec2(_otherPrevColPos.x - _otherColPos.x, _otherPrevColPos.y - _otherColPos.y);

	//float a = (_OwnCol->GetPos().y - _OtherCol->GetPos().y) / (_OwnCol->GetPos().x - _OtherCol->GetPos().x); // ������ ����
	//float b = _OtherCol->GetPos().y - a * _OwnCol->GetPos().x; // y ����

	//float al; // ������ ���� ������ �������� ��Ī��ų ��ǥ�� x
	//float be; // ������ ���� ������ �������� ��Ī��ų ��ǥ�� y

	//// ���� ��ġ���� ��Ī���� ���� ��ġ�� ���� ������ ���� * ������ ���� ������ ���� = -1 ���� �̿� (�����̶�)
	////al = _otherPrevColPos.x - ((2 * a * (a * _otherPrevColPos.x - _otherPrevColPos.y + b)) / (a * a + 1)); 
	////be = _otherPrevColPos.y + ((2 * (a * _otherPrevColPos.x - _otherPrevColPos.y + b) / (a * a + 1)));

	//al = _otherColPos.x - ((2 * a * (a * _otherColPos.x - _otherColPos.y + b)) / (a * a + 1));
	//be = _otherColPos.y + ((2 * (a * _otherColPos.x - _otherColPos.y + b) / (a * a + 1)));

	//Vec2 wantPoint = Vec2(al, be);

	//Vec2 wantVec = Vec2(wantPoint.x - _otherColPos.x, wantPoint.y - _otherColPos.y);

	//wantVec = wantVec.Normalize();

	//Vec2 othPos = _OtherObj->GetPos();

	////othMove->SetVelocity(wantVec);
	//_OtherObj->SetPos(wantPoint);
	//othMove->SetVelocity(Vec2(othMove->GetVelocity().x * wantVec.x, (othMove->GetVelocity().y) * wantVec.y));


	//m_Movement->SetVelocity(Vec2(m_Movement->GetVelocity().x, (m_Movement->GetVelocity().y) * -1));






//Vec2 cPos = _OtherCol->GetPos();
//Vec2 pPos = _OtherCol->GetPrevColPos();
//Vec2 vPos = _OwnCol->GetPos();

//Vec2 ins = pPos - cPos;
//Vec2 ctoc = vPos - cPos;

//Vec2 refld = ins +  ctoc   *2 *  rightshadow(( (ins)*(-1)), ctoc);


























//��ȣ start
//Vec2 vInsertDir = cPos - pPos;
//vInsertDir.Normalize();

//Vec2 vReflect = vPos - cPos;
//vReflect.Normalize();

//float fDot = vInsertDir.x * vReflect.x + vInsertDir.y * vReflect.y;

//float fAngle = acosf(fDot);

//if (fAngle > PI / 90.f)
//{
//	// Ÿ���� ���ؼ� ������ ȸ���Ѵ�.
//	if (GetRotateClock(vInsertDir, vReflect))
//	{
//		vInsertDir = Rotate(vInsertDir, fAngle);
//	}
//	else
//	{
//		vInsertDir = Rotate(vInsertDir, -fAngle);
//	}
//}
//��ȣ end

//Vec2 vVel = othMove->GetVelocity();
//refld.Normalize();
//othMove->SetVelocity({ vVel.x * refld.x, abs(vVel.y) * refld.y });


////al = _otherPrevColPos.x - ((2 * a * (a * _otherPrevColPos.x - _otherPrevColPos.y + b)) / (a * a + 1));
////be = _otherPrevColPos.y + ((2 * (a * _otherPrevColPos.x - _otherPrevColPos.y + b) / (a * a + 1)));



	// ==============================================================================
	//CMovement* othMove = _OtherObj->GetComponent<CMovement>();


	//Vec2 _otherColPos = _OtherCol->GetPos(); // �÷��̾� �ݶ��̴� ������
	//Vec2 _otherPrevColPos = _OtherCol->GetPrevColPos(); // �÷��̾� prev �ݶ��̴� ������

	//float a = (_OwnCol->GetPos().y - _OtherCol->GetPos().y) / (_OwnCol->GetPos().x - _OtherCol->GetPos().x);
	//float b = _OtherCol->GetPos().y - a * _OtherCol->GetPos().x;

	//float al;
	//float be;

	////al = _otherPrevColPos.x - ((2 * a * (a * _otherPrevColPos.x - _otherPrevColPos.y + b)) / (a * a + 1));
	////be = _otherPrevColPos.y + ((2 * (a * _otherPrevColPos.x - _otherPrevColPos.y + b) / (a * a + 1)));

	//al = _otherColPos.x - ((2 * a * (a * _otherColPos.x - _otherColPos.y + b)) / (a * a + 1));
	//be = _otherColPos.y + ((2 * (a * _otherColPos.x - _otherColPos.y + b) / (a * a + 1)));

	//Vec2 wantPoint = Vec2(al, be);

	//Vec2 wantVec = wantPoint - _otherColPos;
	//wantVec = wantVec.Normalize();
	//Vec2 vel = othMove->GetVelocity();


	// //_OtherObj->SetPos(wantPoint)
	//othMove->SetVelocity(Vec2(abs(othMove->GetVelocity().x) * wantVec.x,   abs(othMove->GetVelocity().y) * wantVec.y));
	////othMove->SetVelocity(Vec2((othMove->GetVelocity().x) * wantVec.x,   (othMove->GetVelocity().y) * wantVec.y));

	// ==============================================================================


//CMovement* othMove = _OtherObj->GetComponent<CMovement>();
//
//
//Vec2 _otherColPos = _OtherCol->GetPos(); // �÷��̾� �ݶ��̴� ������
//Vec2 _otherPrevColPos = _OtherCol->GetPrevColPos(); // �÷��̾� prev �ݶ��̴� ������
//
//float a = (_OwnCol->GetPos().y - _OtherCol->GetPos().y) / (_OwnCol->GetPos().x - _OtherCol->GetPos().x);
//// ������ ����
//float b = _OtherCol->GetPos().y - a * _OwnCol->GetPos().x;
//
//float al;
//float be;
////al = _otherPrevColPos.x - ((2 * a * (a * _otherPrevColPos.x - _otherPrevColPos.y + b)) / (a * a + 1));
////be = _otherPrevColPos.y - ((2 * (a * _otherPrevColPos.x - _otherPrevColPos.y + b) / (a * a + 1)));
//
//al = _otherColPos.x - ((2 * a * (a * _otherColPos.x - _otherColPos.y + b)) / (a * a + 1));
//be = _otherColPos.y - ((2 * (a * _otherColPos.x - _otherColPos.y + b) / (a * a + 1)));
//
//Vec2 wantPoint = Vec2(al, be);
//
//Vec2 wantVec = Vec2(wantPoint.x - _otherColPos.x, wantPoint.y - _otherColPos.y);
//wantVec = wantVec.Normalize();
//
//
//_OtherObj->SetPos(wantPoint);
//othMove->SetVelocity(wantVec);
//































	// --------------------------------------------------------------------------
	//Vec2 _otherColPos = _OtherCol->GetPos();
	//Vec2 _otherPrevColPos = _OtherCol->GetPrevColPos();

	//float a = (_OwnCol->GetPos().x - _OtherCol->GetPos().x) / (_OwnCol->GetPos().y - _OtherCol->GetPos().y);
	//float b = _OtherCol->GetPos().y - a * _OwnCol->GetPos().x;

	//float al;
	//float be;
	//al = _otherPrevColPos.x - ((2 * a * (a * _otherPrevColPos.x - _otherPrevColPos.y + b)) / (a * a + 1));
	//be = _otherPrevColPos.y - ((2 * (a * _otherPrevColPos.x - _otherPrevColPos.y + b) / (a * a + 1)));

	//Vec2 wantPoint = Vec2(al, be);

	//Vec2 wantVec = Vec2(wantPoint.x - _otherColPos.x, wantPoint.y - _otherColPos.y);
	//wantVec = wantVec.Normalize();

	//othMove->SetVelocity(wantVec);


	// -------------------------------------------
	//othMove->SetVelocity();


	//// ������ ������
	//Vec2 _otherPos = _OtherCol->GetPos(); // �÷��̾��� 
	//float a = (_otherPos.x - GetPos().x) / (_otherPos.y - GetPos().y); // ����
	//float b = GetPos().y - a * GetPos().x; // y ����


	//// ���ϴ� ���� ��ǥ ���ϱ�.
	//float al;
	//float be;
	//al = prevPos.x - ((2 * a * (a * prevPos.x - prevPos.y + b)) / (a * a + 1));
	//be = prevPos.y - ((2 * (a * prevPos.x - prevPos.y + b) / (a * a + 1)));

	//Vec2 wantPoint = Vec2(al, be);

	//Vec2 wantVec = Vec2(wantPoint.x - GetPos().x, wantPoint.y - GetPos().y);

	//wantVec = wantVec.Normalize();

	//SetPos(Vec2(wantPoint.x, wantPoint.y));



	// ------------------------------------------------------------------------------
	//CMovement* othMove = _OtherObj->GetComponent<CMovement>();

	//othMove->SetVelocity(Vec2((othMove->GetVelocity().x * -1), othMove->GetVelocity().y));
	//othMove->SetVelocity(Vec2(othMove->GetVelocity().x, (othMove->GetVelocity().y) * -1));
	// -------------------------------------------------------------------------------





// -------------------------------------------------

//CMovement* othMove = _OtherObj->GetComponent<CMovement>();


//Vec2 _otherColPos = _OtherCol->GetPos(); // �÷��̾� �ݶ��̴� ������
//Vec2 _otherPrevColPos = _OtherCol->GetPrevColPos(); // �÷��̾� prev �ݶ��̴� ������

//float a = (_OwnCol->GetPos().y - _OtherCol->GetPos().y) / (_OwnCol->GetPos().x - _OtherCol->GetPos().x);
//// ������ ����
//float b = _OtherCol->GetPos().y - a * _OwnCol->GetPos().x;

//float al;
//float be;
//al = _otherPrevColPos.x - ((2 * a * (a * _otherPrevColPos.x - _otherPrevColPos.y + b)) / (a * a + 1));
//be = _otherPrevColPos.y - ((2 * (a * _otherPrevColPos.x - _otherPrevColPos.y + b) / (a * a + 1)));

//Vec2 wantPoint = Vec2(al, be);

//Vec2 wantVec = Vec2(wantPoint.x - _otherColPos.x, wantPoint.y - _otherColPos.y);
//wantVec = wantVec.Normalize();

//othMove->SetVelocity(wantVec);


//CMovement* othMove = _OtherObj->GetComponent<CMovement>();


//Vec2 _otherColPos = _OtherCol->GetPos(); // �÷��̾� �ݶ��̴� ������
//Vec2 _otherPrevColPos = _OtherCol->GetPrevColPos(); // �÷��̾� prev �ݶ��̴� ������

//float a = (_OwnCol->GetPos().y - _OtherCol->GetPos().y) / (_OwnCol->GetPos().x - _OtherCol->GetPos().x);
//// ������ ����
//float b = _OtherCol->GetPos().y - a * _OwnCol->GetPos().x;

//float al;
//float be;
////al = _otherPrevColPos.x - ((2 * a * (a * _otherPrevColPos.x - _otherPrevColPos.y + b)) / (a * a + 1));
////be = _otherPrevColPos.y - ((2 * (a * _otherPrevColPos.x - _otherPrevColPos.y + b) / (a * a + 1)));

//al = _otherColPos.x - ((2 * a * (a * _otherColPos.x - _otherColPos.y + b)) / (a * a + 1));
//be = _otherColPos.y - ((2 * (a * _otherColPos.x - _otherColPos.y + b) / (a * a + 1)));

//Vec2 wantPoint = Vec2(al, be);

//Vec2 wantVec = Vec2(wantPoint.x - _otherColPos.x, wantPoint.y - _otherColPos.y);
//wantVec = wantVec.Normalize();


//_OtherObj->SetPos(wantPoint);
//othMove->SetVelocity(wantVec);



