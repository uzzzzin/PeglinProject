#include "pch.h"
#include "CAssetMgr.h"

#include "CPathMgr.h"
#include "CTexture.h"
#include "CSound.h"


CAssetMgr::CAssetMgr()
{

}

CAssetMgr::~CAssetMgr()
{
	for (const auto& pair : m_mapTex)
	{
		delete pair.second;
	}

	for (const auto& pair : m_mapSound)
	{
		delete pair.second;
	}
}

CTexture* CAssetMgr::LoadTexture(const wstring& _strKey, const wstring& _strRelativePath)
{
	// �Էµ� Ű�� �ش��ϴ� �ؽ��İ� �ִ��� Ȯ���Ѵ�.
	CTexture* pTexture = FindTexture(_strKey);
	if (nullptr != pTexture)
	{
		// �̹� �ִ� �ؽ��ĸ� ã���� ��ȯ���ش�.
		return pTexture;
	}

	// �Էµ� Ű�� �ش��ϴ� �ؽ��İ� ������ �ε��ؼ� ��ȯ���ش�.
	wstring strContentPath = CPathMgr::GetContentPath();
	wstring strFilePath = strContentPath + _strRelativePath;

	pTexture = new CTexture;

	if (!pTexture->Load(strFilePath))
	{
		// �ؽ��� �ε尡 ������ ���(��� ���� ���..)
		delete pTexture;
		return nullptr;
	}

	// Asset �� Ű���� ��ΰ��� �˷��ش�.
	pTexture->m_strKey = _strKey;
	pTexture->m_strRelativePath = _strRelativePath;

	m_mapTex.insert(make_pair(_strKey, pTexture));

	return pTexture;
}

CTexture* CAssetMgr::CreateTexture(const wstring& _strKey, UINT _width, UINT _height)
{
	// �Էµ� Ű�� �ش��ϴ� �ؽ��İ� �ִ��� Ȯ���Ѵ�.
	CTexture* pTexture = FindTexture(_strKey);
	if (nullptr != pTexture)
	{
		// �̹� �ִ� �ؽ��ĸ� ã���� ��ȯ���ش�.
		return pTexture;
	}

	pTexture = new CTexture;
	pTexture->Create(_width, _height);

	// Asset �� Ű���� ��ΰ��� �˷��ش�.
	pTexture->m_strKey = _strKey;
	m_mapTex.insert(make_pair(_strKey, pTexture));
	return pTexture;
}

CTexture* CAssetMgr::FindTexture(const wstring& _strKey)
{
	map<wstring, CTexture*>::iterator iter = m_mapTex.find(_strKey);

	if (iter == m_mapTex.end())
	{
		return nullptr;
	}

	return iter->second;
}

CSound* CAssetMgr::LoadSound(const wstring& _strKey, const wstring& _strRelativePath)
{
	// �Էµ� Ű�� �ش��ϴ� �ؽ��İ� �ִ��� Ȯ���Ѵ�.
	CSound* pSound = FindSound(_strKey);
	if (nullptr != pSound)
	{
		// �̹� �ִ� �ؽ��ĸ� ã���� ��ȯ���ش�.
		return pSound;
	}

	// �Էµ� Ű�� �ش��ϴ� �ؽ��İ� ������ �ε��ؼ� ��ȯ���ش�.
	wstring strContentPath = CPathMgr::GetContentPath();
	wstring strFilePath = strContentPath + _strRelativePath;

	pSound = new CSound;

	if (!pSound->Load(strFilePath))
	{
		// �ؽ��� �ε尡 ������ ���(��� ���� ���..)
		delete pSound;
		return nullptr;
	}

	// Asset �� Ű���� ��ΰ��� �˷��ش�.
	pSound->m_strKey = _strKey;
	pSound->m_strRelativePath = _strRelativePath;

	m_mapSound.insert(make_pair(_strKey, pSound));

	return pSound;
}

CSound* CAssetMgr::FindSound(const wstring& _strKey)
{
	map<wstring, CSound*>::iterator iter = m_mapSound.find(_strKey);

	if (iter == m_mapSound.end())
	{
		return nullptr;
	}

	return iter->second;
}
