#pragma once
#include "CObj.h"

class COrb :
    public CObj
{
    GENERATED_OBJECT(CObj);
private:
    class CColliderCircle* m_Collider;
    class CAnimator* m_Animator;
    class CMovement*  m_Movement;

    //class CPeglinPlayer* pPlayer;

    vector<OrbInfo> orbs; // ����� �������� ��� �ִ�.

    vector<CTexture*> Nums; // ������ ���� �ؽ��ĵ� ���.
    int alphaCnt;

    int accDamage;
    Vec2 accDamagePos;
    //int accCnt;


    vector<std::pair<PEG_TYPE, int>> hitOrbs;

    ORB_TYPE curOrbType;

    int curDamage;
    int curCritDamage; 
    int curAttackCnt;


public:
    Vec2 prevPos;
    Vec2 curPos;
    Vec2 rPos;
    Vec2 colPos;
    Vec2 vDir;

    Vec2 m_pPos;
    Vec2 m_cPos;
    Vec2 m_rPos;
    Vec2 m_colPos;
    
public:
    ORB_TYPE GetCurOrbType()
    { return curOrbType; }

    Vec2 GetPrevPos()
    {   return prevPos;}

    Vec2 GetDir()
    {    return (curPos - prevPos).Normalize(); }

    vector<OrbInfo>& GetOrbsInfo()
    {  return orbs;}

    vector<std::pair<PEG_TYPE, int>>& GetHitOrbsCnt()
    { return hitOrbs;}

    void SetCurTurnOrb(ORB_TYPE _type);

    int digitCal(int _accDamage);

    void SetAccDamage(int _damage);

    int GetAccDamage()
    {
        return accDamage;
    }
    void alphaCntMM()
    {
        if (alphaCnt <= 0)
            return;

        alphaCnt = alphaCnt - 1;
    }
    void alphaCntReset()
    {
        alphaCnt = 255;
    }




    void SetAccDamagePos(Vec2 _pos);

    virtual void begin() override;
    virtual void tick(float _DT) override;
    //virtual void finaltick(float _DT) override;
   virtual void render(HDC _dc) override;
    virtual void BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol) override;
    //virtual void Overlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol) override;
    //virtual void EndOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol) override;

    friend class CLevel;
    friend class COrbQueueHeadOrb;
    friend class CPeglinPlayer;

public:
    CLONE(COrb);
    COrb();
    ~COrb();
};

