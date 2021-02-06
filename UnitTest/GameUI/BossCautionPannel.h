#pragma once
#include "UI/Pannel.h"

class BossCautionPannel : public Pannel
{
public :
	BossCautionPannel();

	virtual void OnUpdate() override;

	void Caution();

private :
	// �������� 3�� �ݺ�
	int loopingCount = 0;
	int maxLoopingCount = 3;
	bool isDecreaseAlpha = true;
	bool isStart = false;
};