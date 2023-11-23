#pragma once
#include "CState.h"
class CShootingState :
    public CState
{
private:
    class COrb* m_Orb;
    vector<OrbInfo> info;

    class CPeglinPlayer* pPeglin;

    int prevDamage = 0;

public:
    virtual void finaltick(float _DT);
    virtual void Enter();
    virtual void Exit();
    virtual void render(HDC _dc);

public:
    CLONE(CShootingState);
    CShootingState();
    ~CShootingState();
};

