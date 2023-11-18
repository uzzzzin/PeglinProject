#pragma once
#include "CObj.h"
class CPeglinPlayer :
    public CObj
{
    GENERATED_OBJECT(CObj);
private:
    class CAnimator* m_Animator;
    class CCollider* m_Collider;
    //class CMovement* m_Movement;
    class CStateMachine* m_AI;

    int Coin;
    int HP;
    int AttackDamage;

    vector<ORB_TYPE> myOrbs;

    int myOrbsIdx;

public:
    ORB_TYPE GetCurOrbType()
    {
        return myOrbs[myOrbsIdx];
    }
    virtual void tick(float _DT) override;

public:
    CLONE(CPeglinPlayer);
    CPeglinPlayer();
    ~CPeglinPlayer();

    friend class COrbQueue;
    friend class COrb;
};

