#pragma once
#include "CObj.h"
class CPeglinHealth :
    public CObj
{
    GENERATED_OBJECT(CObj);
private:
    CTexture* m_blood;      // 피
    CTexture* m_HealthUI; // UI
    CTexture* m_100; // 피 100

    CTexture* m_Num100; // 피 숫자 백일 때
   
    vector<CTexture*> Nums;

public:
    virtual void begin() override;
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;

public:
    CLONE(CPeglinHealth);
    CPeglinHealth();
    ~CPeglinHealth();
};

