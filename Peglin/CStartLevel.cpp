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
	LOG( LOGLOG, L"StartLevel ����");
}

void CStartLevel::exit()
{
	LOG( LOGLOG, L"StartLevel ��������");
	DeleteAllObjects();
}

void CStartLevel::tick()
{
	CLevel::tick();

	// Enter Ű�� ������ PlayLevel �� ��ȯ
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeLevel(LEVEL_TYPE::STAGE_1_LEVEL);
	}
}
