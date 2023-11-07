#pragma once
#include "CBtnUI.h"
class CEditPegUI :
    public CBtnUI
{
    GENERATED_OBJECT(CBtnUI);

private:
    SavedPegsInfo pegsInfo = {};

public:
    void SetPegsInfo(PEG_TYPE _pegType, Vec2 _pos, Vec2 _scale)
    {
        pegsInfo.type = _pegType;
        pegsInfo.pos = _pos;
        pegsInfo.scale = _scale;
    }

    //bool Save(const wchar_t* _path);
   //void Load(FILE* _pFile);

    virtual void RBtnDown(Vec2 _vMousePos);
    virtual void RBtnUp(Vec2 _vMousePos);
    virtual void RBtnClicked(Vec2 _vMousePos);

public:
    CLONE(CEditPegUI);
    CEditPegUI();
    ~CEditPegUI();

    friend class CBoardEditLevel;
};

