#include "pch.h"
#include "CEngine.h"
#include "CLevelMgr.h"

#include "CBoardEditLevel.h"
#include "CEditBoardUI.h"
#include "CEditBoardUI.h"
#include "CEditPegUI.h"
#include "CImg.h"


CEditBoardUI::CEditBoardUI()
{
	SetName(L"Board");
}

CEditBoardUI::~CEditBoardUI()
{
}

PEG_TYPE pegType;
void ChangePeg(PEG_TYPE _type)
{
	pegType = _type;
}

void CEditBoardUI::LBtnClicked(Vec2 _vMousePos)
{
	CBoardEditLevel* pCurLevel = dynamic_cast<CBoardEditLevel*>(CLevelMgr::GetInst()->GetCurLevel());
	
	switch (pegType)
	{
		case PEG_TYPE::GREY_PEG:
		{
			CEditPegUI* GreyPegBtn = new CEditPegUI;
			GreyPegBtn->SetPos(_vMousePos);
			GreyPegBtn->SetScale(Vec2(24, 24));
			GreyPegBtn->SetNormalImg(L"animdata\\firstGreyPegBtn.txt", L"firstGreyPegBtn");
			GreyPegBtn->SetHoverImg(L"animdata\\GreyPegBtn.txt", L"GreyPegBtn");
			GreyPegBtn->SetPressedImg(L"animdata\\GreyPegBtn.txt", L"GreyPegBtn");
			GreyPegBtn->SetPegsInfo(GREY_PEG, _vMousePos, GreyPegBtn->GetScale());
			pCurLevel->AddObject(UI, GreyPegBtn);
			pCurLevel->PushBack_Pegs(GreyPegBtn);
			break;
		}
		case PEG_TYPE::COIN_PEG:
		{
			CEditPegUI* CoinPegBtn = new CEditPegUI;
			CoinPegBtn->SetPos(_vMousePos);
			CoinPegBtn->SetScale(Vec2(24, 24));
			CoinPegBtn->SetNormalImg(L"animdata\\CoinPegBtn.txt", L"CoinPegBtn");
			CoinPegBtn->SetHoverImg(L"animdata\\CoinPegBtn.txt", L"CoinPegBtn");
			CoinPegBtn->SetPressedImg(L"animdata\\CoinPegBtn.txt", L"CoinPegBtn");
			CoinPegBtn->SetPegsInfo(COIN_PEG, _vMousePos, CoinPegBtn->GetScale());
			pCurLevel->AddObject(UI, CoinPegBtn);
			pCurLevel->PushBack_Pegs(CoinPegBtn);
			break;
		}
		case PEG_TYPE::CRITICAL_PEG:
		{
			CEditPegUI* CritPegBtn = new CEditPegUI;
			CritPegBtn->SetPos(_vMousePos);
			CritPegBtn->SetScale(Vec2(24, 24));
			CritPegBtn->SetNormalImg(L"animdata\\CritPegBtn.txt", L"CritPegBtn");
			CritPegBtn->SetHoverImg(L"animdata\\CritPegBtn.txt", L"CritPegBtn");
			CritPegBtn->SetPressedImg(L"animdata\\CritPegBtn.txt", L"CritPegBtn");
			CritPegBtn->SetPegsInfo(CRITICAL_PEG, _vMousePos, CritPegBtn->GetScale());
			pCurLevel->AddObject(UI, CritPegBtn);
			pCurLevel->PushBack_Pegs(CritPegBtn);
			break;
		}
		case PEG_TYPE::REFRESH_PEG:
		{
			CEditPegUI* RefreshPegBtn = new CEditPegUI;
			RefreshPegBtn->SetPos(_vMousePos);
			RefreshPegBtn->SetScale(Vec2(24, 24));
			RefreshPegBtn->SetNormalImg(L"animdata\\RefreshPegBtn.txt", L"RefreshPegBtn");
			RefreshPegBtn->SetHoverImg(L"animdata\\RefreshPegBtn.txt", L"RefreshPegBtn");
			RefreshPegBtn->SetPressedImg(L"animdata\\RefreshPegBtn.txt", L"RefreshPegBtn");
			RefreshPegBtn->SetPegsInfo(REFRESH_PEG, _vMousePos, RefreshPegBtn->GetScale());
			pCurLevel->AddObject(UI, RefreshPegBtn);
			pCurLevel->PushBack_Pegs(RefreshPegBtn);
			break;
		}
		case PEG_TYPE::BOMB_PEG:
		{
			CEditPegUI* BombPegBtn = new CEditPegUI;
			BombPegBtn->SetPos(_vMousePos); // offset = x-10, y-20
			BombPegBtn->SetScale(Vec2(36, 48));
			BombPegBtn->SetNormalImg(L"animdata\\BombPegBtn.txt", L"BombPegBtn");
			BombPegBtn->SetHoverImg(L"animdata\\BombPegBtn.txt", L"BombPegBtn");
			BombPegBtn->SetPressedImg(L"animdata\\BombPegBtn.txt", L"BombPegBtn");
			BombPegBtn->SetPegsInfo(BOMB_PEG, _vMousePos, BombPegBtn->GetScale());
			pCurLevel->AddObject(UI, BombPegBtn);
			pCurLevel->PushBack_Pegs(BombPegBtn);
			break;
		}
		case PEG_TYPE::SLIMED_GREY_PEG:
		{
			CEditPegUI* SlimedGreyPegBtn = new CEditPegUI;
			SlimedGreyPegBtn->SetPos(_vMousePos); // offset = x-10, y-20
			SlimedGreyPegBtn->SetScale(Vec2(24, 24));
			SlimedGreyPegBtn->SetNormalImg(L"animdata\\SlimedGreyPegBtn.txt", L"SlimedGreyPegBtn");
			SlimedGreyPegBtn->SetHoverImg(L"animdata\\SlimedGreyPegBtn.txt", L"SlimedGreyPegBtn");
			SlimedGreyPegBtn->SetPressedImg(L"animdata\\SlimedGreyPegBtn.txt", L"SlimedGreyPegBtn");
			SlimedGreyPegBtn->SetPegsInfo(SLIMED_GREY_PEG, _vMousePos, SlimedGreyPegBtn->GetScale());
			pCurLevel->AddObject(UI, SlimedGreyPegBtn);
			pCurLevel->PushBack_Pegs(SlimedGreyPegBtn);
			break;
		}
		case PEG_TYPE::SLIMED_COIN_PEG:
		{
			CEditPegUI* SlimedCoinPegBtn = new CEditPegUI;
			SlimedCoinPegBtn->SetPos(_vMousePos); // offset = x-10, y-20
			SlimedCoinPegBtn->SetScale(Vec2(24, 24));
			SlimedCoinPegBtn->SetNormalImg(L"animdata\\SlimedCoinPegBtn.txt", L"SlimedCoinPegBtn");
			SlimedCoinPegBtn->SetHoverImg(L"animdata\\SlimedCoinPegBtn.txt", L"SlimedCoinPegBtn");
			SlimedCoinPegBtn->SetPressedImg(L"animdata\\SlimedCoinPegBtn.txt", L"SlimedCoinPegBtn");
			SlimedCoinPegBtn->SetPegsInfo(SLIMED_COIN_PEG, _vMousePos, SlimedCoinPegBtn->GetScale());
			pCurLevel->AddObject(UI, SlimedCoinPegBtn);
			pCurLevel->AddObject(UI, SlimedCoinPegBtn);
			break;
		}
		default:
		{
			break;
		}
	}

}




