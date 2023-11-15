#include "pch.h"
#include "COrbQueueBody.h"

COrbQueueBody::COrbQueueBody()
	: m_Animator(nullptr)
{
	m_Animator = AddComponent<CAnimator>(L"Animator");
	m_Animator->LoadAnimation(L"animdata\\QueueBodyFloor.txt");
	m_Animator->LoadAnimation(L"animdata\\QueueBodyOrbCase.txt");
	m_Animator->LoadAnimation(L"animdata\\QueueBodyChain.txt");


}

COrbQueueBody::~COrbQueueBody()
{
}

void COrbQueueBody::begin()
{
	//SetPos(Vec2(444.5f, 630.f));
	//SetScale(Vec2(80,600));
	//m_Animator->Play(L"QueueBodyFloor", true);
}

void COrbQueueBody::tick(float _DT)
{
	Super::tick(_DT);
}
