#include "pch.h"
#include "CBoardEditLevel.h"

#include "CEngine.h"

#include "CCamera.h"
#include "CKeyMgr.h"
#include "CLevelMgr.h"
#include "CPathMgr.h"
#include "CLogMgr.h"

#include "CImg.h"
#include "CBtnUI.h"
#include "CEditBoardUI.h"
#include "CEditPegUI.h"

#include "CStartBG.h"
#include "CGreyPeg.h"
#include "CCoinPeg.h"
#include "CCritPeg.h"
#include "CRefreshPeg.h"
#include "CBombPeg.h"

#include "resource.h"


void CBoardEditLevel::init()
{
}

void CBoardEditLevel::enter()
{
	LOG(LOGLOG, L"BoardEditLevel 들어옴");

	Vec2 vLookAt = CEngine::GetInst()->GetResolution();
	vLookAt /= 2.f;
	CCamera::GetInst()->SetLookAt(vLookAt);

	//CStartBG* pStartBG = new CStartBG;
	//pStartBG->SetPos(Vec2(912.f, 585.f));
	//pStartBG->SetScale(Vec2(800.f, 630.f));
	//AddObject(BG, pStartBG);;



	CEditBoardUI* pStartBG = new CEditBoardUI;
	pStartBG->SetPos(Vec2(512.f, 300.f));
	pStartBG->SetScale(Vec2(800.f, 630.f));
	pStartBG->SetNormalImg(L"animdata\\BoardBGBtn.txt", L"BoardBGBtn");
	pStartBG->SetHoverImg(L"animdata\\BoardBGBtn.txt", L"BoardBGBtn");
	pStartBG->SetPressedImg(L"animdata\\BoardBGBtn.txt", L"BoardBGBtn");
	AddObject(UI, pStartBG);


	CImg* pForest = new CImg;
	pForest->SetPos(Vec2(800.f, 150.f));
	pForest->SetScale(Vec2(1600.f, 300.f));
	pForest->SetImg(L"animdata\\Forest.txt", L"Forest");
	AddObject(PLATFORM, pForest);

	CImg* pLWall = new CImg;
	pLWall->SetPos(Vec2(444.5f, 585.f));
	pLWall->SetScale(Vec2(135.f, 630.f));
	pLWall->SetImg(L"animdata\\LWall.txt", L"LWall");
	AddObject(BG, pLWall);

	CImg* pRWall = new CImg;
	pRWall->SetPos(Vec2(1334.5f, 585.f));
	pRWall->SetScale(Vec2(45.f, 630.f));
	pRWall->SetImg(L"animdata\\RWall.txt", L"RWall");
	AddObject(BG, pRWall);

	CImg* pQueueHead = new CImg;
	pQueueHead->SetPos(Vec2(444.5f, 350.f));
	pQueueHead->SetScale(Vec2(100.f, 100.f));
	pQueueHead->SetImg(L"animdata\\QueueHead.txt", L"QueueHead");
	AddObject(PLATFORM, pQueueHead);

	CBtnUI* BoardSaveBtn = new CBtnUI;
	BoardSaveBtn->SetPos(Vec2(1408.f, 400.f));
	BoardSaveBtn->SetScale(Vec2(150.f, 50.f)); // 45*12
	BoardSaveBtn->SetNormalImg(L"animdata\\BoardSaveBtnOUH.txt", L"BoardSaveBtnOUH");
	BoardSaveBtn->SetHoverImg(L"animdata\\BoardSaveBtnOH.txt", L"BoardSaveBtnOH");
	BoardSaveBtn->SetPressedImg(L"animdata\\BoardSaveBtnOH.txt", L"BoardSaveBtnOH");
	BoardSaveBtn->SetDeletage(this, (DelegateFunc)&CBoardEditLevel::SaveBoard);
	AddObject(UI, BoardSaveBtn);


	CBtnUI* BoardLoadBtn = new CBtnUI;
	BoardLoadBtn->SetPos(Vec2(1408.f, 480.f));
	BoardLoadBtn->SetScale(Vec2(150.f, 50.f)); // 45*12
	BoardLoadBtn->SetNormalImg(L"animdata\\BoardLoadBtnOUH.txt", L"BoardLoadBtnOUH");
	BoardLoadBtn->SetHoverImg(L"animdata\\BoardLoadBtnOH.txt", L"BoardLoadBtnOH");
	BoardLoadBtn->SetPressedImg(L"animdata\\BoardLoadBtnOH.txt", L"BoardLoadBtnOH");
	BoardLoadBtn->SetDeletage(this, (DelegateFunc)&CBoardEditLevel::LoadBoard);
	AddObject(UI, BoardLoadBtn);


	// Queue Peg --------------------------------------------------------------------------
	CBtnUI* GreyPegBtn = new CBtnUI;
	GreyPegBtn->SetPos(Vec2(432.5f, 450.f));
	GreyPegBtn->SetScale(Vec2(24, 24));
	GreyPegBtn->SetNormalImg(L"animdata\\firstGreyPegBtn.txt", L"firstGreyPegBtn");
	GreyPegBtn->SetHoverImg(L"animdata\\GreyPegBtn.txt", L"GreyPegBtn");
	GreyPegBtn->SetPressedImg(L"animdata\\GreyPegBtn.txt", L"GreyPegBtn");
	GreyPegBtn->SetCallBack([]() { ChangePeg(PEG_TYPE::GREY_PEG);});
	AddObject(UI, GreyPegBtn);


	CBtnUI* CoinPegBtn = new CBtnUI;
	CoinPegBtn->SetPos(Vec2(432.5f, 480.f));
	CoinPegBtn->SetScale(Vec2(24, 24));
	CoinPegBtn->SetNormalImg(L"animdata\\CoinPegBtn.txt", L"CoinPegBtn");
	CoinPegBtn->SetHoverImg(L"animdata\\CoinPegBtn.txt", L"CoinPegBtn");
	CoinPegBtn->SetPressedImg(L"animdata\\CoinPegBtn.txt", L"CoinPegBtn");
	CoinPegBtn->SetCallBack([]() {ChangePeg(PEG_TYPE::COIN_PEG);});
	AddObject(UI, CoinPegBtn);

	CBtnUI* CritPegBtn = new CBtnUI;
	CritPegBtn->SetPos(Vec2(432.5f, 510.f));
	CritPegBtn->SetScale(Vec2(24, 24));
	CritPegBtn->SetNormalImg(L"animdata\\CritPegBtn.txt", L"CritPegBtn");
	CritPegBtn->SetHoverImg(L"animdata\\CritPegBtn.txt", L"CritPegBtn");
	CritPegBtn->SetPressedImg(L"animdata\\CritPegBtn.txt", L"CritPegBtn");
	CritPegBtn->SetCallBack([]() {ChangePeg(PEG_TYPE::CRITICAL_PEG);});
	AddObject(UI, CritPegBtn);

	CBtnUI* RefreshPegBtn = new CBtnUI;
	RefreshPegBtn->SetPos(Vec2(432.5f, 540.f));
	RefreshPegBtn->SetScale(Vec2(24, 24));
	RefreshPegBtn->SetNormalImg(L"animdata\\RefreshPegBtn.txt", L"RefreshPegBtn");
	RefreshPegBtn->SetHoverImg(L"animdata\\RefreshPegBtn.txt", L"RefreshPegBtn");
	RefreshPegBtn->SetPressedImg(L"animdata\\RefreshPegBtn.txt", L"RefreshPegBtn");
	RefreshPegBtn->SetCallBack([]() {ChangePeg(PEG_TYPE::REFRESH_PEG);});
	AddObject(UI, RefreshPegBtn);


	CBtnUI* BombPegBtn = new CBtnUI;
	BombPegBtn->SetPos(Vec2(432.5f, 570.f));
	BombPegBtn->SetScale(Vec2(36, 48));
	BombPegBtn->SetNormalImg(L"animdata\\BombPegBtn.txt", L"BombPegBtn");
	BombPegBtn->SetHoverImg(L"animdata\\BombPegBtn.txt", L"BombPegBtn");
	BombPegBtn->SetPressedImg(L"animdata\\BombPegBtn.txt", L"BombPegBtn");
	BombPegBtn->SetCallBack([]() {ChangePeg(PEG_TYPE::BOMB_PEG);});
	AddObject(UI, BombPegBtn);


	CBtnUI* SlimedGreyPegBtn = new CBtnUI;
	SlimedGreyPegBtn->SetPos(Vec2(432.5f, 600.f));
	SlimedGreyPegBtn->SetScale(Vec2(24, 24));
	SlimedGreyPegBtn->SetNormalImg(L"animdata\\SlimedGreyPegBtn.txt", L"SlimedGreyPegBtn");
	SlimedGreyPegBtn->SetHoverImg(L"animdata\\SlimedGreyPegBtn.txt", L"SlimedGreyPegBtn");
	SlimedGreyPegBtn->SetPressedImg(L"animdata\\SlimedGreyPegBtn.txt", L"SlimedGreyPegBtn");
	SlimedGreyPegBtn->SetCallBack([]() {ChangePeg(PEG_TYPE::SLIMED_GREY_PEG);});
	AddObject(UI, SlimedGreyPegBtn);

	CBtnUI* SlimedCoinPegBtn = new CBtnUI;
	SlimedCoinPegBtn->SetPos(Vec2(432.5f, 630.f));
	SlimedCoinPegBtn->SetScale(Vec2(24, 24));
	SlimedCoinPegBtn->SetNormalImg(L"animdata\\SlimedCoinPegBtn.txt", L"SlimedCoinPegBtn");
	SlimedCoinPegBtn->SetHoverImg(L"animdata\\SlimedCoinPegBtn.txt", L"SlimedCoinPegBtn");
	SlimedCoinPegBtn->SetPressedImg(L"animdata\\SlimedCoinPegBtn.txt", L"SlimedCoinPegBtn");
	SlimedCoinPegBtn->SetCallBack([]() {ChangePeg(PEG_TYPE::SLIMED_COIN_PEG);});
	AddObject(UI, SlimedCoinPegBtn);

}

