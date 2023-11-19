#pragma once
#include "CLevel.h"
class CGeneralLevel :
    public CLevel
{
private:

    int turnCnt; // 현재 몇 턴까지 왔는지

    vector<std::pair<class CEnemy*, int>> EnemysCheck; // 레벨이 보유한 적 쉑들

public:
    vector<float> EnemyXPos;

    void SetEnemysCheck(CEnemy* _enemy, int _initIdx) { EnemysCheck.push_back(make_pair(_enemy, _initIdx));}

    vector<std::pair<class CEnemy*, int>> GetEnemyCheck() { return EnemysCheck; }

    int GetCurTurn() { return turnCnt; }
    void CurTurnPP() { ++turnCnt; }

public:
    CLONE_DISABLE(CGeneralLevel);
    CGeneralLevel();
    ~CGeneralLevel();

};

