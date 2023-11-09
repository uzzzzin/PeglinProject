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
    
    class CAnimator* m_Animator;
    class CColliderCircle* m_Collider;

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
    virtual void begin();
    virtual void tick(float _DT);
    virtual void render(HDC _dc) { CObj::render(_dc); };
    virtual void Reload() {};  //����� �Լ�
    // �浹 ���� ������ �Լ��� �ʿ����ϵ� 

    //virtual void BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol);
    //virtual void Overlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol);
    //virtual void EndOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol);

public:
    virtual CPeg* Clone() = 0;
    CPeg();
    //CPeg(const CPeg& _Origin);
    virtual ~CPeg();
};

