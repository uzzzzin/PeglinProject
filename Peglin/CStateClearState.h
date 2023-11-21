#pragma once
#include "CState.h"
class CStateClearState :
    public CState
{

public:
    virtual void finaltick(float _DT);
    virtual void Enter();
    virtual void Exit();

public:
    CLONE(CStateClearState);
    CStateClearState();
    ~CStateClearState();
};

