#include "pch.h"
#include "CAnim.h"

#include "CAnimator.h"
#include "CObj.h"
#include "CCamera.h"
#include "CTexture.h"
#include "CTimeMgr.h"
#include "CLogMgr.h"
#include "CAssetMgr.h"


CAnim::CAnim()
	: m_pAnimator(nullptr)
	, m_Atlas(nullptr)
	, m_iCurFrm(0)
	, m_bFinish(false)
	, m_AccTime(0.f)
{
}

CAnim::~CAnim()
{
}

void CAnim::finaltick()
{
	if (m_bFinish)
		return;

	m_AccTime += DT;

	if (m_vecFrm[m_iCurFrm].Duration < m_AccTime)
	{
		m_AccTime = 0.f;

		if (m_vecFrm.size() - 1 <= m_iCurFrm)
		{
			m_bFinish = true;
		}
		else
		{
			++m_iCurFrm;
		}
	}

}

void CAnim::render(HDC _dc)
{
	const FFrame& frm = m_vecFrm[m_iCurFrm];

	CObj* pOwnerObject = m_pAnimator->GetOwner();
	Vec2 vRenderPos = pOwnerObject->GetRenderPos();
	Vec2 vScale = pOwnerObject->GetScale();
	float fXCoeffi = (vScale.x / frm.vCutSize.x);
	float fYCoeffi = (vScale.y / frm.vCutSize.y);


	//float coeffi = 1;


	/*TransparentBlt(_dc, int(vRenderPos.x - (frm.vCutSize.x / 2.f) + frm.vOffset.x)
					  , int(vRenderPos.y - (frm.vCutSize.y / 2.f) + frm.vOffset.y)
					  , int(frm.vCutSize.x), int(frm.vCutSize.y)
					  , m_Atlas->GetDC()
					  , int(frm.vLeftTop.x), int(frm.vLeftTop.y)
					  , int(frm.vCutSize.x), int(frm.vCutSize.y)
					  , RGB(255, 0, 255));*/

	BLENDFUNCTION blend = {};
	blend.BlendOp = AC_SRC_OVER;
	blend.BlendFlags = 0;

	blend.SourceConstantAlpha = 255; // 0 ~ 255
	blend.AlphaFormat = AC_SRC_ALPHA; // 0

	AlphaBlend(_dc, int(vRenderPos.x - (frm.vCutSize.x / 2.f) * (fXCoeffi) + frm.vOffset.x)
		, int(vRenderPos.y - (frm.vCutSize.y / 2.f) * (fYCoeffi ) + frm.vOffset.y)
		, int(frm.vCutSize.x*fXCoeffi) , int(frm.vCutSize.y*fYCoeffi)
		, m_Atlas->GetDC()
		, int(frm.vLeftTop.x), int(frm.vLeftTop.y)
		, int(frm.vCutSize.x), int(frm.vCutSize.y)
		, blend);
}

void CAnim::Create(const wstring& _strName, CTexture* _Atlas
	, Vec2 _vLeftTop, Vec2 _vCutSize, Vec2 _vOffset, float _Duration, int _MaxFrm)
{
	SetName(_strName);

	m_Atlas = _Atlas;

	m_vecFrm.reserve(_MaxFrm);

	for (size_t i = 0; i < _MaxFrm; ++i)
	{
		FFrame frm = {};

		frm.vLeftTop = _vLeftTop + Vec2(_vCutSize.x * i, 0.f);
		frm.vCutSize = _vCutSize;
		frm.vOffset = _vOffset;
		frm.Duration = _Duration;

		m_vecFrm.push_back(frm);
	}
}


bool CAnim::Save(const wstring& _FilePath)
{
	FILE* pFile = nullptr;

	_wfopen_s(&pFile, _FilePath.c_str(), L"w");

	if (nullptr == pFile)
	{
		LOG(ERR, L"���� ���� ����");
		return false;
	}

	// Animation �̸� ����
	fwprintf_s(pFile, L"[ANIM_NAME]\n");

	wstring strName = GetName();
	fwprintf_s(pFile, strName.c_str());
	fwprintf_s(pFile, L"\n\n");


	// Ű, ���
	fwprintf_s(pFile, L"[ATLAS_TEXTURE]\n");

	wstring strKey;
	wstring strRelativePath;

	if (IsValid(m_Atlas))
	{
		strKey = m_Atlas->GetKey();
		strRelativePath = m_Atlas->GetRelativePath();
	}

	fwprintf_s(pFile, strKey.c_str());
	fwprintf_s(pFile, L"\n");
	fwprintf_s(pFile, strRelativePath.c_str());
	fwprintf_s(pFile, L"\n\n");

	// ������ ������
	// ������ ����
	fwprintf_s(pFile, L"[FRAME_COUNT]\n");
	fwprintf_s(pFile, L"%d\n\n", (int)m_vecFrm.size());


	for (int i = 0; i < (int)m_vecFrm.size(); ++i)
	{
		fwprintf_s(pFile, L"[FRAME_NUM]\n");
		fwprintf_s(pFile, L"%d\n", i);

		fwprintf_s(pFile, L"[LEFT_TOP]\n");
		fwprintf_s(pFile, L"%f %f\n", m_vecFrm[i].vLeftTop.x, m_vecFrm[i].vLeftTop.y);

		fwprintf_s(pFile, L"[CUT_SIZE]\n");
		fwprintf_s(pFile, L"%f %f\n", m_vecFrm[i].vCutSize.x, m_vecFrm[i].vCutSize.y);

		fwprintf_s(pFile, L"[OFFSET]\n");
		fwprintf_s(pFile, L"%f %f\n", m_vecFrm[i].vOffset.x, m_vecFrm[i].vOffset.y);

		fwprintf_s(pFile, L"[DURATION]\n");
		fwprintf_s(pFile, L"%f\n\n", m_vecFrm[i].Duration);
	}

	fclose(pFile);

	return true;
}

