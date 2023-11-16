#include "pch.h"
#include "CEnemy.h"

CEnemy::CEnemy()
	: EnemyInitInfo{}
	, m_Animator(nullptr)
	, m_Movement(nullptr)
{
}

CEnemy::~CEnemy()
{
}

void CEnemy::tick(float _DT)
{
}
