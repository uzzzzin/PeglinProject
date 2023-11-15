#include "pch.h"
#include "CPeglinPlayer.h"

CPeglinPlayer::CPeglinPlayer()
	: m_Animator(nullptr)
	, m_Collider(nullptr)
	//, m_Movement(nullptr)
{
	SetName(L"PeglinPlayer");

	m_Animator = AddComponent<CAnimator>(L"Animator");
	m_Collider = AddComponent<CCollider>(L"Collider");
	//m_Movement = AddComponent<CMovement>(L"Movement");

	m_Animator->LoadAnimation(L"animdata\\PeglinIdle.txt");
	m_Animator->Play(L"PeglinIdle", true);

	m_Collider->SetScale(Vec2(76.f,90.f));
}

CPeglinPlayer::~CPeglinPlayer()
{
}

void CPeglinPlayer::tick(float _DT)
{
	Super::tick(_DT);
}
