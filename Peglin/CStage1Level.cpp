#include "pch.h"
#include "CStage1Level.h"

#include "CKeyMgr.h"
#include "CLevelMgr.h"
#include "CLogMgr.h"

void CStage1Level::init()
{
}

void CStage1Level::enter()
{
	LOG(LOGLOG, L"CStage1Level 들어옴");
}

void CStage1Level::exit()
{
	LOG(LOGLOG, L"CStage1Level 빠져나감");
	DeleteAllObjects();
}

void CStage1Level::tick()
{
	CLevel::tick();

	// Enter 키가 눌리면 PlayLevel 로 전환
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeLevel(LEVEL_TYPE::STAGE_2_LEVEL);
	}
}
