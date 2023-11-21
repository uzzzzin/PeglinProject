#include "pch.h"
#include "CEndLevel.h"

#include "CEngine.h"
#include "CKeyMgr.h"
#include "CCamera.h"


#include "CKeyMgr.h"
#include "CLevelMgr.h"
#include "CLogMgr.h"
#include "CImg.h"
#include "CBtnUI.h"

void CEndLevel::init()
{
}

void CEndLevel::enter()
{
	LOG(LOGLOG, L"EndLevel 들어옴");
	Vec2 vLookAt = CEngine::GetInst()->GetResolution();
	vLookAt /= 2.f;
	CCamera::GetInst()->SetLookAt(vLookAt);

	CImg* pBG = new CImg;
	pBG->SetPos(REALCENTER);
	pBG->SetScale(Vec2(1600.f, 900.f));
	pBG->SetImg(L"animdata\\EndLevel.txt", L"EndLevel");
	AddObject(BG, pBG);

	int mul = 3;
	CBtnUI* pNewGameBtn = new CBtnUI;
	pNewGameBtn->SetPos(Vec2(400.f, 140.f));
	pNewGameBtn->SetScale(Vec2(81 * mul, 29 * mul));
	pNewGameBtn->SetNormalImg(L"animdata\\NewGameNBtn.txt", L"NewGameNBtn");
	pNewGameBtn->SetHoverImg(L"animdata\\NewGameHBtn.txt", L"NewGameHBtn");
	pNewGameBtn->SetPressedImg(L"animdata\\NewGamePBtn.txt", L"NewGamePBtn");
	pNewGameBtn->SetCallBack([]() {ChangeLevel(LEVEL_TYPE::STAGE_1_LEVEL);});
	AddObject(UI, pNewGameBtn);

	CBtnUI* pExitGameBtn = new CBtnUI;
	pExitGameBtn->SetPos(Vec2(960.f, 140.f));
	pExitGameBtn->SetScale(Vec2(97 * mul, 26 * mul));
	pExitGameBtn->SetNormalImg(L"animdata\\ExitGameNBtn.txt", L"ExitGameNBtn");
	pExitGameBtn->SetHoverImg(L"animdata\\ExitGameHBtn.txt", L"ExitGameHBtn");
	pExitGameBtn->SetPressedImg(L"animdata\\ExitGamePBtn.txt", L"ExitGamePBtn");
	pExitGameBtn->SetCallBack([]() {DestroyWindow(CEngine::GetInst()->GetMainWind());});
	AddObject(UI, pExitGameBtn);

}

void CEndLevel::exit()
{
	LOG(LOGLOG, L"EndLevel 빠져나감");
	DeleteAllObjects();
}

void CEndLevel::tick()
{
	CLevel::tick();

	// Enter 키가 눌리면 PlayLevel 로 전환
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeLevel(LEVEL_TYPE::BOARD_EDIT_LEVEL);
	}
}
