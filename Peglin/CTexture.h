#pragma once
#include "CAsset.h"


class CTexture :
    public CAsset
{
private:
    HBITMAP     m_hBit;
    HDC         m_hDC;
    BITMAP      m_Info;

public:
    HDC GetDC() { return m_hDC; }
    HBITMAP GetBitmap() { return m_hBit; }
    UINT GetWidth() { return m_Info.bmWidth; }
    UINT GetHeight() { return m_Info.bmHeight; }
    //void SetTexScale(Vec2 _Scale)
    //{
    //    m_Info.bmWidth = _Scale.x;
    //    m_Info.bmHeight = _Scale.y;
    //    m_Info.bmWidthBytes = _Scale.x * 4;
    //}

private:
    virtual bool Load(const wstring& _strFilePath) override;

    void Create(UINT _Width, UINT Height);

private:
    CTexture();
    ~CTexture();

    friend class CAssetMgr;
};

