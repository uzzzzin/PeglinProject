#include "pch.h"
#include "CBoardEditLevel.h"

#include "CEngine.h"

#include "CCamera.h"
#include "CKeyMgr.h"
#include "CLevelMgr.h"
#include "CLogMgr.h"

#include "CGreyPeg.h"
#include "CCoinPeg.h"
#include "CCritPeg.h"
#include "CRefreshPeg.h"
#include "CBombPeg.h"

void CBoardEditLevel::init()
{
}

void CBoardEditLevel::enter()
{
	LOG(LOGLOG, L"BoardEditLevel 들어옴");

	Vec2 vLookAt = CEngine::GetInst()->GetResolution();
	vLookAt /= 2.f;
	CCamera::GetInst()->SetLookAt(vLookAt);

	CGreyPeg* testPeg = new CGreyPeg;
	testPeg->SetPos(REALCENTER);
	testPeg->SetScale(Vec2(24, 24));
	AddObject(PEG, testPeg);

	CCoinPeg* testPeg2 = new CCoinPeg;
	testPeg2->SetPos(Vec2(900.f, 450.f));
	testPeg2->SetScale(Vec2(24, 24));
	AddObject(PEG, testPeg2);

	CCritPeg* testPeg3 = new CCritPeg;
	testPeg3->SetPos(Vec2(1000.f, 450.f));
	testPeg3->SetScale(Vec2(24, 24));
	AddObject(PEG, testPeg3);

	CRefreshPeg* testPeg4 = new CRefreshPeg;
	testPeg4->SetPos(Vec2(1100.f, 450.f));
	testPeg4->SetScale(Vec2(24, 24));
	AddObject(PEG, testPeg4);

	CBombPeg* testPeg5 = new CBombPeg;
	testPeg5->SetPos(Vec2(1200.f, 450.f));
	testPeg5->SetScale(Vec2(36, 48));
	AddObject(PEG, testPeg5);
}

void CBoardEditLevel::exit()
{
	LOG(LOGLOG, L"BoardEditLevel 빠져나감");
	DeleteAllObjects();
}

void CBoardEditLevel::tick()
{
	CLevel::tick();

	// Enter 키가 눌리면 PlayLevel 로 전환
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeLevel(LEVEL_TYPE::STAGE_1_LEVEL);
	}
}
