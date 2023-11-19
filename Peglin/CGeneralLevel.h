#pragma once
#include "CLevel.h"
class CGeneralLevel :
    public CLevel
{
private:

    int turnCnt; // ���� �� �ϱ��� �Դ���
    vector<std::pair<class CEnemy*, int>> EnemysCheck; // ������ ������ �� ����
    class CPeglinPlayer* my_Peglin;

public:
    vector<float> EnemyXPos;

    int GetCurTurn() { return turnCnt;}
    void SetEnemysCheck(CEnemy* _enemy, int _initIdx) { EnemysCheck.push_back(make_pair(_enemy, _initIdx));}
    vector<std::pair<class CEnemy*, int>> GetEnemyCheck() { return EnemysCheck; }
    void CurTurnPP() { ++turnCnt; }

};

