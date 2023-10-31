#include "pch.h"
#include "CBossStageLevel.h"

#include "CKeyMgr.h"
#include "CLevelMgr.h"
#include "CLogMgr.h"

void CBossStageLevel::init()
{
}

void CBossStageLevel::enter()
{
	LOG(LOGLOG, L"CBossStageLevel 들어옴");
}

void CBossStageLevel::exit()
{
	LOG(LOGLOG, L"CBossStageLevel 빠져나감");
	DeleteAllObjects();
}

void CBossStageLevel::tick()
{
	CLevel::tick();

	// Enter 키가 눌리면 PlayLevel 로 전환
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeLevel(LEVEL_TYPE::END_LEVEL);
	}
}
