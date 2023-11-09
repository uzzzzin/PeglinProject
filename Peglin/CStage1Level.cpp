#include "pch.h"
#include "CStage1Level.h"

#include "CEngine.h"

#include "CKeyMgr.h"
#include "CLevelMgr.h"
#include "CLogMgr.h"
#include "CCollisionMgr.h"

#include "CImg.h"
#include "CColliderWall.h"
#include "CPlatform.h"
#include "CGreyPeg.h"
#include "CPlayer.h"


void CStage1Level::init()
{
	Vec2 vLookAt = CEngine::GetInst()->GetResolution();
	vLookAt /= 2.f;
	CCamera::GetInst()->SetLookAt(vLookAt);

	CColliderWall* pLWall = new CColliderWall;
	pLWall->SetPos(Vec2(444.5f, 585.f));
	pLWall->SetScale(Vec2(135.f, 630.f));
	pLWall->SetImg(L"animdata\\LWall.txt", L"LWall");
	AddObject(PLATFORM, pLWall);

	CColliderWall* pRWall = new CColliderWall;
	pRWall->SetPos(Vec2(1334.5f, 585.f));
	pRWall->SetScale(Vec2(45.f, 630.f));
	pRWall->SetImg(L"animdata\\RWall.txt", L"RWall");
	AddObject(PLATFORM, pRWall);

	CColliderWall* pForest = new CColliderWall;
	pForest->SetPos(Vec2(800.f, 150.f));
	pForest->SetScale(Vec2(1600.f, 300.f));
	pForest->SetImg(L"animdata\\Forest.txt", L"Forest");
	AddObject(PLATFORM, pForest);

	CImg* pQueueHead = new CImg;
	pQueueHead->SetPos(Vec2(444.5f, 350.f));
	pQueueHead->SetScale(Vec2(100.f, 100.f));
	pQueueHead->SetImg(L"animdata\\QueueHead.txt", L"QueueHead");
	AddObject(PLATFORM, pQueueHead);

	CPlatform* pFloor = new CPlatform;
	pFloor->SetPos(Vec2(912.f, 901.f));
	pFloor->SetScale(Vec2(800.f, 2.f));
	AddObject(PLATFORM, pFloor);


	//CGreyPeg* pTestPeg = new CGreyPeg;
	//pTestPeg->SetPos(REALCENTER);
	//pTestPeg->SetScale(Vec2(24,24));
	//AddObject(PEG, pTestPeg);

	CPlayer* pPlayer = new CPlayer;
	pPlayer->SetPos(Vec2(532.f, 450.f));
	pPlayer->SetScale(Vec2(24, 24));
	AddObject(PLAYER, pPlayer);

	CCollisionMgr::GetInst()->CheckCollision(PLAYER, PLATFORM);
}

void CStage1Level::enter()
{
	LOG(LOGLOG, L"CStage1Level 들어옴");
}

void CStage1Level::exit()
{
	LOG(LOGLOG, L"CStage1Level 빠져나감");
	DeleteAllObjects();
}

void CStage1Level::tick()
{
	CLevel::tick();

	// Enter 키가 눌리면 PlayLevel 로 전환
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeLevel(LEVEL_TYPE::STAGE_2_LEVEL);
	}
}
