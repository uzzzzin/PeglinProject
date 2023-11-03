#include "pch.h"
#include "CBoardEditLevel.h"

#include "CEngine.h"

#include "CCamera.h"
#include "CKeyMgr.h"
#include "CLevelMgr.h"
#include "CLogMgr.h"

#include "CGreyPeg.h"

void CBoardEditLevel::init()
{
}

void CBoardEditLevel::enter()
{
	LOG(LOGLOG, L"BoardEditLevel ����");

	Vec2 vLookAt = CEngine::GetInst()->GetResolution();
	vLookAt /= 2.f;
	CCamera::GetInst()->SetLookAt(vLookAt);

	CGreyPeg* testPeg = new CGreyPeg;
	testPeg->SetPos(REALCENTER);
	testPeg->SetScale(Vec2(20, 20));
	AddObject(PEG, testPeg);

}

void CBoardEditLevel::exit()
{
	LOG(LOGLOG, L"BoardEditLevel ��������");
	DeleteAllObjects();
}

void CBoardEditLevel::tick()
{
	CLevel::tick();

	// Enter Ű�� ������ PlayLevel �� ��ȯ
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeLevel(LEVEL_TYPE::STAGE_1_LEVEL);
	}
}
