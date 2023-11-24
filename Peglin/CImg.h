#pragma once
#include "CObj.h"
class CImg :
    public CObj
{
    GENERATED_OBJECT(CObj);

private:
    //wstring         m_AnimName;
    CAnimator* m_Animator;
    //CCollider*    m_Collider;

public:
    void SetImg(const wstring& _strRelativePath, const wstring& _animName);

    //virtual void begin() override;
    virtual void tick(float _DT);
    virtual void render(HDC _dc);

public:
    CLONE(CImg);
    CImg();
    ~CImg();
};

