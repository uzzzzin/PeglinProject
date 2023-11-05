#include "pch.h"
#include "CBoardEditLevel.h"

#include "CEngine.h"

#include "CCamera.h"
#include "CKeyMgr.h"
#include "CLevelMgr.h"
#include "CLogMgr.h"

#include "CImg.h"
#include "CStartBG.h"
#include "CGreyPeg.h"
#include "CCoinPeg.h"
#include "CCritPeg.h"
#include "CRefreshPeg.h"
#include "CBombPeg.h"

#include "CBtnUI.h"

void CBoardEditLevel::init()
{
}

void CBoardEditLevel::enter()
{
	LOG(LOGLOG, L"BoardEditLevel 들어옴");

	Vec2 vLookAt = CEngine::GetInst()->GetResolution();
	vLookAt /= 2.f;
	CCamera::GetInst()->SetLookAt(vLookAt);

	CStartBG* pStartBG = new CStartBG;
	pStartBG->SetPos(Vec2(912.f,585.f));
	pStartBG->SetScale(Vec2(800.f, 630.f)); 
	AddObject(BG, pStartBG);


	CImg* pForest = new CImg;
	pForest->SetPos(Vec2(800.f,150.f));
	pForest->SetScale(Vec2(1600.f, 300.f));
	pForest->SetImg(L"animdata\\Forest.txt", L"Forest");
	AddObject(PLATFORM, pForest);

	CImg* pLWall = new CImg;
	pLWall->SetPos(Vec2(444.5f, 585.f));
	pLWall->SetScale(Vec2(135.f, 630.f));
	pLWall->SetImg(L"animdata\\LWall.txt", L"LWall");
	AddObject(BG, pLWall);

	CImg* pRWall = new CImg;
	pRWall->SetPos(Vec2(1334.5f, 585.f));
	pRWall->SetScale(Vec2(45.f, 630.f));
	pRWall->SetImg(L"animdata\\RWall.txt", L"RWall");
	AddObject(BG, pRWall);

	CImg* pQueueHead = new CImg;
	pQueueHead->SetPos(Vec2(444.5f, 350.f));
	pQueueHead->SetScale(Vec2(100.f, 100.f));
	pQueueHead->SetImg(L"animdata\\QueueHead.txt", L"QueueHead");
	AddObject(PLATFORM, pQueueHead);

	/*CBtnUI* testPeg = new CBtnUI;
	testPeg->SetPos(Vec2(300.f,450.f));
	testPeg->SetScale(Vec2(24, 24));
	AddObject(PEG, testPeg);

	CCoinPeg* testPeg2 = new CCoinPeg;
	testPeg2->SetPos(Vec2(300.f, 480.f));
	testPeg2->SetScale(Vec2(24, 24));
	AddObject(PEG, testPeg2);

	CCritPeg* testPeg3 = new CCritPeg;
	testPeg3->SetPos(Vec2(300.f, 510.f));
	testPeg3->SetScale(Vec2(24, 24));
	AddObject(PEG, testPeg3);

	CRefreshPeg* testPeg4 = new CRefreshPeg;
	testPeg4->SetPos(Vec2(300.f, 540.f));
	testPeg4->SetScale(Vec2(24, 24));
	AddObject(PEG, testPeg4);

	CBombPeg* testPeg5 = new CBombPeg;
	testPeg5->SetPos(Vec2(300.f, 570.f));
	testPeg5->SetScale(Vec2(36, 48));
	AddObject(PEG, testPeg5);*/

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
