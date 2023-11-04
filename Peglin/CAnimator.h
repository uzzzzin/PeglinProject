#pragma once
#include "CComponent.h"

class CAnim;
class CTexture;

class CAnimator :
    public CComponent
{
private:
    // Animator �� �����ϰ� �ִ� Animation ���, Ž���� ���ؼ� Map ���� 
    map<wstring, CAnim*> m_mapAnim;

    // ���� ������� Animation
    CAnim* m_CurAnim;

    // �ݺ� ��� ����
    bool                 m_bRepeat;

public:
    void Play(const wstring& _strName, bool _bRepeat);
    void Stop();


    // Animation ã��
    CAnim* FindAnim(const wstring& _strName);

    // �ִϸ��̼� ����
    void CreateAnimation(const wstring& _strName, CTexture* _Altas, Vec2 _vLeftTop, Vec2 _vCutSize
        , Vec2 _vOffset, float _duration, int _MaxFrm);

    void SaveAnimations(const wstring& _strRelativePath);

    void LoadAnimation(const wstring& _strRelativePath);

    void LoadAnimation(CTexture* _pTexture, const wstring& _strAnimKey, const wstring& _strMetaRelativePath, bool _bReverse);



public:
    virtual void finaltick(float _DT) override;
    virtual void render(HDC _dc) override;

public:
    CLONE(CAnimator);
    CAnimator(CObj* _Owner);
    CAnimator(const CAnimator& _Origin);
    ~CAnimator();
};

