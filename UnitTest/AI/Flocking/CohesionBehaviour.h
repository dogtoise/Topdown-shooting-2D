#pragma once
#include "IFlockBehaviour.h"

namespace FlockAI
{
	class CohesionBehaviour : public IFlockBehaviour
	{
		// IFlockBehaviour��(��) ���� ��ӵ�
		virtual Vector3 CalculateMove(FlockAgent * agent, vector<Transform*> context, Flock * flock) override;
	};
}