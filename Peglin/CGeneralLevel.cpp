#include "pch.h"
#include "CGeneralLevel.h"

#include "CAssetMgr.h"
#include "CSound.h"

#include "CPeglinPlayer.h"

CGeneralLevel::CGeneralLevel()
	: turnCnt(0)
	, StageClearBGM(nullptr)
{
	EnemyXPos.push_back(530);
	EnemyXPos.push_back(675);
	EnemyXPos.push_back(820);
	EnemyXPos.push_back(965);
	EnemyXPos.push_back(1110);
	EnemyXPos.push_back(1255);
	EnemyXPos.push_back(1400);

	StageClearBGM = CAssetMgr::GetInst()->LoadSound(L"StageCleagBGM", L"sound\\StageClearBGM.wav");
}

CGeneralLevel::~CGeneralLevel()
{
}

CSound* CGeneralLevel::GetStageClearBGM()
{
	return StageClearBGM;
}