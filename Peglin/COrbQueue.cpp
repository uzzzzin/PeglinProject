#include "pch.h"
#include "COrbQueue.h"

#include "COrbQueueBody.h"
#include "COrbQueueHead.h"
#include "COrbQueueChain.h"
#include "COrbQueueBodyOrbCase.h"

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
{
	SetName(L"OrbQueue");
	m_Animator = AddComponent<CAnimator>(L"Animator");
	m_Animator->LoadAnimation(L"animdata\\LWall.txt");
	m_Animator->Play(L"LWall", true);

	QueueHead = new COrbQueueHead;
	QueueBody = new COrbQueueBody;

	CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();
	CPeglinPlayer* pPlayer = dynamic_cast<CPeglinPlayer*>(pCurLevel->FindObjectByName(L"PeglinPlayer"));
	int orbSize = pPlayer->myOrbs.size();

	for (int i = 0; i < orbSize; ++i)
	{
		nextOrbs.push_back(pPlayer->myOrbs[i]);
	}

	//m_AI = AddComponent<CStateMachine>(L"AI");
	/*m_AI->AddState((UINT)STATE_INIT, new CInitState);
	m_AI->AddState((UINT)BEFORE_SHOOT, new CBeforeShootState);*/
}

COrbQueue::~COrbQueue()
{

}

void COrbQueue::begin()
{
	CLevelMgr::GetInst()->GetCurLevel()->GetLayer(PLATFORM)->AddObject(QueueBody);

	for (int i = 0; i < nextOrbs.size() - 1; ++i)
	{
		float SetPosY = 425.f + 45 * i;
		
		// ť ü��
		COrbQueueChain* tmpChain = new COrbQueueChain;
		OrbChains.push_back(tmpChain);
		CLevelMgr::GetInst()->GetCurLevel()->GetLayer(PLATFORM)->AddObject(tmpChain);

		tmpChain->SetPos(Vec2(444.5f, SetPosY));
		tmpChain->SetScale(Vec2(32, 46));

		// ť ��⿭ - ���� ���̽�
		COrbQueueBodyOrbCase* tmpOrbCase = new COrbQueueBodyOrbCase;
		OrbCases.push_back(tmpOrbCase);
		CLevelMgr::GetInst()->GetCurLevel()->GetLayer(PLATFORM)->AddObject(tmpOrbCase);

		tmpOrbCase->SetPos(Vec2(444.5f, SetPosY));
		tmpOrbCase->SetScale(Vec2(42, 40));

		// ���� ���̽� ���� �����Ǵ� �����
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
			LOG(ERR, L"���� �밡�� �̻���.");
			break;
		}
		}
	}
	CLevelMgr::GetInst()->GetCurLevel()->GetLayer(PLATFORM)->AddObject(QueueHead);

	//m_AI->ChangeState((UINT)STATE_INIT);

}

void COrbQueue::tick(float _DT)
{
	Super::tick(_DT);

	if (KEY_TAP(F))
	{
		if (380.f >= OrbCases[OrbCases.size() - 1]->GetPos().y) // ���� ť ���ε�
		{
			for (int i = 0; i < nextOrbs.size() - 1; ++i)
			{
				float SetPosY = 425.f + 45 * (i+1);        //425.f - 45 * i;
				OrbChains[i]->SetPos(Vec2(444.5f, SetPosY));
				OrbCases[i]->SetPos(Vec2(444.5f, SetPosY));
				OrbImgs[i]->SetPos(Vec2(444.5f, SetPosY));
			}
		}
		for (int i = 0; i < nextOrbs.size() - 1; ++i)
		{
			float SetPosY = OrbChains[i]->GetPos().y - 45;         //425.f - 45 * i;
			OrbChains[i]->SetPos(Vec2(444.5f, SetPosY));
			OrbCases[i]->SetPos(Vec2(444.5f, SetPosY));
			OrbImgs[i]->SetPos(Vec2(444.5f, SetPosY));
		}
	}

	//m_AI->ChangeState((UINT)BEFORE_SHOOT);
}
