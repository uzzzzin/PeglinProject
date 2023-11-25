#pragma once
#include "CState.h"
class CPeglinAttackState :
    public CState
{
private:
    class CGeneralLevel* m_curLevel;
    class CEnemy* m_Target;

    class CPeglinPlayer* m_Peglin;
    class COrb* m_Orb;
    class CAttackProjectile* m_Projectile;

    int damage;

    int  attackRange;
public:
    virtual void finaltick(float _DT);
    virtual void Enter();
    virtual void Exit();
    virtual void render(HDC _dc);

public:
    CLONE(CPeglinAttackState);
    CPeglinAttackState();
    ~CPeglinAttackState();
};

