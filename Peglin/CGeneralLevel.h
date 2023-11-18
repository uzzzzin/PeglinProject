#pragma once
#include "CLevel.h"
class CGeneralLevel :
    public CLevel
{
private:
    //vector<CEnemy*> EnemysCheck;
    //vector<pair<class CEnemy*, int>> EnemysCheck;
    int turnCnt;
    vector<std::pair<class CEnemy*, int>> EnemysCheck;

public:
    vector<float> EnemyXPos;

    int GetCurTurn() { return turnCnt;}
    void SetEnemysCheck(CEnemy* _enemy, int _initIdx) { EnemysCheck.push_back(make_pair(_enemy, _initIdx));}
    vector<std::pair<class CEnemy*, int>> GetEnemyCheck() { return EnemysCheck; }
    void CurTurnPP() { ++turnCnt; }

};

