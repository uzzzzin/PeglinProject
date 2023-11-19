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
    //class CStateMachine* m_AI;

    int curHP;

    ENEMY_TYPE type;
    int fullHP; // 총 체력
    int damage; // 페글린에게 입힐 수 있는 데미지

    int curIdx; // 몇 번 째에 등장할건지 ! // 7의 나머지가 될 예정.. 

    vector<EnemyInfo> Enemys;

    //class CImg* hpUI;

    //vector<float> EnemyXPos;
public:
    void SetEnemyInfo(ENEMY_TYPE _type);
    void SetCurIdx(int _idx) { curIdx = _idx; }
    int GetCurIdx() {return curIdx; }
    int GetCurHP() { return curHP; }
    int GetDamage() { return damage; }
    void DealDamage(int _damage) { curHP = curHP - _damage;  }


public:
    //virtual void begin() override;
    //virtual void tick(float _DT) override;
    //virtual void render(HDC _dc) override;



public:
    CLONE(CEnemy);
    CEnemy();
    ~CEnemy();
};

