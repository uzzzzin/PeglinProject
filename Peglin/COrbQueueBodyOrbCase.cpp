#include "pch.h"
#include "COrbQueueBodyOrbCase.h"

COrbQueueBodyOrbCase::COrbQueueBodyOrbCase()
	: m_Animator(nullptr)
{
	m_Animator = AddComponent<CAnimator>(L"Animator");
	m_Animator->LoadAnimation(L"animdata\\QueueBodyOrbCase.txt");

}

COrbQueueBodyOrbCase::~COrbQueueBodyOrbCase()
{
}


void COrbQueueBodyOrbCase::begin()
{

m_Animator->Play(L"QueueBodyOrbCase", true);
}

void COrbQueueBodyOrbCase::tick(float _DT)
{
}
