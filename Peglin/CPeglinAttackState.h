#pragma once
#include "CState.h"
class CPeglinAttackState :
    public CState
{
private:
    class CEnemy* m_Target;

public:
    virtual void finaltick(float _DT);
    virtual void Enter();
    virtual void Exit();

   // CEnemy* FindTarget();

public:
    CLONE(CPeglinAttackState);
    CPeglinAttackState();
    ~CPeglinAttackState();
};

