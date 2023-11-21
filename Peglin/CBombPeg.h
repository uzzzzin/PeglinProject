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

    virtual void Refresh() override;

    virtual void BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol);


public:
    CLONE(CBombPeg);
    CBombPeg();
    virtual ~CBombPeg();

};

