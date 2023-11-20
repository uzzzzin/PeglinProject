#include "pch.h"
#include "CLevel.h"

#include "CTimeMgr.h"
#include "CPathMgr.h"
#include "CLevelMgr.h"
#include "CLayer.h"
#include "CObj.h"
#include "CTile.h"

#include "CGreyPeg.h"
#include "CCoinPeg.h"
#include "CCritPeg.h"
#include "CRefreshPeg.h"
#include "CBombPeg.h"
#include "COrb.h"

CLevel::CLevel()
	 : m_TileRow(0)
	, m_TileCol(0)
{
	for (UINT i = 0; i < LAYER::END; ++i)
	{
		m_Layer[i] = new CLayer;
	}
}

CLevel::~CLevel()
{
	for (UINT i = 0; i < LAYER::END; ++i)
	{
		if (nullptr != m_Layer[i])
			delete m_Layer[i];
	}
}

void CLevel::begin()
{
	for (UINT i = 0; i < LAYER::END; ++i)
	{
		m_Layer[i]->begin();
	}
}

void CLevel::tick()
{
	for (UINT i = 0; i < LAYER::END; ++i)
	{
		m_Layer[i]->clear();
	}


	for (UINT i = 0; i < LAYER::END; ++i)
	{
		m_Layer[i]->tick(DT);
	}

	for (UINT i = 0; i < LAYER::END; ++i)
	{
		m_Layer[i]->finaltick(DT);
	}
}

void CLevel::render(HDC _dc)
{
	for (UINT i = 0; i < LAYER::END; ++i)
	{
		m_Layer[i]->render(_dc);
	}
}

void CLevel::AddObject(LAYER _LayerType, CObj* _Object)
{
	// 레이어에 오브젝트를 집어넣는다.
	m_Layer[_LayerType]->AddObject(_Object);

	// 레이어 인덱스값을 오브젝트에 세팅해준다(오브젝트가 자신이 소속된 레이어 인덱스를 알게 한다)
	_Object->m_iLayerIdx = _LayerType;
}

void CLevel::DeleteAllObjects()
{
	for (UINT i = 0; i < LAYER::END; ++i)
	{
		m_Layer[i]->DeleteAllObjects();
	}
}

void CLevel::DeleteObjectsByLayer(LAYER _Layer)
{
	m_Layer[_Layer]->DeleteAllObjects();
}

void CLevel::CreateTile(UINT _Row, UINT _Col)
{
	DeleteObjectsByLayer(LAYER::TILE);

	m_TileRow = _Row;
	m_TileCol = _Col;

	for (UINT i = 0; i < _Row; ++i)
	{
		for (UINT j = 0; j < _Col; ++j)
		{
			CTile* pTile = new CTile;

			pTile->SetPos(Vec2(TILE_SIZE * j, TILE_SIZE * i));

			AddObject(LAYER::TILE, pTile);
		}
	}
}

CObj* CLevel::FindObjectByName(const wstring& _Name)
{
	for (UINT i = 0; i < LAYER::END; ++i)
	{
		const vector<CObj*>& vecObjects = m_Layer[i]->GetObjects();
		for (size_t j = 0; j < vecObjects.size(); ++j)
		{
			if (vecObjects[j]->GetName() == _Name)
			{
				return vecObjects[j];
			}
		}
	}

	return nullptr;
}

//ORB_TYPE CLevel::GetCurOrbType()
//{
//	return  CLevelMgr::GetInst()->GetCurLevel()->GetCurOrbType();
//}

void CLevel::LoadPegs(const wstring& _strRelativePath)
{
	wstring strFilePath = CPathMgr::GetContentPath();
	strFilePath += _strRelativePath;

	FILE* pFile = nullptr;
	_wfopen_s(&pFile, strFilePath.c_str(), L"r");

	if (nullptr == pFile)
	{
		LOG(ERR, L"파일 열기 실패");
		return;
	}
	CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();
	SavedPegsInfo peg = {};

	while (true)
	{
		wchar_t szRead[256] = {};
		if (EOF == fwscanf_s(pFile, L"%s", szRead, 256))
		{
			break;
		}
		if (!wcscmp(szRead, L"\n"))
		{
			if (!wcscmp(szRead, L"\n"))
			{
				break;
			}
		}
		//while (true)
		//{

		else if (!wcscmp(szRead, L"[PEG_TYPE]"))
		{
		fwscanf_s(pFile, L"%s", szRead, 256);
		int p = (int)(szRead[0] - 48);
		peg.type = (PEG_TYPE)p;
		//fwscanf_s(pFile, L"%d", &peg.type);
				
		}
		else if (!wcscmp(szRead, L"[PEG_POSITION]"))
		{
			fwscanf_s(pFile, L"%f", &peg.pos.x);
			fwscanf_s(pFile, L"%f", &peg.pos.y);
		}
		else if (!wcscmp(szRead, L"[PEG_SCALE]"))
		{
			fwscanf_s(pFile, L"%f", &peg.scale.x);
			fwscanf_s(pFile, L"%f", &peg.scale.y);

			switch (peg.type)
			{
			case GREY_PEG:
			{
				CGreyPeg* realPeg = new CGreyPeg;
				realPeg->SetPos(peg.pos);
				realPeg->SetScale(peg.scale);
				pCurLevel->AddObject(PEG, realPeg);
				pegs.push_back(realPeg);
				break;
			}
			case COIN_PEG:
			{
				CCoinPeg* realPeg = new CCoinPeg;
				realPeg->SetPos(peg.pos);
				realPeg->SetScale(peg.scale);
				pCurLevel->AddObject(PEG, realPeg);
				pegs.push_back(realPeg);
				break;
			}
			case CRITICAL_PEG:
			{
				CCritPeg* realPeg = new CCritPeg;
				realPeg->SetPos(peg.pos);
				realPeg->SetScale(peg.scale);
				pCurLevel->AddObject(PEG, realPeg);
				pegs.push_back(realPeg);
				break;
			}
			case REFRESH_PEG:
			{
				CRefreshPeg* realPeg = new CRefreshPeg;
				realPeg->SetPos(peg.pos);
				realPeg->SetScale(peg.scale);
				pCurLevel->AddObject(PEG, realPeg);
				pegs.push_back(realPeg);

				break;
			}
			case BOMB_PEG:
			{
				CBombPeg* realPeg = new CBombPeg;
				realPeg->SetPos(peg.pos);
				realPeg->SetScale(peg.scale);
				pCurLevel->AddObject(PEG, realPeg);
				pegs.push_back(realPeg);

				break;
			}
			case SLIMED_GREY_PEG:
			{
				CGreyPeg* realPeg = new CGreyPeg;
				realPeg->SetPos(peg.pos);
				realPeg->SetScale(peg.scale);
				realPeg->SetbSlimed(true);
				pCurLevel->AddObject(PEG, realPeg);
				pegs.push_back(realPeg);
				break;
			}
			case SLIMED_COIN_PEG:
			{
				CCoinPeg* realPeg = new CCoinPeg;
				realPeg->SetPos(peg.pos);
				realPeg->SetScale(peg.scale);
				realPeg->SetbSlimed(true);
				pCurLevel->AddObject(PEG, realPeg);
				pegs.push_back(realPeg);
				break;
			}
			default:
			{
				break;
			}
			break;
		}

		//}

		

		}

	}


	fclose(pFile);


}
