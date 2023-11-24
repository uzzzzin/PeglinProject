#pragma once
#include "CLevel.h"
class CStartLevel :
    public CLevel
{
private:
    class CSound* m_BGM;


public:
    virtual void init() override;
    virtual void enter() override;
    virtual void exit() override;

    virtual void tick() override;

public:
    CStartLevel();
    ~CStartLevel();
};

