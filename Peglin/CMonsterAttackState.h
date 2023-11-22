#pragma once
#include "CState.h"
class CMonsterAttackState :
    public CState
{
private:
    class CGeneralLevel* m_curLevel;
    class CPeglinPlayer* m_Peglin;
    class CEnemy* m_AttackEnemy;

    class CPeglinDamaged* m_PeglinDamageUI;

    vector<CTexture*> RedNums;

    float m_Duration;
    float m_AccTime;

public:
    virtual void finaltick(float _DT);
    virtual void Enter();
    virtual void Exit();

    virtual void render(HDC _dc);

public:
    CLONE(CMonsterAttackState);
    CMonsterAttackState();
    ~CMonsterAttackState();
};

