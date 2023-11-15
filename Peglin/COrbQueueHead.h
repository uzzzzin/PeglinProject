#pragma once
#include "CObj.h"
class COrbQueueHead :
    public CObj
{
    GENERATED_OBJECT(CObj);

private:
    class CAnimator* m_Animator;
    class CAnimator* m_OrbAnimator;

public:
    virtual void begin() override;
    virtual void tick(float _DT) override;
    //virtual void render(HDC _dc) override;

public:
    CLONE(COrbQueueHead);
    COrbQueueHead();
    ~COrbQueueHead();
};

