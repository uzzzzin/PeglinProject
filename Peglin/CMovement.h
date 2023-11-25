#pragma once
#include "CComponent.h"
class CMovement :
    public CComponent
{
private:
    // ������ ��
    Vec2    m_Force;

    // ���� ���ӵ�
    Vec2    m_Accel;

    // �ӵ�
    Vec2    m_Velocity;

    // ����
    float   m_Mass;

    // ����� �ʱ� �ӷ�
    float   m_InitSpeed;

    // �ִ� �ӷ�
    float   m_MaxSpeed;

    // ���� ũ��
    float   m_FrictionScale;

    // �߷� ��� On / Off
    bool    m_UseGravity;

    // ����ǰ� �ִ� �߷� ���� �� ����
    Vec2    m_GravityForce;

    // �������� �ƴ���
    bool    m_Ground;


public:
    void AddForce(Vec2 _vForce)
    {
        m_Force += _vForce;
    }

    Vec2 GetForce()
    {
        return m_Force;
    }

    void SetVelocity(Vec2 _vVelocity)
    {
        m_Velocity = _vVelocity;
    }

    void AddVelocity(Vec2 _vAdd)
    {
        m_Velocity += _vAdd;
    }

    Vec2 GetVelocity()
    {
        return m_Velocity;
    }

    void SetMass(float _Mass)
    {
        m_Mass = _Mass;
    }

    float GetMass()
    {
        return m_Mass;
    }

    void SetInitSpeed(float _Speed)
    {
        m_InitSpeed = _Speed;
    }

    void SetMaxSpeed(float _Speed)
    {
        m_MaxSpeed = _Speed;
    }

    //void AddSpeed(float _Speed)
    //{
    //    m_
    //}

    float GetInitSpeed()
    {
        return m_InitSpeed;
    }

    float GetMaxSpeed()
    {
        return m_MaxSpeed;
    }

    void SetFrictionScale(float _F)
    {
        m_FrictionScale = _F;
    }

    float GetFrictionScale()
    {
        return m_FrictionScale;
    }

    void UseGravity(bool _Use)
    {
        m_UseGravity = _Use;
    }

    bool IsUseGravity()
    {
        return m_UseGravity;
    }

    void SetGravity(Vec2 _vGravity)
    {
        m_GravityForce = _vGravity;
    }

    Vec2 GetGravityDir()
    {
        return Vec2(m_GravityForce).Normalize();
    }

    bool IsGround()
    {
        return m_Ground;
    }

    void SetGround(bool _Ground)
    {
        if (_Ground)
        {
            m_Velocity.y = 0.f;
        }

        m_Ground = _Ground;
    }

public:
    virtual void finaltick(float _DT) override;

public:
    CLONE(CMovement);

    CMovement(CObj* _Owner);
    ~CMovement();
};

