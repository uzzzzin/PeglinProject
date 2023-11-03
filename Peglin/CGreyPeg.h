#pragma once
#include "CPeg.h"
class CGreyPeg :
    public CObj
{
    GENERATED_OBJECT(CObj);

private:
    //int iPegType; // 페그의 타입
    int iDieCnt; // 몇 번 맞으면 죽는지
    int iCurCnt; // 페그 생성되고 현재 몇 번 맞았는지
    bool bDied; // 현재 죽었는지 안 죽었는지 -> 엔터티에 있지 않나 
    class CCollider* m_Collider;
    class CAnimator* m_Animator;


public:
    virtual void begin();
    virtual void tick(float _DT);
    virtual void render(HDC _dc);
    virtual void Reload();  //재생성 함수
    // 충돌 관련 오버랩 함수가 필요할턴디 


public:
    CLONE(CGreyPeg);
    CGreyPeg();
   // CGreyPeg(const CGreyPeg& _Origin);
    virtual ~CGreyPeg();
};

