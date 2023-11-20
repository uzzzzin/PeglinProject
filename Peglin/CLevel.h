#pragma once

#include "CEntity.h"

#include "CLayer.h"

class CObj;

class CLevel
	: public CEntity
{
private:
	CLayer* m_Layer[LAYER::END];

	UINT	m_TileRow;
	UINT	m_TileCol;

	vector<class CPeg*> pegs;


public:
	virtual void init() = 0;
	virtual void enter() = 0;
	virtual void exit() = 0;

	virtual void begin();
	virtual void tick();
	virtual void render(HDC _dc);

	// ������ �����ϰ� �ִ� ��� ���̾ ��ȸ�ϸ鼭 T Ÿ�Կ� �ش��ϴ� ��ü�� ã�Ƽ� ���(_Out) ���Ϳ� ����ش�.
	template<typename T>
	void GetObjects(vector<T*>& _Out);

	// ������ �����ϰ� �ִ� Ư�� ���̾��� ������Ʈ ����� ��ȯ�Ѵ�.
	const vector<CObj*>& GetObjects(LAYER _LayerType) { return m_Layer[_LayerType]->m_vecObjects; }

	CLayer* GetLayer(int LayerIdx)
	{
		assert(!(LayerIdx < 0 || LAYER::END <= LayerIdx));
		return m_Layer[LayerIdx];
	}

protected:
	void AddObject(LAYER _LayerType, CObj* _Object);
	void DeleteAllObjects();
	void DeleteObjectsByLayer(LAYER _Layer);

public:
	void CreateTile(UINT _Row, UINT _Col);
	UINT GetTileCol() { return m_TileCol; }
	UINT GetTileRow() { return m_TileRow; }

	vector<CPeg*> GetPegs()
	{
		return pegs;
	}

	CObj* FindObjectByName(const wstring& _Name);

	//ORB_TYPE GetCurOrbType();
	void LoadPegs(const wstring& _strRelativePath); // L"Board//~~~.txt"

public:
	CLONE_DISABLE(CLevel);
	CLevel();
	CLevel(const CLevel& _Origin) = delete;
	~CLevel();

	friend class CLevelMgr;
	friend class CTaskMgr;
	friend class CEditBoardUI;
};

template<typename T>
inline void CLevel::GetObjects(vector<T*>& _Out)
{
	for (UINT j = 0; j < LAYER::END; ++j)
	{
		for (size_t i = 0; i < m_Layer[j]->m_vecObjects.size(); ++i)
		{
			T* pObj = dynamic_cast<T*>(m_Layer[j]->m_vecObjects[i]);

			if (nullptr != pObj)
			{
				_Out.push_back(pObj);
			}
		}
	}
}
