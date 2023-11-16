#pragma once
#include "CObj.h"
class CEnemy :
    public CObj
{
    GENERATED_OBJECT(CObj);

private:
    EnemyInfo EnemyInitInfo;
    int curHP;
    class CAnimator* m_Animator;
    class CMovement* m_Movement;

    //vector<float> EnemyXPos;

public:
    void SetEnemyInfo(const EnemyInfo& _Info)
    { 
        EnemyInitInfo = _Info; 
    }


public:
    //virtual void begin() override;
    virtual void tick(float _DT) override;
    //virtual void render(HDC _dc) override;



public:
    CLONE(CEnemy);
    CEnemy();
    ~CEnemy();
};

