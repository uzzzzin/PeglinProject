#pragma once
#include "CObj.h"
class CPeg :
    public CObj
{
    //GENERATED_OBJECT(CObj);
protected:
    //int iPegType; // 페그의 타입
    int                                iDieCnt; // 몇 번 맞으면 죽는지 // 1
    int                                iCurCnt; // 페그 생성되고 현재 몇 번 맞았는지 // 0

    bool                            bCrashed; // 현재 죽었는지 안 죽었는지 -> 엔터티에 있지 않나 // false 

    bool                            bCritMode;

    bool                            bColSnd;
    
    class CAnimator* m_Animator;
    class CColliderCircle* m_Collider;



public:
    void SetiDieCnt(int _iDieCnt)
    {
        iDieCnt = _iDieCnt;
    }
    void SetiCurCnt(int _iCurCnt)
    {
        iCurCnt = _iCurCnt;
    }
    void SetCrashed(bool _bDied)
    {
        bCrashed = _bDied;
    }
    void CritModeOn()
    {
        bCritMode = true;
    }
    void CritModeOff()
    {
        bCritMode = false;
    }

    bool GetCritMode()
    {
        return bCritMode;
    }

public:
    virtual void begin();
    virtual void tick(float _DT);
    virtual void render(HDC _dc) { CObj::render(_dc); };
    virtual void Reload() {};  //재생성 함수
    // 충돌 관련 오버랩 함수가 필요할턴디 
    virtual void Refresh() {};





    virtual void BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol);
    //virtual void Overlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol);
    //virtual void EndOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol);

public:
    virtual CPeg* Clone() = 0;
    CPeg();
    //CPeg(const CPeg& _Origin);
    virtual ~CPeg();
};


//void LoadPeg