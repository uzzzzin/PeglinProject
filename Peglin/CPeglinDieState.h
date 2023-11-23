#pragma once
#include "CState.h"
class CPeglinDieState :
    public CState
{
private:
    class CPeglinPlayer* m_Peglin;
    class CGeneralLevel* m_curLevel;


    float m_Duration_Die;
    float m_AccTime_Die;

    float m_Duration_Last;
    float m_AccTime_Last;

public:
    virtual void finaltick(float _DT);
    virtual void Enter();
    virtual void Exit();

public:
    CLONE(CPeglinDieState);
    CPeglinDieState();
    ~CPeglinDieState();

};

