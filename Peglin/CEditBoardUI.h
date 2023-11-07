#pragma once
#include "CBtnUI.h"

typedef  void(*BtnCallBack)(void);


class CEditBoardUI :
    public CBtnUI
{
    GENERATED_OBJECT(CBtnUI);
private:
    // 콜백 (전역함수 포인터) 
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

