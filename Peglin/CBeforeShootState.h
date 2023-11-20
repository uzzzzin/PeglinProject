#pragma once
#include "CState.h"

class CBeforeShootState :
    public CState
{
private:
   //class  CPeglinPlayer* m_Peglin;
   // class COrb* m_Orb;

public:
    virtual void finaltick(float _DT);
    virtual void Enter();
    virtual void Exit();

public:
    CLONE(CBeforeShootState);
    CBeforeShootState();
    ~CBeforeShootState();

};

