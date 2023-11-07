#pragma once
#include "CBtnUI.h"

typedef  void(*BtnCallBack)(void);


class CEditBoardUI :
    public CBtnUI
{
    GENERATED_OBJECT(CBtnUI);

 /*   virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;*/
    //virtual void begin();

public:
    virtual void LBtnClicked(Vec2 _vMousePos) override;


public:
    CLONE(CEditBoardUI)
        CEditBoardUI();
    ~CEditBoardUI();
};

