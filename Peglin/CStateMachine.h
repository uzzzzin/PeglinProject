#pragma once
#include "CComponent.h"
#include "CLogMgr.h"

class CState;

// FSM, Finite State Machine(���� ���� ���)
class CStateMachine :
    public CComponent
{
private:
    map<UINT, CState*>  m_mapState;
    CState* m_pCurState;

    map<wstring, void*> m_mapBlackboard;


public:
    void AddState(UINT _id, CState* _State);
    CState* FindState(UINT _id);
    void ChangeState(UINT _NextID);

    template<typename T>
    void AddDataToBlackboard(const wstring& _strKey, const T& _Data);

    void* GetDataFromBlackboard(const wstring _strKey);




public:
    virtual void finaltick(float _DT) override;


public:
    CLONE(CStateMachine);

    CStateMachine(CObj* _Owner);
    CStateMachine(const CStateMachine& _Origin);
    ~CStateMachine();
};

template<typename T>
inline void CStateMachine::AddDataToBlackboard(const wstring& _strKey, const T& _Data)
{
    map<wstring, void*>::iterator iter = m_mapBlackboard.find(_strKey);
    if (iter != m_mapBlackboard.end())
    {
        LOG(LOG_LEVEL::ERR, L"!!�����忡 �ش� ������ Ű �̹� ����!!");
        return;
    }

    T* pData = new T;
    *pData = _Data;
    m_mapBlackboard.insert(make_pair(_strKey, pData));
}
