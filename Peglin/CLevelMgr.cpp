#include "pch.h"
#include "CLevelMgr.h"

#include "CEngine.h"
#include "CCamera.h"
#include "CLogMgr.h"
#include "CCollisionMgr.h"

#include "CLevel.h"
#include "CStartLevel.h"
#include "CStage1Level.h"
#include "CStage2Level.h"
#include "CBossStageLevel.h"
#include "CEndLevel.h"


#include "CPlayer.h"
#include "CMonster.h"
#include "CProjectile.h"
#include "CGuided.h"
#include "CPlatform.h"

CLevelMgr::CLevelMgr()
	: m_pCurLevel(nullptr)
{

}

CLevelMgr::~CLevelMgr()
{
	for (UINT i = 0; i < (UINT)LEVEL_TYPE::END; ++i)
	{
		if (nullptr != m_arrLevels[i])
			delete m_arrLevels[i];
	}
}


void CLevelMgr::init()
{
	// 모든 레벨 생성
	m_arrLevels[(UINT)LEVEL_TYPE::START_LEVEL] = new CStartLevel;
	m_arrLevels[(UINT)LEVEL_TYPE::STAGE_1_LEVEL] = new CStage1Level;
	m_arrLevels[(UINT)LEVEL_TYPE::STAGE_2_LEVEL] = new CStage2Level;
	m_arrLevels[(UINT)LEVEL_TYPE::STAGE_BOSS_LEVEL] = new CBossStageLevel;
	m_arrLevels[(UINT)LEVEL_TYPE::END_LEVEL] = new CEndLevel;


	// 레벨 초기화
	for (UINT i = 0; i < (UINT)LEVEL_TYPE::END; ++i)
	{
		m_arrLevels[i]->init();
	}

	// Level
	::ChangeLevel(LEVEL_TYPE::START_LEVEL);
}

void CLevelMgr::tick()
{
	if (nullptr != m_pCurLevel)
		m_pCurLevel->tick();
}

void CLevelMgr::render(HDC _dc)
{
	if (nullptr == m_pCurLevel)
		return;

	// Level Render
	// 화면 Clear
	POINT ptResolution = CEngine::GetInst()->GetResolution();
	Rectangle(_dc, -1, -1, ptResolution.x + 1, ptResolution.y + 1);

	// 레벨 render
	m_pCurLevel->render(_dc);

	// Log
	CLogMgr::GetInst()->tick(_dc);
}


void CLevelMgr::ChangeLevel(LEVEL_TYPE _Type)
{
	if (m_pCurLevel == m_arrLevels[(UINT)_Type])
		return;

	if (nullptr != m_pCurLevel)
		m_pCurLevel->exit();

	m_pCurLevel = m_arrLevels[(UINT)_Type];

	m_pCurLevel->enter();

	m_pCurLevel->begin();
}