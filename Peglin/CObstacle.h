#pragma once
#include "CImg.h"
class CObstacle :
    public CImg
{
    GENERATED_OBJECT(CImg);

private:
    CColliderCircle* m_Collider;

public:
    virtual void tick(float _DT) override;
    virtual void begin() override;


public:
    CLONE(CObstacle);
    CObstacle();
    ~CObstacle();
};

