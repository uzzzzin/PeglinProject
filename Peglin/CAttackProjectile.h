#pragma once
#include "CObj.h"
class CAttackProjectile :
    public CObj
{
    GENERATED_OBJECT(CObj);

private:
    class CTransform* m_Transform;
    class CAnimator* m_Animator;
    class CCollider* m_Collider;

public:
    virtual void tick(float _DT) override;
    virtual void begin() override;
    
public:
    CLONE(CAttackProjectile);
    CAttackProjectile();
    ~CAttackProjectile();
};

