#pragma once
#include "CBtnUI.h"

typedef  void(*BtnCallBack)(void);


class CEditBoardUI :
    public CBtnUI
{
    GENERATED_OBJECT(CBtnUI);
private:
    // �ݹ� (�����Լ� ������) 
    //BtnCallBack m_CallBackFunc;

public:
    //void SetCallBack(BtnCallBack _CallBack) { m_CallBackFunc = _CallBack; }

 /*   virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;*/
    //virtual void begin();

public:
    virtual void LBtnClicked(Vec2 _vMousePos) override;
    //virtual void RBtnClicked(Vec2 _vMousePos) override;


public:
    CLONE(CEditBoardUI)
        CEditBoardUI();
    ~CEditBoardUI();
};