void CBoardEditLevel::exit()
{
	LOG(LOGLOG, L"BoardEditLevel 빠져나감");
	DeleteAllObjects();
}

void CBoardEditLevel::tick()
{
	CLevel::tick();

	// Enter 키가 눌리면 PlayLevel 로 전환
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeLevel(LEVEL_TYPE::STAGE_1_LEVEL);
	}
}

void CBoardEditLevel::SaveBoard()
{
	int PegsCnt = vPegs.size();
	//FILE* pFile = nullptr;
	OPENFILENAME ofn = {};
	wstring strFolderPath = CPathMgr::GetContentPath();
	strFolderPath += L"Board\\";

	wchar_t szFilePath[256] = {};

	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFile = szFilePath;
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = 256;
	ofn.lpstrFilter =L"txt\0*.TXT\0ALL\0*.*";
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = strFolderPath.c_str();
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	if (false == GetSaveFileName(&ofn))
		return;


	FILE* pFile = nullptr;
	_wfopen_s(&pFile, szFilePath, L"w");

	if (nullptr == pFile)
	{
		LOG(ERR, L"파일 열기 실패");
		return;
	}
	//int validPegsSize = 0;;
	for(int i = 0; i < PegsCnt; ++i)
	{
		if (!(vPegs[i]->IsDead()))
		{
			fwprintf_s(pFile, L"[PEG_TYPE]\n");
			UINT peg_type = vPegs[i]->pegsInfo.type;
			wstring w_peg_type = std::to_wstring(peg_type);
			fwprintf_s(pFile, w_peg_type.c_str());
			fwprintf_s(pFile, L"\n");

			fwprintf_s(pFile, L"[PEG_POSITION]\n");
			fwprintf_s(pFile, L"%f %f", vPegs[i]->pegsInfo.pos.x, vPegs[i]->pegsInfo.pos.y);
			fwprintf_s(pFile, L"\n");

			fwprintf_s(pFile, L"[PEG_SCALE]\n");
			fwprintf_s(pFile, L"%f %f", vPegs[i]->pegsInfo.scale.x, vPegs[i]->pegsInfo.scale.y);
			fwprintf_s(pFile, L"\n\n");

			//++validPegsSize;
		}
	}
	fclose(pFile);
}

