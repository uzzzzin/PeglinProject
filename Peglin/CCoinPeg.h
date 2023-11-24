#pragma once
#include "CPeg.h"
class CCoinPeg :
    public CPeg
{
    GENERATED_OBJECT(CPeg);

private:
    bool    bSlimed; // ������ȭ �� �������
    class CSound* m_SE;
    class CSound* m_SE2;

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
    virtual void BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol);


public:
    CLONE(CCoinPeg);
    CCoinPeg();
    // CCoinPeg(const CCoinPeg& _Origin);
    virtual ~CCoinPeg();
};
