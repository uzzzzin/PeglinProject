#pragma once
#include "CObj.h"
class CPeglinPlayer :
    public CObj
{
    GENERATED_OBJECT(CObj);
private:
    class CAnimator* m_Animator;
    class CCollider* m_Collider;
    class CStateMachine* m_AI; // 모든 턴을 관리할 FSM

    vector<ORB_TYPE> myOrbs; // 내가 보유한 오브들
    int myOrbsIdx; // 현재 가리키고 있는 오브의 인덱스 (myOrbs)

    int Coin;
    int HP;
    int AttackDamage; // 공격할 데미지 양

public:
    int GetMyOrbIdx() { return myOrbsIdx; } // 현재 턴의 오브를 들고 올
    vector<ORB_TYPE> GetOrbs() { return myOrbs; } // 페글린이 보유한 오브들 벡터를 들고 올
    int GetAttackDamage() { return AttackDamage; }
    void AddAttackDamage(int _damage) { AttackDamage = AttackDamage + _damage;   }
    
    void AddMyOrbsIdx();
    //{
    //    if (myOrbs.size() <= myOrbsIdx + 1)
    //    {
    //        myOrbsIdx = 0;
    //    }
    //    else
    //    {
    //        ++myOrbsIdx;
    //    }

    //}

    void ReduceHP(int _damage)
    {
        HP = HP - _damage;
    }

    int GetHP()
    {
        return HP;
    }
    
    ORB_TYPE GetCurOrbType();
    /*{
        return myOrbs[myOrbsIdx];
    }*/
    ORB_TYPE GetNextOrbType();
    //{
    //    return myOrbs[myOrbsIdx+1];
    //}
    virtual void tick(float _DT) override;

public:
    CLONE(CPeglinPlayer);
    CPeglinPlayer();
    ~CPeglinPlayer();

    friend class COrbQueue;
    friend class COrb;
};

