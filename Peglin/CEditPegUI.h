#pragma once
#include "CBtnUI.h"
class CEditPegUI :
    public CBtnUI
{
    GENERATED_OBJECT(CBtnUI);

private:
    SavedPegsInfo pegsInfo;

public:
    void SetPegsType(PEG_TYPE _pegType)
    {
        pegsInfo.type = _pegType;
    }


    virtual void RBtnDown(Vec2 _vMousePos);
    virtual void RBtnUp(Vec2 _vMousePos);
    virtual void RBtnClicked(Vec2 _vMousePos);

public:
    CLONE(CEditPegUI);
    CEditPegUI();
    ~CEditPegUI();

};

