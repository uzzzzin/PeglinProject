#pragma once
#include "CLevel.h"

class CBoardEditLevel :
    public CLevel
{
private:
    vector<class CEditPegUI*> vPegs;

    //int PegsCnt = 0;

public:
    virtual void init() override;
    virtual void enter() override;
    virtual void exit() override;
    virtual void tick() override; 

public:
    void SaveBoard();
    void LoadBoard();

    void PushBack_Pegs(CEditPegUI* _peg)
    {
        vPegs.push_back(_peg);
    }

   friend class CEditPegUI;
 
};

