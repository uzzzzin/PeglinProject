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
	LOG(LOGLOG, L"CStage1Level ����");
}

void CStage1Level::exit()
{
	LOG(LOGLOG, L"CStage1Level ��������");
	DeleteAllObjects();
}

void CStage1Level::tick()
{
	CLevel::tick();

	// Enter Ű�� ������ PlayLevel �� ��ȯ
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeLevel(LEVEL_TYPE::STAGE_2_LEVEL);
	}
}
