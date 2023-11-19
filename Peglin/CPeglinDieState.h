#pragma once
#include "CState.h"
class CPeglinDieState :
    public CState
{
private:
    class CPeglinPlayer* m_Peglin;
    class CGeneralLevel* m_curLevel;
public:
    virtual void finaltick(float _DT);
    virtual void Enter();
    virtual void Exit();

public:
    CLONE(CPeglinDieState);

};

