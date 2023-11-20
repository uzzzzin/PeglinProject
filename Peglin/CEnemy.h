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
    
    CTexture* m_blood;      // ��
    CTexture* m_HealthUI; // UI
    CTexture* m_slash;

    vector<CTexture*> Nums;

    int curHP;

    ENEMY_TYPE type;
    int fullHP; // �� ü��
    int damage; // ��۸����� ���� �� �ִ� ������

    int curIdx; // �� �� °�� �����Ұ��� ! // 7�� �������� �� ����.. 

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
    virtual void render(HDC _dc) override;



public:
    CLONE(CEnemy);
    CEnemy();
    ~CEnemy();
};

