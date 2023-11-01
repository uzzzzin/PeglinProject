#pragma once
#include "CObj.h"
class CStartLogo :
    public CObj
{
    GENERATED_OBJECT(CObj);

private:
    CTexture*         m_Texture;
    CAnimator*      m_Animator;

public:
    virtual void begin() override;
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;

public:
    CLONE(CStartLogo);
    CStartLogo();
    ~CStartLogo();
};

