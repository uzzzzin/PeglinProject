#pragma once
#include "CObj.h"
class COrbQueue :
    public CObj
{
    GENERATED_OBJECT(CObj);

protected:
    class CAnimator* m_Animator;
    class CMovement* m_Movement;
   // class CStateMachine* m_AI;

private:
    class COrbQueueHead* QueueHead;
    class COrbQueueBody* QueueBody;

public:
    ORB_TYPE curOrb;
    int curOrbIdx;
    vector<ORB_TYPE> nextOrbs;

    vector<class COrbQueueBodyOrbCase*> OrbCases;
    vector<class COrbQueueChain*> OrbChains;
    vector<class CImg*> OrbImgs;

public:
    virtual void begin() override;
    virtual void tick(float _DT) override;
    //virtual void render(HDC DC) override;

public:
    CLONE(COrbQueue);
    COrbQueue();
    ~COrbQueue();
};

