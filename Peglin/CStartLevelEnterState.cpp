#include "pch.h"
#include "CStartLevelEnterState.h"
#include "CGeneralLevel.h"



CStartLevelEnterState::CStartLevelEnterState()
{
}

CStartLevelEnterState::~CStartLevelEnterState()
{
}

void CStartLevelEnterState::finaltick(float _DT)
{
}

void CStartLevelEnterState::Enter()
{
	CCamera::GetInst()->FadeIn(2.f);

	//m_curLevel = dynamic_cast<CGeneralLevel*>(CLevelMgr::GetInst()->GetCurLevel());

	//for (int i = 0; i < LAYER::END; ++i)
	//{
	//	vector <CObj*> v =  m_curLevel->GetObjects((LAYER)i);
	//	v.clear();
	//}



	ChangeLevel(LEVEL_TYPE::START_LEVEL);
}

void CStartLevelEnterState::Exit()
{


}
