#pragma once
#include "CLevel.h"
class CGeneralLevel :
    public CLevel
{
private:

    int turnCnt; // ���� �� �ϱ��� �Դ���

    vector<std::pair<class CEnemy*, int>> EnemysCheck; // ������ ������ �� ����

public:
    vector<float> EnemyXPos;

    void SetEnemysCheck(CEnemy* _enemy, int _initIdx) { EnemysCheck.push_back(make_pair(_enemy, _initIdx));}

    vector<std::pair<class CEnemy*, int>>& GetEnemyCheck() { return EnemysCheck; }

    int GetCurTurn() { return turnCnt; }
    void CurTurnPP() { ++turnCnt; }
    void ResetTurn() { turnCnt = 0; }

public:
    CLONE_DISABLE(CGeneralLevel);
    CGeneralLevel();
    ~CGeneralLevel();

};

