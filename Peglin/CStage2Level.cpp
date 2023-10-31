#include "pch.h"
#include "CStage2Level.h"

#include "CKeyMgr.h"
#include "CLevelMgr.h"
#include "CLogMgr.h"

void CStage2Level::init()
{
}

void CStage2Level::enter()
{
	LOG(LOGLOG, L"CStage2Level 들어옴");
}

void CStage2Level::exit()
{
	LOG(LOGLOG, L"CStage2Level 빠져나감");
	DeleteAllObjects();
}

void CStage2Level::tick()
{
	CLevel::tick();

	// Enter 키가 눌리면 PlayLevel 로 전환
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeLevel(LEVEL_TYPE::STAGE_BOSS_LEVEL);
	}
}
