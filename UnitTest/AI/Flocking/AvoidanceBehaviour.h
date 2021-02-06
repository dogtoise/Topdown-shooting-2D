#pragma once

#include "IFlockBehaviour.h"

namespace FlockAI
{
	class AvoidanceBehaviour : public IFlockBehaviour
	{
	public :

		// IFlockBehaviour��(��) ���� ��ӵ�
		virtual Vector3 CalculateMove(FlockAgent * agent, vector<Transform*> context, Flock * flock) override;
	};
}