#pragma once
#include "CUI.h"


class CTextUI :
    public CUI
{
    GENERATED_OBJECT(CUI);

private:

    wstring wsText;

public:
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;

    void SetText(wstring _Text) { wsText = _Text;  }
    wstring GetText() { return wsText;  }

    virtual void OnHovered(Vec2 _vMousePos) override;
    virtual void OnUnHovered(Vec2 _vMousePos) override;
    virtual void MouseOn(Vec2 _vMousePos) override;

    virtual void LBtnDown(Vec2 _vMousePos) override;
    virtual void LBtnUp(Vec2 _vMousePos) override;
    virtual void LBtnClicked(Vec2 _vMousePos) override;

public:
    CLONE(CTextUI);
    CTextUI(wstring _Text);
    ~CTextUI();
     
};

