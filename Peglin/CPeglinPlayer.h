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
    int GetAttackDamage()
    {
        return AttackDamage;
    }

    void AddAttackDamage(int _damage)
    {
        AttackDamage = AttackDamage + _damage;
    }
    void AddMyOrbsIdx()
    {
        if (myOrbs.size() <= myOrbsIdx + 1)
        {
            myOrbsIdx = 0;
        }
        else
        {
            ++myOrbsIdx;
        }

    }

    void ReduceHP(int _damage)
    {
        HP = HP - _damage;
    }

    int GetHP()
    {
        return HP;
    }
    
    ORB_TYPE GetCurOrbType()
    {
        return myOrbs[myOrbsIdx];
    }
    ORB_TYPE GetNextOrbType()
    {
        return myOrbs[myOrbsIdx+1];
    }
    virtual void tick(float _DT) override;

public:
    CLONE(CPeglinPlayer);
    CPeglinPlayer();
    ~CPeglinPlayer();

    friend class COrbQueue;
    friend class COrb;
};

