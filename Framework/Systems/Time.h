#pragma once

class Time : public SingletonBase<Time>
{
public:
	friend class SingletonBase<Time>;

	static bool Stopped() { return isTimerStopped; }
	static float Delta() { return isTimerStopped ? 0.0f : timeElapsed * GetTimeScale(); }

	void Update();

	void Start();
	void Stop();

	float FPS() const { return framePerSecond; }
	float Running() const { return runningTime; }



	static	void SetTimeScale(float timeScale)
	{
		Time::timeScale = timeScale;
	}
	static float GetTimeScale()
	{
		return Time::timeScale;
	}
private:
	Time(void);
	~Time(void);

	static bool isTimerStopped;///< Ÿ�̸� ����
	static float timeElapsed;///< ���� ���������κ��� ����ð�
	static float timeScale;

	INT64 ticksPerSecond;///< �ʴ� ƽī��Ʈ
	INT64 currentTime;///< ���� �ð�
	INT64 lastTime;///< �����ð�
	INT64 lastFPSUpdate;///< ������ FPS ������Ʈ �ð�
	INT64 fpsUpdateInterval;///< fps ������Ʈ ����

	UINT frameCount;///< ������ ��
	float runningTime;///< ���� �ð�
	float framePerSecond;///< FPS



};