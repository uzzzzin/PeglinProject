#include "pch.h"
#include "CPeglinAttackState.h"

#include "CLogMgr.h"

CPeglinAttackState::CPeglinAttackState()
{
}

CPeglinAttackState::~CPeglinAttackState()
{
}

void CPeglinAttackState::finaltick(float _DT)
{
}

void CPeglinAttackState::Enter()
{
	LOG(LOGLOG, L"현재 상태 : Peglin Attack State");
}

void CPeglinAttackState::Exit()
{
}
