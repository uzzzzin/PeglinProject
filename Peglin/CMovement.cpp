#include "pch.h"
#include "CMovement.h"

#include "CObj.h"

CMovement::CMovement(CObj* _Owner)
	: CComponent(_Owner)
	, m_Mass(1.f)
	, m_InitSpeed(0.f)
	, m_MaxSpeed(0.f)
	, m_FrictionScale(0.f)
	, m_UseGravity(0.f)
	, m_Ground(false)
{

}

CMovement::~CMovement()
{

}

void CMovement::finaltick(float _DT)
{
	m_Accel = m_Force / m_Mass;

	// �߷¿ɼ� ����ϴ� ���
	if (m_UseGravity && !m_Ground)
	{
		m_Accel += m_GravityForce;
	}

	// ������ ����� ������ ���
	if (m_Velocity.Length() < 0.1f)
	{
		if (!m_Accel.IsZero())
		{
			Vec2 vAccelDir = m_Accel;
			vAccelDir.Normalize();
			m_Velocity = vAccelDir * m_InitSpeed;
		}
	}
	else
	{
		m_Velocity += m_Accel * _DT;
	}

	// �ִ� �ӵ� ����
	if (fabs(m_Velocity.x) > m_MaxSpeed)
	{
		m_Velocity.x = (m_Velocity.x / abs(m_Velocity.x)) * m_MaxSpeed;
	}

	// ��ü�� ����ǰ��ִ� ���� ������ �������� �����Ų��.
	if (m_Force.IsZero() && m_Velocity.x != 0.f && m_Ground)
	{
		float fFriction = -m_Velocity.x;
		fFriction /= abs(fFriction);

		fFriction *= m_FrictionScale;

		float fFrictionAccel = (fFriction / m_Mass) * _DT;
		if (abs(m_Velocity.x) < abs(fFrictionAccel))
		{
			m_Velocity = Vec2(0.f, m_Velocity.y);
		}
		else
		{
			m_Velocity.x += fFrictionAccel;
		}
	}

	Vec2 vObjPos = GetOwner()->GetPos();
	vObjPos += m_Velocity * _DT;
	GetOwner()->SetPos(vObjPos);

	// �� ����
	m_Force = Vec2(0.f, 0.f);
}