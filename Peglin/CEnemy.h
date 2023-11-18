#pragma once
#include "CObj.h"
class CEnemy :
    public CObj
{
    GENERATED_OBJECT(CObj);

private:
    EnemyInfo EnemyInitInfo;
    class CAnimator* m_Animator;
    class CMovement* m_Movement;
    class CStateMachine* m_AI;

    int curHP;

    ENEMY_TYPE type;
    int fullHP; // �� ü��
    int damage; // ��۸����� ���� �� �ִ� ������



    vector<EnemyInfo> Enemys;

    //vector<float> EnemyXPos;
public:
    void SetEnemyInfo(ENEMY_TYPE _type);

public:
    //virtual void begin() override;
    //virtual void tick(float _DT) override;
    //virtual void render(HDC _dc) override;



public:
    CLONE(CEnemy);
    CEnemy();
    ~CEnemy();
};

