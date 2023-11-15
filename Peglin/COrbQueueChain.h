#pragma once
#include "CObj.h"
class COrbQueueChain :
    public CObj
{
    GENERATED_OBJECT(CObj);

private:
    class CAnimator* m_Animator;

public:
    virtual void begin() override;
    virtual void tick(float _DT) override;


public:
    CLONE(COrbQueueChain);
    COrbQueueChain();
    ~COrbQueueChain();
};

