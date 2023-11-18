#pragma once
#include "CGeneralLevel.h"
class CStage1Level :
    public CGeneralLevel
{

public:
    virtual void init() override;
    virtual void enter() override;
    virtual void exit() override;

    virtual void tick() override;

public:
    CStage1Level();
    ~CStage1Level();
};

