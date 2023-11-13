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
#include "COrb.h"
#include "CObstacle.h"


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

	//CPlatform* pFloor = new CPlatform;
	//pFloor->SetPos(Vec2(912.f, 901.f));
	//pFloor->SetScale(Vec2(800.f, 2.f));
	//AddObject(PLATFORM, pFloor);


	//CGreyPeg* pTestPeg = new CGreyPeg;
	//pTestPeg->SetPos(REALCENTER);
	//pTestPeg->SetScale(Vec2(24,24));
	//AddObject(PEG, pTestPeg);

	COrb* pOrb = new COrb;
	pOrb->SetPos(REALCENTER);
	pOrb->SetScale(Vec2(24, 24));
	AddObject(ORB, pOrb);

	CObstacle* pObstacle = new CObstacle;
	pObstacle->SetPos(Vec2(800,800)); // Vec2(700.f, 800.f)
	pObstacle->SetScale(Vec2(108.f, 100.f));
	pObstacle->SetImg(L"animdata\\CircleObstacle.txt", L"CircleObstacle");
	AddObject(PLATFORM, pObstacle);

	CObstacle* pObstacle2 = new CObstacle;
	pObstacle2->SetPos(Vec2(950.f, 800.f));
	pObstacle2->SetScale(Vec2(108.f, 100.f));
	pObstacle2->SetImg(L"animdata\\CircleObstacle.txt", L"CircleObstacle");
	AddObject(PLATFORM, pObstacle2);

	CObstacle* pObstacle3 = new CObstacle;
	pObstacle3->SetPos(Vec2(1150.f, 800.f));
	pObstacle3->SetScale(Vec2(108.f, 100.f));
	pObstacle3->SetImg(L"animdata\\CircleObstacle.txt", L"CircleObstacle");
	AddObject(PLATFORM, pObstacle3);


	CCollisionMgr::GetInst()->CheckCollision(ORB, PLATFORM);
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
