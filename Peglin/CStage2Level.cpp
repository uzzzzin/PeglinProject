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
	LOG(LOGLOG, L"CStage2Level ����");
}

void CStage2Level::exit()
{
	LOG(LOGLOG, L"CStage2Level ��������");
	DeleteAllObjects();
}

void CStage2Level::tick()
{
	CLevel::tick();

	// Enter Ű�� ������ PlayLevel �� ��ȯ
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeLevel(LEVEL_TYPE::STAGE_BOSS_LEVEL);
	}
}
