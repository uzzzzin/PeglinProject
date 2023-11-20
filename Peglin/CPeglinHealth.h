#pragma once
#include "CObj.h"
class CPeglinHealth :
    public CObj
{
    GENERATED_OBJECT(CObj);
private:
    CTexture* m_blood;      // ��
    CTexture* m_HealthUI; // UI
    CTexture* m_100; // �� 100

    CTexture* m_Num100; // �� ���� ���� ��
   
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

