#pragma once
#include "CObj.h"

class COrb :
    public CObj
{
    GENERATED_OBJECT(CObj);
private:
    class CColliderCircle* m_Collider;
    class CAnimator* m_Animator;
    class CMovement*  m_Movement;

    vector<OrbInfo> orbs;

    ORB_TYPE curOrbType;
    int curDamage;
    int curCritDamage; 
    int curAttackCnt;

public:
    Vec2 prevPos;
    Vec2 curPos;
    Vec2 rPos;
    Vec2 colPos;
    Vec2 vDir;

    Vec2 m_pPos;
    Vec2 m_cPos;
    Vec2 m_rPos;
    Vec2 m_colPos;
    
public:
    Vec2 GetPrevPos()
    {
        return prevPos;
    }
    Vec2 GetDir()
    {
        return (curPos - prevPos).Normalize();
    }

    void SetCurTurnOrb(ORB_TYPE _type);

    virtual void begin() override;
    virtual void tick(float _DT) override;
   virtual void render(HDC _dc) override;
    virtual void BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol) override;
    virtual void Overlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol) override;
    //virtual void EndOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol) override;

public:
    CLONE(COrb);
    COrb();
    ~COrb();
};

