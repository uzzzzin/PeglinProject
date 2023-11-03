#include "pch.h"
#include "CEndLevel.h"

#include "CKeyMgr.h"
#include "CLevelMgr.h"
#include "CLogMgr.h"

void CEndLevel::init()
{
}

void CEndLevel::enter()
{
	LOG(LOGLOG, L"EndLevel 들어옴");
}

void CEndLevel::exit()
{
	LOG(LOGLOG, L"EndLevel 빠져나감");
	DeleteAllObjects();
}

void CEndLevel::tick()
{
	CLevel::tick();

	// Enter 키가 눌리면 PlayLevel 로 전환
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeLevel(LEVEL_TYPE::BOARD_EDIT_LEVEL);
	}
}
