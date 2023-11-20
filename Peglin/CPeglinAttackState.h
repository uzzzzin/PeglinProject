#pragma once
#include "CState.h"
class CPeglinAttackState :
    public CState
{
private:
    class CGeneralLevel* m_curLevel;
    class CEnemy* m_Target;

    class CAttackProjectile* m_Projectile;

public:
    virtual void finaltick(float _DT);
    virtual void Enter();
    virtual void Exit();

public:
    CLONE(CPeglinAttackState);
    CPeglinAttackState();
    ~CPeglinAttackState();
};

