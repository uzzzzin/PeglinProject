#pragma once
#include "CPeg.h"
class CCoinPeg :
    public CPeg
{
    GENERATED_OBJECT(CPeg);

public:
    virtual void begin();
    virtual void tick(float _DT);
    virtual void render(HDC _dc);
    virtual void Reload();  //����� �Լ�
    // �浹 ���� ������ �Լ��� �ʿ����ϵ�  // �浹�� �� ���� �ö󰡾��� 


public:
    CLONE(CCoinPeg);
    CCoinPeg();
    // CCoinPeg(const CCoinPeg& _Origin);
    virtual ~CCoinPeg();
};
