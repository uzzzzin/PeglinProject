#pragma once
#include "CObj.h"
class CPeglinDamaged :
    public CObj
{
    GENERATED_OBJECT(CObj);

private:
    class CTexture* m_PeglinDamagedUI;
    class CTransform* m_Transform;

    vector<CTexture*> RedNums;

    int damageNum;

    int alphaCnt;

public:
    void SetDamageNum(int _num)
    {
        damageNum = _num;
    }

    int GetDamageNum()
    {
        return damageNum;
    }

    void alphaCntMM()
    {
        if (alphaCnt <= 0)
            return;

        alphaCnt = alphaCnt - 1;
    }
public:
    //virtual void begin() override;
    //virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;
    virtual void finaltick(float _DT) override;



public:
    CLONE(CPeglinDamaged);
    CPeglinDamaged();
    ~CPeglinDamaged();
};

