#include "pch.h"
#include "CStateClearState.h"
#include "CGeneralLevel.h"


CStateClearState::CStateClearState()
{
}

CStateClearState::~CStateClearState()
{
}


void CStateClearState::finaltick(float _DT)
{
}

void CStateClearState::Enter()
{
	m_curLevel = dynamic_cast<CGeneralLevel*>(CLevelMgr::GetInst()->GetCurLevel());
	ChangeLevel(LEVEL_TYPE::END_LEVEL);
}

void CStateClearState::Exit()
{
	m_curLevel->ResetTurn();
}
