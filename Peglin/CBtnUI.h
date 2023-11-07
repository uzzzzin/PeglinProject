#pragma once
#include "CUI.h"

class CTexture;

typedef  void(*BtnCallBack)(void);

typedef  void(CEntity::* DelegateFunc)(void);



class CBtnUI :
    public CUI
{
    GENERATED_OBJECT(CUI);
private:

    CAnimator* m_Animator;

    wstring wNAnimName;
    wstring wHAnimName;
    wstring wPAnimName;

    // �ݹ� (�����Լ� ������) 
    BtnCallBack m_CallBackFunc;

    // ��������Ʈ(�ɹ��Լ� ������, ��ü)
    // ��ü�� �ּ�
    CEntity* m_Inst;
    // �ɹ��Լ��� �ּ�
    DelegateFunc    m_Delegate;

public:

    void SetCallBack(BtnCallBack _CallBack) { m_CallBackFunc = _CallBack; }
    void SetDeletage(CEntity* _Inst, DelegateFunc _Func) { m_Inst = _Inst; m_Delegate = _Func; }

    void SetNormalImg(const wstring& _strRelativePath2, const wstring& _animName);
    void SetPressedImg(const wstring& _strRelativePath2, const wstring& _animName);
    void SetHoverImg(const wstring& _strRelativePath2, const wstring& _animName);
    
    wstring& GetNAnimName() { return wNAnimName; }
    wstring& GetPAnimName() { return wPAnimName; }
    wstring& GetHAnimName() { return wHAnimName; }

public:
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;
    virtual void begin();

public:
    virtual void OnHovered(Vec2 _vMousePos) override;
    virtual void OnUnHovered(Vec2 _vMousePos) override;
    virtual void MouseOn(Vec2 _vMousePos) override;

    virtual void LBtnDown(Vec2 _vMousePos) override;
    virtual void LBtnUp(Vec2 _vMousePos) override;
    virtual void LBtnClicked(Vec2 _vMousePos) override;


public:
    CLONE(CBtnUI);
    CBtnUI();
    CBtnUI(const wstring& _strName, const wstring& _strKey, const wstring& _strRelativePath);
    ~CBtnUI();
};

