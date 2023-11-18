#pragma once
#include "CState.h"
class CMonsterAttackState :
    public CState
{
private:
    class CGeneralLevel* m_curLevel;
    class CPeglinPlayer* m_Peglin;
    class CEnemy* m_AttackEnemy;

public:
    virtual void finaltick(float _DT);
    virtual void Enter();
    virtual void Exit();

public:
    CLONE(CMonsterAttackState);
    CMonsterAttackState();
    ~CMonsterAttackState();
};

