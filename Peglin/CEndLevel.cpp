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
	LOG(LOGLOG, L"EndLevel ����");
}

void CEndLevel::exit()
{
	LOG(LOGLOG, L"EndLevel ��������");
	DeleteAllObjects();
}

void CEndLevel::tick()
{
	CLevel::tick();

	// Enter Ű�� ������ PlayLevel �� ��ȯ
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeLevel(LEVEL_TYPE::BOARD_EDIT_LEVEL);
	}
}
