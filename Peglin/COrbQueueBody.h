#pragma once
#include "CObj.h"
class COrbQueueBody :
    public CObj
{
    GENERATED_OBJECT(CObj);
 
private:
    class CAnimator* m_Animator;

public:
    virtual void begin() override;
    virtual void tick(float _DT) override;

public:
    CLONE(COrbQueueBody);
    COrbQueueBody();
    ~COrbQueueBody();
};

