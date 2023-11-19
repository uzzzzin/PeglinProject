#include "pch.h"
#include "COrbQueueHeadOrb.h"

#include "CLevelMgr.h"
#include "CLogMgr.h"
#include "CLevel.h"
#include "COrb.h"

COrbQueueHeadOrb::COrbQueueHeadOrb()
	: m_Animator(nullptr)
{
	m_Animator = AddComponent<CAnimator>(L"Animator");
	m_Animator->LoadAnimation(L"animdata\\Pebball.txt");
	m_Animator->LoadAnimation(L"animdata\\Daggorb.txt");
	m_Animator->LoadAnimation(L"animdata\\Infernorb.txt");
	m_Animator->LoadAnimation(L"animdata\\Sphear.txt");
	m_Animator->LoadAnimation(L"animdata\\Rubborb.txt");
}

COrbQueueHeadOrb::~COrbQueueHeadOrb()
{
}

void COrbQueueHeadOrb::OrbAnimPlay(ORB_TYPE _orbType)
{
	switch (_orbType)
	{
	case PEBBALL:
	{
		m_Animator->Play(L"Pebball", true);
		break;
	}
	case DAGGORB:
	{
		m_Animator->Play(L"Daggorb", true);
		break;
	}
	case INFERNORB:
	{
		m_Animator->Play(L"Infernorb", true);
		break;
	}
	case SPHEAR:
	{
		m_Animator->Play(L"Sphear", true);
		break;
	}
	case RUBBORB:
	{
		m_Animator->Play(L"Rubborb", true);
		break;
	}
	default:
	{
		LOG(ERR, L"오브 대가리 이미지가 매우 매우 이상함.");
		break;
	}
	}
}
