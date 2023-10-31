#pragma once


class CUI;

class CUIMgr
{
	SINGLETON(CUIMgr);
private:
	CUI* m_FocuedUI;	// �ֻ��� �θ� UI �߿��� ��Ŀ�� �Ǿ��ִ� UI

public:
	void tick();

private:
	CUI* GetPriorityCheck(CUI* _ParentUI);

};

