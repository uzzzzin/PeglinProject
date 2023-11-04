#pragma once
#include "CObj.h"
class CPeg :
    public CObj
{
    //GENERATED_OBJECT(CObj);
protected:
    //int iPegType; // ����� Ÿ��
    int                                iDieCnt; // �� �� ������ �״��� // 1
    int                                iCurCnt; // ��� �����ǰ� ���� �� �� �¾Ҵ��� // 0
    bool                            bDied; // ���� �׾����� �� �׾����� -> ����Ƽ�� ���� �ʳ� // false 
    class CCollider*    m_Collider;
    class CAnimator* m_Animator;

public:
    void SetiDieCnt(int _iDieCnt)
    {
        iDieCnt = _iDieCnt;
    }
    void SetiCurCnt(int _iCurCnt)
    {
        iCurCnt = _iCurCnt;
    }
    void SetbDied(bool _bDied)
    {
        bDied = _bDied;
    }

public:
    virtual void begin() {};
    virtual void tick(float _DT) { CObj::tick(_DT); };
    virtual void render(HDC _dc) { CObj::render(_dc); };
    virtual void Reload() {};  //����� �Լ�
    // �浹 ���� ������ �Լ��� �ʿ����ϵ� 

public:
    virtual CPeg* Clone() = 0;
    CPeg();
    //CPeg(const CPeg& _Origin);
    virtual ~CPeg();
};

