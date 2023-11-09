#pragma once
#include "CObj.h"

class CPlayer :
    public CObj
{
    GENERATED_OBJECT(CObj);
private:
    class CColliderCircle* m_Collider;
    class CAnimator* m_Animator;
    class CMovement* m_Movement;

public:
    Vec2    prevPos;
    Vec2    curPos;
    Vec2    m_vDir;
    Vec2    vDest;


public:
    virtual void tick(float _DT) override;
    virtual void BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol) override;
    virtual void Overlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol) override;

public:
    CLONE(CPlayer);
    CPlayer();
    CPlayer(const CPlayer& _Origin);
    ~CPlayer();
};

