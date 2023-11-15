#include "pch.h"
#include "COrbQueueChain.h"

COrbQueueChain::COrbQueueChain()
	: m_Animator(nullptr)
{
	m_Animator = AddComponent<CAnimator>(L"Animator");
	m_Animator->LoadAnimation(L"animdata\\QueueBodyChain.txt");
}

COrbQueueChain::~COrbQueueChain()
{
}

void COrbQueueChain::begin()
{
	m_Animator->Play(L"QueueBodyChain", true);
}

void COrbQueueChain::tick(float _DT)
{
}

