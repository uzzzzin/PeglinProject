#pragma once
#include "CPeg.h"
class CCoinPeg :
    public CPeg
{
    GENERATED_OBJECT(CPeg);

private:
    bool    bSlimed; // 슬라임화 된 페그인지
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
    virtual void Reload();  //재생성 함수
    // 충돌 관련 오버랩 함수가 필요할턴디  // 충돌할 때 코인 올라가야함 

    virtual void Refresh() override;
    virtual void BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol);


public:
    CLONE(CCoinPeg);
    CCoinPeg();
    // CCoinPeg(const CCoinPeg& _Origin);
    virtual ~CCoinPeg();
};