bool CAnim::Load(const wstring& _FilePath)
{
	FILE* pFile = nullptr;

	_wfopen_s(&pFile, _FilePath.c_str(), L"r");

	if (nullptr == pFile)
	{
		LOG(ERR, L"���� ���� ����");
		return false;
	}

	// Animation �̸� �ε�

	while (true)
	{
		wchar_t szRead[256] = {};
		if (EOF == fwscanf_s(pFile, L"%s", szRead, 256))
		{
			break;
		}

		if (!wcscmp(szRead, L"[ANIM_NAME]"))
		{
			fwscanf_s(pFile, L"%s", szRead, 256);
			SetName(szRead);
		}
		else if (!wcscmp(szRead, L"[ATLAS_TEXTURE]"))
		{
			wstring strKey, strRelativePath;

			fwscanf_s(pFile, L"%s", szRead, 256);
			strKey = szRead;

			fwscanf_s(pFile, L"%s", szRead, 256);
			strRelativePath = szRead;

			m_Atlas = CAssetMgr::GetInst()->LoadTexture(strKey, strRelativePath);
		}
		else if (!wcscmp(szRead, L"[FRAME_COUNT]"))
		{
			int iFrameCount = 0;
			fwscanf_s(pFile, L"%d", &iFrameCount);
			m_vecFrm.resize(iFrameCount);

			int iCurFrame = 0;
			while (true)
			{
				fwscanf_s(pFile, L"%s", szRead, 256);

				if (!wcscmp(szRead, L"[FRAME_NUM]"))
				{
					fwscanf_s(pFile, L"%d", &iCurFrame);
				}
				else if (!wcscmp(szRead, L"[LEFT_TOP]"))
				{
					fwscanf_s(pFile, L"%f", &m_vecFrm[iCurFrame].vLeftTop.x);
					fwscanf_s(pFile, L"%f", &m_vecFrm[iCurFrame].vLeftTop.y);
				}
				else if (!wcscmp(szRead, L"[CUT_SIZE]"))
				{
					fwscanf_s(pFile, L"%f", &m_vecFrm[iCurFrame].vCutSize.x);
					fwscanf_s(pFile, L"%f", &m_vecFrm[iCurFrame].vCutSize.y);
				}
				else if (!wcscmp(szRead, L"[OFFSET]"))
				{
					fwscanf_s(pFile, L"%f", &m_vecFrm[iCurFrame].vOffset.x);
					fwscanf_s(pFile, L"%f", &m_vecFrm[iCurFrame].vOffset.y);
				}
				else if (!wcscmp(szRead, L"[DURATION]"))
				{
					fwscanf_s(pFile, L"%f", &m_vecFrm[iCurFrame].Duration);

					if (iFrameCount - 1 <= iCurFrame)
						break;
				}
			}
		}
	}

	fclose(pFile);
	return true;
}

