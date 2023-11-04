#pragma once
#include "CPeg.h"
class CRefreshPeg :
    public CPeg
{
    GENERATED_OBJECT(CPeg);

public:
    virtual void begin();
    virtual void tick(float _DT);
    virtual void render(HDC _dc);
    virtual void Reload();  //재생성 함수
    // 충돌 관련 오버랩 함수가 필요할턴디 

public:
    CLONE(CRefreshPeg);
    CRefreshPeg();
    virtual ~CRefreshPeg();
};

