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
	LOG(LOGLOG, L"CBossStageLevel ����");
}

void CBossStageLevel::exit()
{
	LOG(LOGLOG, L"CBossStageLevel ��������");
	DeleteAllObjects();
}

void CBossStageLevel::tick()
{
	CLevel::tick();

	// Enter Ű�� ������ PlayLevel �� ��ȯ
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeLevel(LEVEL_TYPE::END_LEVEL);
	}
}
