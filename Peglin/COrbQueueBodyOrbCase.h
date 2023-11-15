#pragma once
#include "CObj.h"
class COrbQueueBodyOrbCase :
    public CObj
{
    GENERATED_OBJECT(CObj);

private:
    class CAnimator* m_Animator;

public:
    virtual void begin() override;
    virtual void tick(float _DT) override;

public:
    CLONE(COrbQueueBodyOrbCase);
    COrbQueueBodyOrbCase();
    ~COrbQueueBodyOrbCase();
};

