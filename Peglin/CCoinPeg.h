#pragma once
#include "CObj.h"
class CCoinPeg :
    public CObj
{
    GENERATED_OBJECT(CObj);

private:
    //int iPegType; // ����� Ÿ��
    int iDieCnt; // �� �� ������ �״���
    int iCurCnt; // ��� �����ǰ� ���� �� �� �¾Ҵ���
    bool bDied; // ���� �׾����� �� �׾����� -> ����Ƽ�� ���� �ʳ� 
    class CCollider* m_Collider;
    class CAnimator* m_Animator;


public:
    virtual void begin();
    virtual void tick(float _DT);
    virtual void render(HDC _dc);
    virtual void Reload();  //����� �Լ�
    // �浹 ���� ������ �Լ��� �ʿ����ϵ� 


public:
    CLONE(CCoinPeg);
    CCoinPeg();
    // CCoinPeg(const CCoinPeg& _Origin);
    virtual ~CCoinPeg();
};
