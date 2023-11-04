#pragma once
#include "CObj.h"
class CPeg :
    public CObj
{
    //GENERATED_OBJECT(CObj);
protected:
    //int iPegType; // 페그의 타입
    int                                iDieCnt; // 몇 번 맞으면 죽는지 // 1
    int                                iCurCnt; // 페그 생성되고 현재 몇 번 맞았는지 // 0

    bool                            bDied; // 현재 죽었는지 안 죽었는지 -> 엔터티에 있지 않나 // false 
    
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
    virtual void Reload() {};  //재생성 함수
    // 충돌 관련 오버랩 함수가 필요할턴디 

public:
    virtual CPeg* Clone() = 0;
    CPeg();
    //CPeg(const CPeg& _Origin);
    virtual ~CPeg();
};

