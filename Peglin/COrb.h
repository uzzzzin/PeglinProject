#pragma once
#include "CObj.h"

class COrb :
    public CObj
{
    GENERATED_OBJECT(CObj);
    class CColliderCircle* m_Collider;
    class CAnimator* m_Animator;
    class CMovement*  m_Movement;

public:
    Vec2 prevPos;
    Vec2 curPos;
    Vec2 vDir;
    
public:
    Vec2 GetPrevPos()
    {
        return prevPos;
    }
    Vec2 GetDir()
    {
        return (curPos - prevPos).Normalize();
    }

    virtual void tick(float _DT) override;
    //virtual void render(HDC _dc) override;
    virtual void BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol) override;
    virtual void Overlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol) override;
    //virtual void EndOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol) override;

public:
    CLONE(COrb);
    COrb();
    ~COrb();
};

