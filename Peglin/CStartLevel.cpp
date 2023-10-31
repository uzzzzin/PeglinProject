#include "pch.h"
#include "CStartLevel.h"

#include "CKeyMgr.h"
#include "CLevelMgr.h"
#include "CLogMgr.h"

void CStartLevel::init()
{
}

void CStartLevel::enter()
{
	LOG( LOGLOG, L"시작화면 들어옴");
}

void CStartLevel::exit()
{
	LOG( LOGLOG, L"시작화면 빠져나감");
	DeleteAllObjects();
}

void CStartLevel::tick()
{
	CLevel::tick();

	// Enter 키가 눌리면 PlayLevel 로 전환
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeLevel(LEVEL_TYPE::PLAY_LEVEL);
	}
}
