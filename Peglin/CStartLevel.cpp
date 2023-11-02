#include "pch.h"
#include "CStartLevel.h"

#include "CEngine.h"

#include "CKeyMgr.h"
#include "CLevelMgr.h"
#include "CLogMgr.h"

#include "CStartBG.h"
#include "CStartLogo.h"
#include "CBtnUI.h"

void CStartLevel::init()
{
}

void CStartLevel::enter()
{
	LOG( LOGLOG, L"StartLevel 들어옴");

	// 카메라 설정
	Vec2 vLookAt = CEngine::GetInst()->GetResolution();
	vLookAt /= 2.f;
	CCamera::GetInst()->SetLookAt(vLookAt);

	CStartBG* pStartBG = new CStartBG;
	pStartBG->SetPos(Vec2(400.f, 450.f));
	pStartBG->SetScale(Vec2(800.f,900.f));
	AddObject(BG, pStartBG);

	CStartBG* pStartBG2 = new CStartBG;
	pStartBG2->SetPos(Vec2(1200.f, 450.f));
	pStartBG2->SetScale(Vec2(800.f,900.f));
	AddObject(BG, pStartBG2);

	CStartLogo* pLogo = new CStartLogo;
	pLogo->SetScaleCoeffi(7);
	float fScaleCoeffi = pLogo->GetfScaleCoeffi();
	pLogo->SetPos(Vec2(800.f, 250.f)); 
	pLogo->SetScale(Vec2(129.f* fScaleCoeffi, 48.f * fScaleCoeffi)); // 원본 컷 사이즈에 곱함
	AddObject(BG, pLogo); // 어디에 넣어야 하는지 애매

	int mul = 3;
	CBtnUI* pNewGameBtn = new CBtnUI;
	pNewGameBtn->SetPos(Vec2(800.f - (81 * mul) / 2, 500.f - (29 * mul) / 2));
	pNewGameBtn->SetScale(Vec2(81*mul, 29*mul));
	pNewGameBtn->SetNormalImg(L"NewGameNBtnImg", L"texture\\newGameTextOUH.png", L"NewGameNBtnAnim",L"animdata\\NewGameNBtn.txt", L"NewGameNBtn");
	pNewGameBtn->SetHoverImg(L"NewGameHBtnImg", L"texture\\newGameTextOH.png", L"NewGameHBtnAnim", L"animdata\\NewGameHBtn.txt",L"NewGameHBtn");
	pNewGameBtn->SetPressedImg(L"NewGamePBtnImg", L"texture\\newGameTextOH.png", L"NewGamePBtnAnim", L"animdata\\NewGamePBtn.txt", L"NewGamePBtn");
	pNewGameBtn->SetCallBack([]() {ChangeLevel(LEVEL_TYPE::STAGE_1_LEVEL);});
	AddObject(UI, pNewGameBtn);

	CBtnUI* pExitGameBtn = new CBtnUI;
	pExitGameBtn->SetPos(Vec2(800.f-(97*mul)/2, 700.f - (26 * mul)));
	pExitGameBtn->SetScale(Vec2(97 * mul, 26 * mul));
	pExitGameBtn->SetNormalImg(L"ExitGameNBtnImg", L"texture\\exitTextOH.png", L"exitTextOUHAnim", L"animdata\\ExitGameNBtn.txt", L"ExitGameNBtn");
	pExitGameBtn->SetHoverImg(L"ExitGameHBtnImg", L"texture\\exitTextOH.png", L"exitTextOHAnim", L"animdata\\ExitGameHBtn.txt", L"ExitGameHBtn");
	pExitGameBtn->SetPressedImg(L"ExitGamePBtnImg", L"texture\\exitTextOH.png", L"exitTextOHAnim", L"animdata\\ExitGamePBtn.txt", L"ExitGamePBtn");
	pExitGameBtn->SetCallBack([]() {DestroyWindow(CEngine::GetInst()->GetMainWind());});
	AddObject(UI, pExitGameBtn);


}

void CStartLevel::exit()
{
	LOG( LOGLOG, L"StartLevel 빠져나감");
	DeleteAllObjects();
}

void CStartLevel::tick()
{
	CLevel::tick();

	// Enter 키가 눌리면 PlayLevel 로 전환
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeLevel(LEVEL_TYPE::STAGE_1_LEVEL);
	}
}
