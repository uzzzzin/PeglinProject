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

    vector<OrbInfo> orbs; // 오브들 정보들이 담겨 있다.

    vector<CTexture*> Nums; // 데미지 숫자 텍스쳐들 담김.
    int alphaCnt;

    int accDamage;
    int accCritDamage;
    Vec2 accDamagePos;
    //int accCnt;

    bool PegCritMode;


    vector<std::pair<PEG_TYPE, int>> hitOrbs;

    ORB_TYPE curOrbType;

    int curDamage;
    int curCritDamage; 
    int curAttackCnt;

    class CSound* m_SE;

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
    bool GetPegCritMode()
    {
        return PegCritMode;
    }
    void SetCritMode(bool _mode)
    {
        PegCritMode = _mode;
    }

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

    void SetAccCritDamage(int _damage)
    {
        accCritDamage = _damage;
    }

    int GetAccDamage()
    {
        if (PegCritMode)
        {
            return accCritDamage;
        }
        else
        {
            return accDamage;
        }

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

