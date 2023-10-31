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
	LOG( LOGLOG, L"����ȭ�� ����");
}

void CStartLevel::exit()
{
	LOG( LOGLOG, L"����ȭ�� ��������");
	DeleteAllObjects();
}

void CStartLevel::tick()
{
	CLevel::tick();

	// Enter Ű�� ������ PlayLevel �� ��ȯ
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeLevel(LEVEL_TYPE::PLAY_LEVEL);
	}
}
