#pragma once
#include "CPeg.h"
class CCritPeg :
    public CPeg
{
    GENERATED_OBJECT(CPeg);

public:
    virtual void begin();
    virtual void tick(float _DT);
    virtual void render(HDC _dc);
    virtual void Reload();  //재생성 함수
    // 충돌 관련 오버랩 함수가 필요할턴디 

    virtual void Refresh() override;

    virtual void BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol);

public:
    CLONE(CCritPeg);
    CCritPeg();
    // CGreyPeg(const CGreyPeg& _Origin);
    virtual ~CCritPeg();
};

