#include "pch.h"
#include "CStateClearState.h"


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
	ChangeLevel(LEVEL_TYPE::END_LEVEL);
}

void CStateClearState::Exit()
{
}
