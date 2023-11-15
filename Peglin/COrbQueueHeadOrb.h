#pragma once
#include "CObj.h"
class COrbQueueHeadOrb :
    public CObj
{
    GENERATED_OBJECT(CObj);
private:
    class CAnimator* m_Animator;

    ORB_TYPE curOrbType;

public:
    virtual void tick(float _DT) override;

public:
    CLONE(COrbQueueHeadOrb);
    COrbQueueHeadOrb();
    ~COrbQueueHeadOrb();
};

