#pragma once
#include "CObj.h"
class CPeg :
    public CObj
{
    GENERATED_OBJECT(CObj);
private:
    int iPegType; // ����� Ÿ��
    int iDieCnt; // �� �� ������ �״���
    int iCurCnt; // ��� �����ǰ� ���� �� �� �¾Ҵ���
    bool bDied; // ���� �׾����� �� �׾����� -> ����Ƽ�� ���� �ʳ� 

public:
    virtual void begin() {};
    virtual void tick(float _DT) {};
    virtual void render(HDC _dc) {};
    virtual void Reload() {};  //����� �Լ�
    // �浹 ���� ������ �Լ��� �ʿ����ϵ� 

public:
    virtual CObj* Clone() = 0;
    CPeg();
    CPeg(const CPeg& _Origin);
    virtual ~CPeg();
};

