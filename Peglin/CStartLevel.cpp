#include "pch.h"
#include "CStartLevel.h"

#include "CKeyMgr.h"
#include "CLevelMgr.h"
#include "CLogMgr.h"

#include "CStartBG.h"
#include "CStartLogo.h"

void CStartLevel::init()
{

}

void CStartLevel::enter()
{
	LOG( LOGLOG, L"StartLevel 들어옴");

	CStartBG* pStartBG = new CStartBG;
	pStartBG->SetPos(Vec2(400.f, 450.f));
	pStartBG->SetScale(Vec2(800.f,900.f));
	AddObject(BG, pStartBG);

	CStartBG* pStartBG2 = new CStartBG;
	pStartBG2->SetPos(Vec2(1200.f, 450.f));
	pStartBG2->SetScale(Vec2(800.f,900.f));
	AddObject(BG, pStartBG2);

	//pStartBG->SetPos(REALCENTER);
	//pStartBG->SetScale(Vec2(1600.f, 900.f));
	//AddObject(BG, pStartBG);

	CStartLogo* pLogo = new CStartLogo;

	pLogo->SetScaleCoeffi(5);
	float fScaleCoeffi = pLogo->GetfScaleCoeffi();
	pLogo->SetPos(Vec2(-400.f, -200.f)); // 센터에 상대적임
	pLogo->SetScale(Vec2(129.f* fScaleCoeffi, 48.f * fScaleCoeffi)); // 원본 컷 사이즈에 곱함
	AddObject(BG, pLogo); // 어디에 넣어야 하는지 애매

}

void CStartLevel::exit()
{
	LOG( LOGLOG, L"StartLevel 빠져나감");
	DeleteAllObjects();
}

void CStartLevel::tick()
{
	CLevel::tick();

	// Enter 키가 눌리면 PlayLevel 로 전환
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeLevel(LEVEL_TYPE::STAGE_1_LEVEL);
	}
}
