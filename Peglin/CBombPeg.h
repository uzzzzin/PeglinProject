#pragma once
#include "CPeg.h"
class CBombPeg :
    public CPeg
{
    GENERATED_OBJECT(CPeg);


public:
    virtual void begin();
    virtual void tick(float _DT);
    virtual void render(HDC _dc);
    virtual void Reload();  //����� �Լ�
    // �浹 ���� ������ �Լ��� �ʿ����ϵ� 


public:
    CLONE(CBombPeg);
    CBombPeg();
    virtual ~CBombPeg();

};

