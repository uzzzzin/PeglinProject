#pragma once
#include "CState.h"

class CInitState :
    public CState
{
private:
    class  COrbQueue* m_Queue;

    bool NoneState;

public:
    virtual void finaltick(float _DT);
    virtual void Enter();
    virtual void Exit();

public:
    CLONE(CInitState);
    CInitState();
    ~CInitState();
};

