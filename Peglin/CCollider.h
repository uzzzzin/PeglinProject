#pragma once

#include "CComponent.h"
enum class ColliderType
{
    RECTANGLE
    , CIRCLE
    ,END
};

class CCollider :
    public CComponent
{
private:
    bool bOnOff;
    ColliderType m_Type;
    Vec2    m_vOffsetPos;  // Owner �κ��� ������ �Ÿ�
    Vec2    m_vScale;      // Owner �κ��� �߰� ����
    Vec2    m_vFinalPos;   // �浹ü�� ���� ��ġ

    Vec2    prevColPos;

    int     m_iCollisionCount;

public:
    virtual void finaltick(float _DT) override;
    virtual void render(HDC _dc) override;

public:
    bool GetBOnOff() { return bOnOff; }
    void SetBOnOff(bool _onoff) { bOnOff = _onoff; }
    void SetOffsetPos(Vec2 _vOffsetPos) { m_vOffsetPos = _vOffsetPos; }
    void SetScale(Vec2 _vScale) { m_vScale = _vScale; }
    Vec2 GetPos() { return m_vFinalPos; }
    Vec2 GetPrevColPos() { return prevColPos; }
    Vec2 GetOffsetPos() { return m_vOffsetPos; }
    Vec2 GetScale() { return m_vScale; }
    void SetColliderType(ColliderType _type)
    {
        m_Type = _type;
    }
    ColliderType GetType()
    {
        return m_Type;
    }


public:
    void BeginOverlap(CCollider* _OtherCol);
    void Overlap(CCollider* _OtherCol);
    void EndOverlap(CCollider* _OtherCol);

public:
    virtual CCollider* Clone() { return new CCollider(*this); }

public:
    CCollider(CObj* _Owner);
    CCollider(const CCollider& _Origin);
    ~CCollider();

    friend class CColliderCircle;
};

