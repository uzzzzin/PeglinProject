#pragma once
#include "CState.h"
class CShootingState :
    public CState
{

private:
    class COrb* m_Orb;



public:
    virtual void finaltick(float _DT);
    virtual void Enter();
    virtual void Exit();

public:
    CLONE(CShootingState);
    CShootingState();
    ~CShootingState();
};

