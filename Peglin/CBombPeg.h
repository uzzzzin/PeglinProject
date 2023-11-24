#pragma once
#include "CPeg.h"
class CBombPeg :
    public CPeg
{
    GENERATED_OBJECT(CPeg);

    class CSound* m_SE;
    class CSound* m_SE2;


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

