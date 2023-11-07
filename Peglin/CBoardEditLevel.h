#pragma once
#include "CLevel.h"

class CBoardEditLevel :
    public CLevel
{
private:
    vector<class CBtnUI*> vPegs;

public:
    virtual void init() override;
    virtual void enter() override;
    virtual void exit() override;
    virtual void tick() override; 

public:
    void SaveBoard();
    void LoadBoard();



    //void PushBack_Pegs

   // friend class CEditPegUI;
 
};