bool CAnim::LoadMeta(CTexture* _pTexture, const wstring& _strAnimKey, const wstring& _strMetaRelativePath)
{
	SetName(_strAnimKey);
	m_Atlas = _pTexture;

	FILE* pFile = nullptr;

	_wfopen_s(&pFile, _strMetaRelativePath.c_str(), L"r");

	if (nullptr == pFile)
	{
		LOG(LOG_LEVEL::ERR, L"���� ���� ����");
		return false;
	}

	// Animation �̸� �ε�
	while (true)
	{
		wchar_t szRead[256] = {};
		if (EOF == fwscanf_s(pFile, L"%s", szRead, 256))
		{
			break;
		}

		if (!wcscmp(szRead, L"%YAML"))
		{
			FFrame frm = {};
			frm.vLeftTop = Vec2(0.f, 0.f);
			frm.vCutSize = Vec2(0.f, 0.f);
			frm.vOffset = Vec2(0.f, 0.f);
			frm.Duration = 1.f;


			while (true)
			{
				fwscanf_s(pFile, L"%s", szRead, 256);

				if (!wcscmp(szRead, L"m_Rect:"))
				{
					while (true)
					{
						fwscanf_s(pFile, L"%s", szRead, 256);

						if (!wcscmp(szRead, L"x:"))
						{
							fwscanf_s(pFile, L"%f", &frm.vLeftTop.x);
						}

						if (!wcscmp(szRead, L"y:"))
						{
							fwscanf_s(pFile, L"%f", &frm.vLeftTop.y);
						}

						if (!wcscmp(szRead, L"width:"))
						{
							fwscanf_s(pFile, L"%f", &frm.vCutSize.x);
						}
						if (!wcscmp(szRead, L"height:"))
						{
							fwscanf_s(pFile, L"%f", &frm.vCutSize.y);
						}

						if (!wcscmp(szRead, L"m_Offset:"))
						{
							frm.vLeftTop.y = _pTexture->GetHeight() - frm.vLeftTop.y - frm.vCutSize.y;
							break;
						}



					}
				}

				if (!wcscmp(szRead, L"m_Offset:"))
				{
					while (true)
					{
						fwscanf_s(pFile, L"%s", szRead, 256);

						if (!wcscmp(szRead, L"{x:"))
						{
							fwscanf_s(pFile, L"%f", &frm.vOffset.x);

							frm.vOffset.x = frm.vOffset.x * -1;
						}
						if (!wcscmp(szRead, L"y:"))
						{
							fwscanf_s(pFile, L"%s", szRead, 256);

							int length = (int)wcslen(szRead);

							if (length > 0) {
								szRead[length - 1] = '\0';
							}

							wchar_t* end;
							float tmp = wcstof(szRead, &end);
							if (*end == L'\0') {
								frm.vOffset.y = tmp;
							}
							break;
						}
						if (!wcscmp(szRead, L"m_Border:"))
						{
							break;
						}
					}
				}
				if (!wcscmp(szRead, L"m_Border:"))
					break;

			}
			m_vecFrm.push_back(frm);

		}


	}

	fclose(pFile);
	return true;
}

bool CAnim::LoadMetaReverse(CTexture* _pTexture, const wstring& _strAnimKey, const wstring& _strMetaRelativePath)
{
	SetName(_strAnimKey);
	m_Atlas = _pTexture;

	FILE* pFile = nullptr;

	_wfopen_s(&pFile, _strMetaRelativePath.c_str(), L"r");

	if (nullptr == pFile)
	{
		LOG(LOG_LEVEL::ERR, L"���� ���� ����");
		return false;
	}

	// Animation �̸� �ε�
	while (true)
	{
		wchar_t szRead[256] = {};
		if (EOF == fwscanf_s(pFile, L"%s", szRead, 256))
		{
			break;
		}

		if (!wcscmp(szRead, L"%YAML"))
		{
			FFrame frm = {};
			frm.vLeftTop = Vec2(0.f, 0.f);
			frm.vCutSize = Vec2(0.f, 0.f);
			frm.vOffset = Vec2(0.f, 0.f);
			frm.Duration = 0.1f;

			// x = texture.x - x - sclae.x +1;
			float tmpX = 0.f;

			while (true)
			{
				fwscanf_s(pFile, L"%s", szRead, 256);

				if (!wcscmp(szRead, L"m_Rect:"))
				{
					while (true)
					{
						fwscanf_s(pFile, L"%s", szRead, 256);

						if (!wcscmp(szRead, L"x:"))
						{
							fwscanf_s(pFile, L"%f", &frm.vLeftTop.x);
						}

						if (!wcscmp(szRead, L"y:"))
						{
							fwscanf_s(pFile, L"%f", &frm.vLeftTop.y);
						}

						if (!wcscmp(szRead, L"width:"))
						{
							fwscanf_s(pFile, L"%f", &frm.vCutSize.x);
						}
						if (!wcscmp(szRead, L"height:"))
						{
							fwscanf_s(pFile, L"%f", &frm.vCutSize.y);
						}

						if (!wcscmp(szRead, L"m_Offset:"))
						{
							frm.vLeftTop.x = _pTexture->GetWidth() - frm.vLeftTop.x - frm.vCutSize.x + 1;
							frm.vLeftTop.y = _pTexture->GetHeight() - frm.vLeftTop.y - frm.vCutSize.y;
							break;
						}



					}
				}

				if (!wcscmp(szRead, L"m_Offset:"))
				{
					while (true)
					{
						fwscanf_s(pFile, L"%s", szRead, 256);

						if (!wcscmp(szRead, L"{x:"))
						{
							fwscanf_s(pFile, L"%f", &frm.vOffset.x);

						}
						if (!wcscmp(szRead, L"y:"))
						{
							fwscanf_s(pFile, L"%s", szRead, 256);

							int length = (int)wcslen(szRead);

							if (length > 0) {
								szRead[length - 1] = '\0';
							}

							wchar_t* end;
							float tmp = wcstof(szRead, &end);
							if (*end == L'\0') {
								frm.vOffset.y = tmp;
							}
							break;
						}
						if (!wcscmp(szRead, L"m_Border:"))
						{
							break;
						}
					}
				}
				if (!wcscmp(szRead, L"m_Border:"))
					break;

			}
			m_vecFrm.push_back(frm);

		}


	}

	fclose(pFile);
	return true;
}