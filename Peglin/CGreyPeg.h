#pragma once
#include "CPeg.h"
class CGreyPeg :
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
    // �浹 ���� ������ �Լ��� �ʿ����ϵ� 

   // virtual void BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol);


public:
    CLONE(CGreyPeg);
    CGreyPeg();
   // CGreyPeg(const CGreyPeg& _Origin);
    virtual ~CGreyPeg();
};

