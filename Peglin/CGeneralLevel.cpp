#include "pch.h"
#include "CGeneralLevel.h"

#include "CPeglinPlayer.h"

CGeneralLevel::CGeneralLevel()
	: turnCnt(0)
{
}

CGeneralLevel::~CGeneralLevel()
{

	EnemyXPos.push_back(530);
	EnemyXPos.push_back(675);
	EnemyXPos.push_back(820);
	EnemyXPos.push_back(965);
	EnemyXPos.push_back(1110);
	EnemyXPos.push_back(1255);
	EnemyXPos.push_back(1400);
}
