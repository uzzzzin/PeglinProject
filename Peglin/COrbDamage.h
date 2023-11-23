#pragma once
#include "CObj.h"
class COrbDamage :
    public CObj
{
    GENERATED_OBJECT(CObj);

private:
    class CTexture* m_PeglinDamagedUI;
    class CTransform* m_Transform;

    vector<CTexture*> WhiteNums;

    int damageNum;
    int alphaCnt;


public:
    void AddDamageNum(int _num)
    {
        damageNum = _num + damageNum;
    }

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
    void alphaCntReset()
    {
        alphaCnt = 255;
    }


public:
    //virtual void begin() override;
    //virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;
    virtual void finaltick(float _DT) override;

public:
    CLONE(COrbDamage);
    COrbDamage();
    ~COrbDamage();
};

