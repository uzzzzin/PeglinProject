#pragma once
#include "CState.h"

class CInitState :
    public CState
{
private:
    class CGeneralLevel* m_curLevel;
    class  COrbQueue* m_Queue;
    vector<std::pair<class CEnemy*, int>> EnemysInLevel;

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

