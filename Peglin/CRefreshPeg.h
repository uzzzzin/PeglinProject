#pragma once
#include "CPeg.h"
class CRefreshPeg :
    public CPeg
{
    GENERATED_OBJECT(CPeg);

    class CSound* m_SE;


public:
    virtual void begin();
    virtual void tick(float _DT);
    virtual void render(HDC _dc);
    virtual void Reload();  //����� �Լ�
    // �浹 ���� ������ �Լ��� �ʿ����ϵ� 

    virtual void BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol);

    virtual void Refresh() override;

public:
    CLONE(CRefreshPeg);
    CRefreshPeg();
    virtual ~CRefreshPeg();
};

