#include "pch.h"

#include "CBoardEditLevel.h"

#include "CEngine.h"

#include "CCamera.h"
#include "CKeyMgr.h"
#include "CLevelMgr.h"
#include "CLogMgr.h"

#include "CImg.h"
#include "CBtnUI.h"
#include "CEditBoardUI.h"

#include "CStartBG.h"
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

	//CStartBG* pStartBG = new CStartBG;
	//pStartBG->SetPos(Vec2(912.f, 585.f));
	//pStartBG->SetScale(Vec2(800.f, 630.f));
	//AddObject(BG, pStartBG);;


	CEditBoardUI* pStartBG = new CEditBoardUI;
	pStartBG->SetPos(Vec2(512.f, 300.f));
	pStartBG->SetScale(Vec2(800.f, 630.f));
	pStartBG->SetNormalImg(L"animdata\\BoardBGBtn.txt", L"BoardBGBtn");
	pStartBG->SetHoverImg(L"animdata\\BoardBGBtn.txt", L"BoardBGBtn");
	pStartBG->SetPressedImg(L"animdata\\BoardBGBtn.txt", L"BoardBGBtn");
	AddObject(UI, pStartBG);


	CImg* pForest = new CImg;
	pForest->SetPos(Vec2(800.f, 150.f));
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

	CBtnUI* GreyPegBtn = new CBtnUI;
	GreyPegBtn->SetPos(Vec2(432.5f, 450.f));
	GreyPegBtn->SetScale(Vec2(24, 24));
	GreyPegBtn->SetNormalImg(L"animdata\\firstGreyPegBtn.txt", L"firstGreyPegBtn");
	GreyPegBtn->SetHoverImg(L"animdata\\GreyPegBtn.txt", L"GreyPegBtn");
	GreyPegBtn->SetPressedImg(L"animdata\\GreyPegBtn.txt", L"GreyPegBtn");
	GreyPegBtn->SetCallBack([]() { ChangePeg(PEG_TYPE::GREY_PEG);});
	AddObject(UI, GreyPegBtn);


	CBtnUI* CoinPegBtn = new CBtnUI;
	CoinPegBtn->SetPos(Vec2(432.5f, 480.f));
	CoinPegBtn->SetScale(Vec2(24, 24));
	CoinPegBtn->SetNormalImg(L"animdata\\CoinPegBtn.txt", L"CoinPegBtn");
	CoinPegBtn->SetHoverImg(L"animdata\\CoinPegBtn.txt", L"CoinPegBtn");
	CoinPegBtn->SetPressedImg(L"animdata\\CoinPegBtn.txt", L"CoinPegBtn");
	CoinPegBtn->SetCallBack([]() {ChangePeg(PEG_TYPE::COIN_PEG);});
	AddObject(UI, CoinPegBtn);

	CBtnUI* CritPegBtn = new CBtnUI;
	CritPegBtn->SetPos(Vec2(432.5f, 510.f));
	CritPegBtn->SetScale(Vec2(24, 24));
	CritPegBtn->SetNormalImg(L"animdata\\CritPegBtn.txt", L"CritPegBtn");
	CritPegBtn->SetHoverImg(L"animdata\\CritPegBtn.txt", L"CritPegBtn");
	CritPegBtn->SetPressedImg(L"animdata\\CritPegBtn.txt", L"CritPegBtn");
	CritPegBtn->SetCallBack([]() {ChangePeg(PEG_TYPE::CRITICAL_PEG);});
	AddObject(UI, CritPegBtn);

	CBtnUI* RefreshPegBtn = new CBtnUI;
	RefreshPegBtn->SetPos(Vec2(432.5f, 540.f));
	RefreshPegBtn->SetScale(Vec2(24, 24));
	RefreshPegBtn->SetNormalImg(L"animdata\\RefreshPegBtn.txt", L"RefreshPegBtn");
	RefreshPegBtn->SetHoverImg(L"animdata\\RefreshPegBtn.txt", L"RefreshPegBtn");
	RefreshPegBtn->SetPressedImg(L"animdata\\RefreshPegBtn.txt", L"RefreshPegBtn");
	RefreshPegBtn->SetCallBack([]() {ChangePeg(PEG_TYPE::REFRESH_PEG);});
	AddObject(UI, RefreshPegBtn);


	CBtnUI* BombPegBtn = new CBtnUI;
	BombPegBtn->SetPos(Vec2(432.5f, 570.f));
	BombPegBtn->SetScale(Vec2(36, 48));
	BombPegBtn->SetNormalImg(L"animdata\\BombPegBtn.txt", L"BombPegBtn");
	BombPegBtn->SetHoverImg(L"animdata\\BombPegBtn.txt", L"BombPegBtn");
	BombPegBtn->SetPressedImg(L"animdata\\BombPegBtn.txt", L"BombPegBtn");
	BombPegBtn->SetCallBack([]() {ChangePeg(PEG_TYPE::BOMB_PEG);});
	AddObject(UI, BombPegBtn);


	CBtnUI* SlimedGreyPegBtn = new CBtnUI;
	SlimedGreyPegBtn->SetPos(Vec2(432.5f, 600.f));
	SlimedGreyPegBtn->SetScale(Vec2(24, 24));
	SlimedGreyPegBtn->SetNormalImg(L"animdata\\SlimedGreyPegBtn.txt", L"SlimedGreyPegBtn");
	SlimedGreyPegBtn->SetHoverImg(L"animdata\\SlimedGreyPegBtn.txt", L"SlimedGreyPegBtn");
	SlimedGreyPegBtn->SetPressedImg(L"animdata\\SlimedGreyPegBtn.txt", L"SlimedGreyPegBtn");
	SlimedGreyPegBtn->SetCallBack([]() {ChangePeg(PEG_TYPE::SLIMED_GREY_PEG);});
	AddObject(UI, SlimedGreyPegBtn);

	CBtnUI* SlimedCoinPegBtn = new CBtnUI;
	SlimedCoinPegBtn->SetPos(Vec2(432.5f, 630.f));
	SlimedCoinPegBtn->SetScale(Vec2(24, 24));
	SlimedCoinPegBtn->SetNormalImg(L"animdata\\SlimedCoinPegBtn.txt", L"SlimedCoinPegBtn");
	SlimedCoinPegBtn->SetHoverImg(L"animdata\\SlimedCoinPegBtn.txt", L"SlimedCoinPegBtn");
	SlimedCoinPegBtn->SetPressedImg(L"animdata\\SlimedCoinPegBtn.txt", L"SlimedCoinPegBtn");
	SlimedCoinPegBtn->SetCallBack([]() {ChangePeg(PEG_TYPE::SLIMED_COIN_PEG);});
	AddObject(UI, SlimedCoinPegBtn);

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
