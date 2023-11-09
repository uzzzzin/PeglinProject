#pragma once
#include "CImg.h"
class CColliderWall :
    public CImg
{
    GENERATED_OBJECT(CImg);
private:
    CCollider*            m_Collider;


public:
    virtual void tick(float _DT) override;
    virtual void begin() override;
    //virtual void render(HDC _dc) override;

    //virtual void BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol) override;
    ////virtual void Overlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol) override;
    //virtual void Overlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol) override;

public:
    CLONE(CColliderWall);
    CColliderWall();
    ~CColliderWall();

};