void CBoardEditLevel::LoadBoard()
{
	OPENFILENAME ofn = {};

	wstring strFolderPath = CPathMgr::GetContentPath();
	strFolderPath += L"Board\\";

	wchar_t szFilePath[256] = {};

	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFile = szFilePath;
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = 256;
	ofn.lpstrFilter = L"txt\0*.TXT\0ALL\0*.*";
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = strFolderPath.c_str();
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	if (false == GetOpenFileName(&ofn))
		return;

	for (int i = 0;i < vPegs.size(); ++i)
	{
		vPegs[i]->Destroy();
	}
	vPegs.clear();

	FILE* pFile = nullptr;
	_wfopen_s(&pFile, szFilePath, L"r");

	if (nullptr == pFile)
	{
		LOG(ERR, L"파일 열기 실패");
		return;
	}
	// 읽는 과정...
	while (true)
	{
		CEditPegUI* pPeg = new CEditPegUI;
		SavedPegsInfo pLoadPegsInfo = {};
		while (true)
		{
			wchar_t szRead[256] = {};

			if (EOF == fwscanf_s(pFile, L"%s", szRead, 256))
			{
				pPeg = nullptr;
				break;
			}

			if (!wcscmp(szRead, L"\n"))
			{
				if (!wcscmp(szRead, L"\n"))
				{
					break;
				}
			}
			else if (!wcscmp(szRead, L"[PEG_TYPE]"))
			{
				fwscanf_s(pFile, L"%s", szRead, 256);

				int p = (int)(szRead[0] - 48);
				pLoadPegsInfo.type = (PEG_TYPE)p;
			}
			else if (!wcscmp(szRead, L"[PEG_POSITION]"))
			{
				fwscanf_s(pFile, L"%f", &pLoadPegsInfo.pos.x);
				fwscanf_s(pFile, L"%f", &pLoadPegsInfo.pos.y);
			}
			else if (!wcscmp(szRead, L"[PEG_SCALE]"))
			{
				fwscanf_s(pFile, L"%f", &pLoadPegsInfo.scale.x);
				fwscanf_s(pFile, L"%f", &pLoadPegsInfo.scale.y);
				break;
			}
		}
		if (nullptr == pPeg)
		{
			break;
		}
		pPeg->SetPos(pLoadPegsInfo.pos);
		pPeg->SetScale(pLoadPegsInfo.scale);
		pPeg->SetPegsInfo(pLoadPegsInfo.type, pLoadPegsInfo.pos, pLoadPegsInfo.scale);

		switch (pLoadPegsInfo.type)
		{
			case PEG_TYPE::GREY_PEG:
			{
				pPeg->SetNormalImg(L"animdata\\firstGreyPegBtn.txt", L"firstGreyPegBtn");
				pPeg->SetHoverImg(L"animdata\\GreyPegBtn.txt", L"GreyPegBtn");
				pPeg->SetPressedImg(L"animdata\\GreyPegBtn.txt", L"GreyPegBtn");
				break;
			}
			case PEG_TYPE::COIN_PEG:
			{
				pPeg->SetNormalImg(L"animdata\\CoinPegBtn.txt", L"CoinPegBtn");
				pPeg->SetHoverImg(L"animdata\\CoinPegBtn.txt", L"CoinPegBtn");
				pPeg->SetPressedImg(L"animdata\\CoinPegBtn.txt", L"CoinPegBtn");
				break;
			}
			case PEG_TYPE::CRITICAL_PEG:
			{
				pPeg->SetNormalImg(L"animdata\\CritPegBtn.txt", L"CritPegBtn");
				pPeg->SetHoverImg(L"animdata\\CritPegBtn.txt", L"CritPegBtn");
				pPeg->SetPressedImg(L"animdata\\CritPegBtn.txt", L"CritPegBtn");
				break;
			}
			case PEG_TYPE::REFRESH_PEG:
			{
				pPeg->SetNormalImg(L"animdata\\RefreshPegBtn.txt", L"RefreshPegBtn");
				pPeg->SetHoverImg(L"animdata\\RefreshPegBtn.txt", L"RefreshPegBtn");
				pPeg->SetPressedImg(L"animdata\\RefreshPegBtn.txt", L"RefreshPegBtn");
				break;
			}
			case PEG_TYPE::BOMB_PEG:
			{
				pPeg->SetNormalImg(L"animdata\\BombPegBtn.txt", L"BombPegBtn");
				pPeg->SetHoverImg(L"animdata\\BombPegBtn.txt", L"BombPegBtn");
				pPeg->SetPressedImg(L"animdata\\BombPegBtn.txt", L"BombPegBtn");
				break;
			}
			case PEG_TYPE::SLIMED_GREY_PEG:
			{
				pPeg->SetNormalImg(L"animdata\\SlimedGreyPegBtn.txt", L"SlimedGreyPegBtn");
				pPeg->SetHoverImg(L"animdata\\SlimedGreyPegBtn.txt", L"SlimedGreyPegBtn");
				pPeg->SetPressedImg(L"animdata\\SlimedGreyPegBtn.txt", L"SlimedGreyPegBtn");
				break;
			}
			case PEG_TYPE::SLIMED_COIN_PEG:
			{
				pPeg->SetNormalImg(L"animdata\\SlimedCoinPegBtn.txt", L"SlimedCoinPegBtn");
				pPeg->SetHoverImg(L"animdata\\SlimedCoinPegBtn.txt", L"SlimedCoinPegBtn");
				pPeg->SetPressedImg(L"animdata\\SlimedCoinPegBtn.txt", L"SlimedCoinPegBtn");
				break;
			}
			default:
			{
				break;
			}
	}
	AddObject(UI, pPeg);
	PushBack_Pegs(pPeg);	
	}
		fclose(pFile);
}
