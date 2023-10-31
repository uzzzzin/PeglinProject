#pragma once

class CSound;

class CSoundMgr
{
	SINGLETON(CSoundMgr);
private:
	LPDIRECTSOUND8	m_pSound;	// ���� ���� �Ŵ��� ��ü, ���� ī�� ��Ʈ��
	CSound* m_pBGM;		// ���� �߿��� BGM Sound �� ����Ű�� ������

public:
	int init();
	LPDIRECTSOUND8 GetSoundDevice() { return m_pSound; }
	void RegisterToBGM(CSound* _pSound);
};

