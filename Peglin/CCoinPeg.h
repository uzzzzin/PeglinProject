#pragma once
#include "CPeg.h"
class CCoinPeg :
    public CPeg
{
    GENERATED_OBJECT(CPeg);

private:
    bool    bSlimed; // ������ȭ �� �������

public:
    void SetbSlimed(bool _bSlimed)
    {
        bSlimed = _bSlimed;
    }

public:
    virtual void begin();
    virtual void tick(float _DT);
    virtual void render(HDC _dc);
    virtual void Reload();  //����� �Լ�
    // �浹 ���� ������ �Լ��� �ʿ����ϵ�  // �浹�� �� ���� �ö󰡾��� 

    virtual void Refresh() override;


public:
    CLONE(CCoinPeg);
    CCoinPeg();
    // CCoinPeg(const CCoinPeg& _Origin);
    virtual ~CCoinPeg();
};
