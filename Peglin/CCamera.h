#pragma once

class CTexture;

enum class CAM_EFFECT
{
	FADE_IN,
	FADE_OUT,
};

struct FCamEvent
{
	CAM_EFFECT	Type;
	float		AccTime;
	float		Duration;
};


class CCamera
{
	SINGLETON(CCamera);
private:
	Vec2				m_vLookAt;
	Vec2				m_vDiff;
	CTexture* m_Veil;

	list<FCamEvent>		m_EventList;
	UINT				m_Alpha;



public:
	void tick();
	void render(HDC _dc);
	void SetLookAt(Vec2 _vLookAt) { m_vLookAt = _vLookAt; }

	void FadeIn(float _time)
	{
		FCamEvent evnt = {};
		evnt.Type = CAM_EFFECT::FADE_IN;
		evnt.AccTime = 0.f;
		evnt.Duration = _time;
		m_EventList.push_back(evnt);
	}

	void FadeOut(float _time)
	{
		FCamEvent evnt = {};
		evnt.Type = CAM_EFFECT::FADE_OUT;
		evnt.AccTime = 0.f;
		evnt.Duration = _time;
		m_EventList.push_back(evnt);
	}

	// ī�޶� �ٶ󺸰� �ִ� LookAt ������ �ػ� �߽���ġ�� ���̰� ��ŭ ���� ��ġ�� ������ ���ش�.
	// ī�޶� �ٶ󺸰� �ִ� ������ ��ü���� �ػ� ���η� ���� �� �ְ�,
	// ī�޶� ����ִ� ��ġ�� ��ü���� ȭ�鿡 ���� �� �ְ� �Ѵ�.
	Vec2 GetRenderPos(Vec2 _vRealPos) { return _vRealPos - m_vDiff; }
	Vec2 GetRealPos(Vec2 _vRenderPos) { return m_vDiff + _vRenderPos; }
	Vec2 GetLookAtPos() { return m_vLookAt; }
};

