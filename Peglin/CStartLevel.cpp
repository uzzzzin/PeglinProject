#include "pch.h"
#include "CStartLevel.h"

#include "CKeyMgr.h"
#include "CLevelMgr.h"
#include "CLogMgr.h"

#include "CStartBG.h"

void CStartLevel::init()
{

}

void CStartLevel::enter()
{
	LOG( LOGLOG, L"StartLevel ����");

	CStartBG* pStartBG = new CStartBG;
	pStartBG->SetPos(Vec2(400.f, 450.f));
	pStartBG->SetScale(Vec2(100.f,100.f));
	AddObject(BG, pStartBG);

	CStartBG* pStartBG2 = new CStartBG;
	pStartBG2->SetPos(Vec2(1200.f, 450.f));
	pStartBG2->SetScale(Vec2(100.f,100.f));
	AddObject(BG, pStartBG2);

	//pStartBG->SetPos(REALCENTER);
	//pStartBG->SetScale(Vec2(1600.f, 900.f));
	//AddObject(BG, pStartBG);

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
