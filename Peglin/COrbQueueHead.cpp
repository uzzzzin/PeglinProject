#include "pch.h"
#include "COrbQueueHead.h"

COrbQueueHead::COrbQueueHead()
	: m_Animator(nullptr)
	, m_OrbAnimator(nullptr)
{
	m_Animator = AddComponent<CAnimator>(L"Animator");
	//m_OrbAnimator = AddComponent<CAnimator>(L"OrbAnimator");

	m_Animator->LoadAnimation(L"animdata\\QueueHead.txt");

	//m_OrbAnimator->LoadAnimation(L"animdata\\Pebball.txt");

}

COrbQueueHead::~COrbQueueHead()
{

}

void COrbQueueHead::begin()
{
	SetPos(Vec2(444.5f, 357.f));
	SetScale(Vec2(105.f, 105.f));
	SetName(L"OrbQueueHead");
	m_Animator->Play(L"QueueHead", true);

	//m_OrbAnimator->Play(L"Pebball",true);
}

void COrbQueueHead::tick(float _DT)
{
	Super::tick(_DT);
	
}
