#include "pch.h"
#include "CStage1Level.h"
#include "CGeneralLevel.h"
#include "CPeglinPlayer.h"
#include "CEngine.h"

#include "CKeyMgr.h"
#include "CLevelMgr.h"
#include "CLogMgr.h"
#include "CCollisionMgr.h"
#include "components.h"

#include "CImg.h"
#include "CColliderWall.h"
#include "CPlatform.h"
#include "CGreyPeg.h"
#include "COrb.h"
#include "CObstacle.h"

#include "COrbQueue.h"
#include "COrbQueueHeadOrb.h"
#include "CEnemy.h"

#include "CPeglinHealth.h"


void CStage1Level::init()
{
}

void CStage1Level::enter()
{
	LOG(LOGLOG, L"CStage1Level 들어옴");
	Vec2 vLookAt = CEngine::GetInst()->GetResolution();
	vLookAt /= 2.f;
	CCamera::GetInst()->SetLookAt(vLookAt);

	//my_Peglin->GetComponent<class CStateMachine>()->ChangeState(UINT(STATE_INIT));
	my_Peglin = new CPeglinPlayer;
	my_Peglin->SetPos(Vec2(440.f, 207.f));
	my_Peglin->SetScale(Vec2(110.f, 110.f));
	AddObject(PEGLIN, my_Peglin);

	CPeglinHealth* pPeglinHealth = new CPeglinHealth;
	pPeglinHealth->SetPos(Vec2(190,400));
	pPeglinHealth->SetScale(Vec2(256,68));
	AddObject(WORLD_STATIC, pPeglinHealth);

	// --------------------------------------------- enemy start
	//CEnemy* pBlueSlime1 = new CEnemy;
	//pBlueSlime1->SetCurIdx(0);
	//int i = pBlueSlime1->GetCurIdx();
	//pBlueSlime1->SetPos(Vec2(EnemyXPos[i % 7],230.f ));
	//pBlueSlime1->SetScale(Vec2(78.f, 48.f));
	//SetEnemysCheck(pBlueSlime1, i);
	//AddObject(MONSTER, pBlueSlime1);


	CEnemy* pBlueSlime2 = new CEnemy;
	pBlueSlime2->SetCurIdx(1);
	int i = pBlueSlime2->GetCurIdx();
	pBlueSlime2->SetPos(Vec2(EnemyXPos[i % 7], 230.f));
	pBlueSlime2->SetScale(Vec2(78.f, 48.f));
	SetEnemysCheck(pBlueSlime2, i);
	AddObject(MONSTER, pBlueSlime2);

	CEnemy* pBlueSlime3 = new CEnemy;
	pBlueSlime3->SetCurIdx(2);
	i = pBlueSlime3->GetCurIdx();
	pBlueSlime3->SetPos(Vec2(EnemyXPos[i % 7], 230.f));
	pBlueSlime3->SetScale(Vec2(78.f, 48.f));
	SetEnemysCheck(pBlueSlime3, i);
	AddObject(MONSTER, pBlueSlime3);

	CEnemy* pBlueSlime4 = new CEnemy;
	pBlueSlime4->SetCurIdx(3);
	i = pBlueSlime4->GetCurIdx();
	pBlueSlime4 ->SetPos(Vec2(EnemyXPos[i % 7], 230.f));
	pBlueSlime4->SetScale(Vec2(78.f, 48.f));
	SetEnemysCheck(pBlueSlime4, i);
	AddObject(MONSTER, pBlueSlime4);

	CEnemy* pBlueSlime5 = new CEnemy;
	pBlueSlime5->SetCurIdx(4);
	i = pBlueSlime5->GetCurIdx();
	pBlueSlime5->SetPos(Vec2(EnemyXPos[i % 7], 230.f));
	pBlueSlime5->SetScale(Vec2(78.f, 48.f));
	SetEnemysCheck(pBlueSlime5, i);
	AddObject(MONSTER, pBlueSlime5);

	CEnemy* pBlueSlime6 = new CEnemy;
	pBlueSlime6->SetCurIdx(5);
	i = pBlueSlime6->GetCurIdx();
	pBlueSlime6->SetPos(Vec2(EnemyXPos[i % 7], 230.f));
	pBlueSlime6->SetScale(Vec2(78.f, 48.f));
	SetEnemysCheck(pBlueSlime6, i);
	AddObject(MONSTER, pBlueSlime6);

	CEnemy* pBlueSlime7 = new CEnemy;
	pBlueSlime7->SetCurIdx(6);
	i = pBlueSlime7->GetCurIdx();
	pBlueSlime7->SetPos(Vec2(EnemyXPos[i % 7], 230.f));
	pBlueSlime7->SetScale(Vec2(78.f, 48.f));
	SetEnemysCheck(pBlueSlime7, i);
	AddObject(MONSTER, pBlueSlime7);

	// --------------------------------------------- enemy end


	CImg* pStartBG = new CImg;
	pStartBG->SetPos(Vec2(512.f, 300.f));
	pStartBG->SetScale(Vec2(800.f, 630.f));
	pStartBG->SetImg(L"animdata\\BoardBGBtn.txt", L"BoardBGBtn");
	AddObject(BG, pStartBG);

	//CColliderWall* pLWall = new CColliderWall;
	//pLWall->SetPos(Vec2(444.5f, 585.f));
	//pLWall->SetScale(Vec2(135.f, 630.f));
	//pLWall->SetImg(L"animdata\\LWall.txt", L"LWall");
	//AddObject(PLATFORM, pLWall);

	//CImg* pQueueHead = new CImg;
	//pQueueHead->SetPos(Vec2(444.5f, 360.f));
	//pQueueHead->SetScale(Vec2(105.f, 105.f));
	//pQueueHead->SetImg(L"animdata\\QueueHead.txt", L"QueueHead");
	//AddObject(PLATFORM, pQueueHead);

	COrbQueue* pOrbQueue = new COrbQueue;
	pOrbQueue->SetPos(Vec2(444.5f, 585.f));
	pOrbQueue->SetScale(Vec2(135.f, 630.f));
	AddObject(PLATFORM, pOrbQueue);

	CColliderWall* pRWall = new CColliderWall;
	pRWall->SetPos(Vec2(1334.5f, 585.f));
	pRWall->SetScale(Vec2(45.f, 630.f));
	pRWall->SetImg(L"animdata\\RWall.txt", L"RWall");
	AddObject(PLATFORM, pRWall);

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

	//COrbQueueHeadOrb* pQueueOrb = new COrbQueueHeadOrb;
	//pQueueOrb->SetPos(Vec2(444.5f, 357.f));
	//pQueueOrb->SetScale(Vec2(50, 50));
	//AddObject(PLAYER_PJ, pQueueOrb);

	CColliderWall* pForest = new CColliderWall;
	pForest->SetPos(Vec2(800.f, 150.f));
	pForest->SetScale(Vec2(1600.f, 300.f));
	pForest->SetImg(L"animdata\\Forest.txt", L"Forest");
	AddObject(FOREST, pForest);

	CImg* pObstacleBody = new CImg;
	pObstacleBody->SetPos(Vec2(630, 883));
	pObstacleBody->SetScale(Vec2(49.f, 49.f));
	pObstacleBody->SetImg(L"animdata\\CircleObstacleBody.txt", L"CircleObstacleBody");
	AddObject(PLATFORM, pObstacleBody);
	CObstacle* pObstacle = new CObstacle;
	pObstacle->SetPos(Vec2(630, 833));
	pObstacle->SetScale(Vec2(94.5f, 87.5f));
	pObstacle->SetImg(L"animdata\\CircleObstacle.txt", L"CircleObstacle");
	AddObject(PLATFORM, pObstacle);


	CImg* pObstacleBody2 = new CImg;
	pObstacleBody2->SetPos(Vec2(820, 883));
	pObstacleBody2->SetScale(Vec2(49.f, 49.f));
	pObstacleBody2->SetImg(L"animdata\\CircleObstacleBody.txt", L"CircleObstacleBody");
	AddObject(PLATFORM, pObstacleBody2);
	CObstacle* pObstacle2 = new CObstacle;
	pObstacle2->SetPos(Vec2(820, 833));
	pObstacle2->SetScale(Vec2(94.5f, 87.5f));
	pObstacle2->SetImg(L"animdata\\CircleObstacle.txt", L"CircleObstacle");
	AddObject(PLATFORM, pObstacle2);


	CImg* pObstacleBody3 = new CImg;
	pObstacleBody3->SetPos(Vec2(1010, 883));
	pObstacleBody3->SetScale(Vec2(49.f, 49.f));
	pObstacleBody3->SetImg(L"animdata\\CircleObstacleBody.txt", L"CircleObstacleBody");
	AddObject(PLATFORM, pObstacleBody3);
	CObstacle* pObstacle3 = new CObstacle;
	pObstacle3->SetPos(Vec2(1010, 833));
	pObstacle3->SetScale(Vec2(94.5f, 87.5f));
	pObstacle3->SetImg(L"animdata\\CircleObstacle.txt", L"CircleObstacle");
	AddObject(PLATFORM, pObstacle3);


	CImg* pObstacleBody4 = new CImg;
	pObstacleBody4->SetPos(Vec2(1200, 883));
	pObstacleBody4->SetScale(Vec2(49.f, 49.f));
	pObstacleBody4->SetImg(L"animdata\\CircleObstacleBody.txt", L"CircleObstacleBody");
	AddObject(PLATFORM, pObstacleBody4);
	CObstacle* pObstacle4 = new CObstacle;
	pObstacle4->SetPos(Vec2(1200, 833));
	pObstacle4->SetScale(Vec2(94.5f, 87.5f));
	pObstacle4->SetImg(L"animdata\\CircleObstacle.txt", L"CircleObstacle");
	AddObject(PLATFORM, pObstacle4);
	
	LoadPegs(L"Board\\Board1.txt");


	CCollisionMgr::GetInst()->CheckCollision(ORB, PLATFORM);
	CCollisionMgr::GetInst()->CheckCollision(ORB, PEG);


	//pPlayer.m_AI->ChangeState(UINT(STATE_INIT));

	//pPlayer->GetOwnerSM()->ChangeState((UINT)MONSTER_ATTACK);
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
		ChangeLevel(LEVEL_TYPE::BOARD_EDIT_LEVEL);
	}
}

CStage1Level::CStage1Level()
	: my_Peglin(nullptr)
{

}

CStage1Level::~CStage1Level()
{
}
