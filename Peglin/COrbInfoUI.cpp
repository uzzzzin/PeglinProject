#include "pch.h"
#include "COrbInfoUI.h"

#include "components.h"

COrbInfoUI::COrbInfoUI()
	:curOrbType(ORB_TYPE_END)
	, m_Animator(nullptr)
{
	SetName(L"OrbInfoUI");
	m_Animator = AddComponent<CAnimator>(L"Animator");
	m_Animator->LoadAnimation(L"animdata\\PebballUI.txt");
	m_Animator->LoadAnimation(L"animdata\\DaggorbUI.txt");
	m_Animator->LoadAnimation(L"animdata\\InfernorbUI.txt");
	m_Animator->LoadAnimation(L"animdata\\SphearUI.txt");
	m_Animator->LoadAnimation(L"animdata\\RubborbUI.txt");
	m_Animator->LoadAnimation(L"animdata\\NullUI.txt");
}

COrbInfoUI::~COrbInfoUI()
{
}

void COrbInfoUI::tick(float _DT)
{
	Super::tick(_DT);

	switch (curOrbType)
	{
	case PEBBALL:
	{
		m_Animator->Play(L"PebballUI", false);
		break;
	}
	case DAGGORB:
	{
		m_Animator->Play(L"DaggorbUI", false);
		break;
	}
	case INFERNORB:
	{
		m_Animator->Play(L"InfernorbUI", false);
		break;
	}
	case SPHEAR:
	{
		m_Animator->Play(L"SphearUI", false);
		break;
	}
	case RUBBORB:
	{
		m_Animator->Play(L"RubborbUI", false);
		break;
	}
	default:
	{
		m_Animator->Play(L"NullUI", false);
		break;
	}
	// 스테이트에서 겟셋해서 플레이해버리기 
	}

}

void COrbInfoUI::render(HDC _dc)
{
	Super::render(_dc);
}

