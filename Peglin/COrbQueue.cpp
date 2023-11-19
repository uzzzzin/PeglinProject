#include "pch.h"
#include "COrbQueue.h"

#include "COrbQueueBody.h"
#include "COrbQueueHead.h"
#include "COrbQueueChain.h"
#include "COrbQueueBodyOrbCase.h"
#include "COrbQueueHeadOrb.h"

#include "CLevelMgr.h"
#include "CLevel.h"
#include "CKeyMgr.h"
#include "CPeglinPlayer.h"

#include "CImg.h"
#include "components.h"

#include "CInitState.h"
#include "CBeforeShootState.h"


COrbQueue::COrbQueue()
	: m_Animator(nullptr)
	//, m_AI(nullptr)
	, QueueHead(nullptr)
	, QueueBody(nullptr)
	, QueueHeadOrb(nullptr)
{
	SetName(L"OrbQueue");
	m_Animator = AddComponent<CAnimator>(L"Animator");
	m_Animator->LoadAnimation(L"animdata\\LWall.txt");
	m_Animator->Play(L"LWall", true);

	QueueHead = new COrbQueueHead;
	QueueBody = new COrbQueueBody;
	QueueHeadOrb = new COrbQueueHeadOrb;

	CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();
	CPeglinPlayer* pPlayer = dynamic_cast<CPeglinPlayer*>(pCurLevel->FindObjectByName(L"PeglinPlayer"));
	int orbSize = pPlayer->myOrbs.size();

	for (int i = 0; i < orbSize; ++i)
	{
		nextOrbs.push_back(pPlayer->myOrbs[i]);
	}
}

COrbQueue::~COrbQueue()
{
}

void COrbQueue::begin()
{
	CLevelMgr::GetInst()->GetCurLevel()->GetLayer(PLATFORM)->AddObject(QueueBody);
	CLevelMgr::GetInst()->GetCurLevel()->GetLayer(PLATFORM)->AddObject(QueueHead);
	CLevelMgr::GetInst()->GetCurLevel()->GetLayer(PLATFORM)->AddObject(QueueHeadOrb);

	for (int i = 0; i < nextOrbs.size() - 1; ++i)
	{
		float SetPosY = 425.f + 45 * i;
		
		// 큐 체인
		COrbQueueChain* tmpChain = new COrbQueueChain;
		OrbChains.push_back(tmpChain);
		CLevelMgr::GetInst()->GetCurLevel()->GetLayer(PLATFORM)->AddObject(tmpChain);

		tmpChain->SetPos(Vec2(444.5f, SetPosY));
		tmpChain->SetScale(Vec2(32, 46));

		// 큐 대기열 - 오브 케이스
		COrbQueueBodyOrbCase* tmpOrbCase = new COrbQueueBodyOrbCase;
		OrbCases.push_back(tmpOrbCase);
		CLevelMgr::GetInst()->GetCurLevel()->GetLayer(PLATFORM)->AddObject(tmpOrbCase);

		tmpOrbCase->SetPos(Vec2(444.5f, SetPosY));
		tmpOrbCase->SetScale(Vec2(42, 40));

		// 오브 케이스 위에 렌더되는 오브들
		CImg* pNextOrb = new CImg;
		OrbImgs.push_back(pNextOrb);
		CLevelMgr::GetInst()->GetCurLevel()->GetLayer(PLATFORM)->AddObject(pNextOrb);
		pNextOrb->SetPos(Vec2(444.5f, SetPosY));
		pNextOrb->SetScale(Vec2(25, 25));

		switch (nextOrbs[i+1])
		{
		case PEBBALL:
		{
			pNextOrb->SetImg(L"animdata\\Pebball.txt", L"Pebball");
			break;
		}
		case DAGGORB:
		{
			pNextOrb->SetImg(L"animdata\\Daggorb.txt", L"Daggorb");
			break;
		}
		case INFERNORB:
		{
			pNextOrb->SetImg(L"animdata\\Infernorb.txt", L"Infernorb");
			break;
		}
		case SPHEAR:
		{
			pNextOrb->SetImg(L"animdata\\Sphear.txt", L"Sphear");
			break;
		}
		case RUBBORB:
		{
			pNextOrb->SetImg(L"animdata\\Rubborb.txt", L"Rubborb");
			break;
		}
		default:
		{
			LOG(ERR, L"오브 큐  대가리 이미지 이상함.");
			break;
		}
		}
		// 큐 머리에 렌더되는 오브 이미지 QueueHeadOrb Img
		QueueHeadOrb->OrbAnimPlay(ORB_TYPE(nextOrbs[0]));
		QueueHeadOrb->SetPos(Vec2(444.5f, 357.f));
		QueueHeadOrb->SetScale(Vec2(50, 50));
	}

}

void COrbQueue::tick(float _DT)
{
	Super::tick(_DT);
}

