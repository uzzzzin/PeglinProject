#pragma once
#include "CState.h"

class CInitState :
    public CState
{
private:
    class CPeglinPlayer* m_Peglin;
    class CGeneralLevel* m_curLevel;

    class  COrbQueue* m_Queue;
    class COrbQueueHeadOrb* m_HeadOrb;
    class COrb* m_Orb;



    //vector<std::pair<class CEnemy*, int>> EnemysInLevel;

    bool bRealInit = false; // 진짜 맨첨인지만 알려주는

public:
    virtual void finaltick(float _DT);
    virtual void Enter();
    virtual void Exit();

public:
    CLONE(CInitState);
    CInitState();
    ~CInitState();
};

