#pragma once
#include "CState.h"
class CPeglinAttackState :
    public CState
{
private:
    class CGeneralLevel* m_curLevel;
    class CPeglinPlayer* m_Peglin;
    class CEnemy* m_Target;

public:
    virtual void finaltick(float _DT);
    virtual void Enter();
    virtual void Exit();

public:
    CLONE(CPeglinAttackState);
    CPeglinAttackState();
    ~CPeglinAttackState();
};

