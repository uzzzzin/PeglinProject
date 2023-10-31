#pragma once
#include "CObj.h"

class CStartBG :
    public CObj
{
    GENERATED_OBJECT(CObj);

private:
    CTexture* m_Texture;

public:
    virtual void begin() override;
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;
    

public:
    CLONE(CStartBG);
    CStartBG();
    ~CStartBG();
};

