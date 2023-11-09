#pragma once
#include "CCollider.h"

class CColliderCircle :
    public CCollider
{

public:
    virtual void render(HDC _dc) override;

public:
    virtual CColliderCircle* Clone() { return new CColliderCircle(*this); }

public:
    CColliderCircle(CObj* _Owner);
    ~CColliderCircle();
};

