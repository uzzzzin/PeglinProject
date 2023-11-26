#pragma once
#include "CObj.h"
class COrbInfoUI :
    public CObj
{
    GENERATED_OBJECT(CObj);
private:
    ORB_TYPE curOrbType;

   class  CAnimator* m_Animator;

public:
    void SetOrbType(ORB_TYPE _type)
    {
        curOrbType = _type;
    }
public:
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;

public:
    CLONE(COrbInfoUI);
    COrbInfoUI();
    ~COrbInfoUI();
};

