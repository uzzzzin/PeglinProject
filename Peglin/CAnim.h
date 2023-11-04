#pragma once
#include "CEntity.h"

class CTexture;

struct FFrame
{
    Vec2 vLeftTop;  // ��Ʋ�� ������ �߶� �»�� ��ġ
    Vec2 vCutSize;  // �߶� ũ��
    Vec2 vOffset;   // ������Ʈ �߽ɿ��� �̵� ��
    float Duration; // �ش� ������ ���� �ð�
};


class CAnimator;

class CAnim :
    public CEntity
{
private:
    CAnimator* m_pAnimator;

    vector<FFrame>  m_vecFrm;
    CTexture* m_Atlas;
    int             m_iCurFrm;

    // ���� �ð�
    float           m_AccTime;

    // animation ��� �Ϸ� üũ
    bool            m_bFinish;


public:
    void finaltick();
    void render(HDC _dc);

public:
    void Create(const wstring& _strName, CTexture* _Atlas
        , Vec2 _vLeftTop, Vec2 _vCutSize, Vec2 _vOffset, float _Duration, int _MaxFrm);

    bool IsFinish() { return m_bFinish; }

    void Reset()
    {
        m_AccTime = 0.f;
        m_iCurFrm = 0;
        m_bFinish = false;
    }

    bool Save(const wstring& _FilePath);
    bool Load(const wstring& _FilePath);
    bool LoadMeta(CTexture* _pTexture, const wstring& _strAnimKey, const wstring& _strMetaRelativePath);
    bool LoadMetaReverse(CTexture* _pTexture, const wstring& _strAnimKey, const wstring& _strMetaRelativePath);


public:
    CLONE(CAnim);

    CAnim();
    ~CAnim();

    friend class CAnimator;
};

