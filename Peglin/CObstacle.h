#pragma once
#include "CImg.h"
class CObstacle :
    public CImg
{
    GENERATED_OBJECT(CImg);

private:
    CColliderCircle* m_Collider;
    class CSound* m_SE;

public:
    virtual void tick(float _DT) override;
    virtual void begin() override;

    virtual void BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol);
   virtual void Overlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol) override;



public:
    CLONE(CObstacle);
    CObstacle();
    ~CObstacle();
};

