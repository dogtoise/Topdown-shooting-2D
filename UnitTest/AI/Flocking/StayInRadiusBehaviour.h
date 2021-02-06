#pragma once

#include "IFlockBehaviour.h"

namespace FlockAI
{
	class StayInRadiusBehaviour : public IFlockBehaviour
	{
	public :
		// IFlockBehaviour��(��) ���� ��ӵ�
		virtual Vector3 CalculateMove(FlockAgent * agent, vector<Transform*> context, Flock * flock) override;

	private :
		Vector3 center; // center is player
		float radius = 15.0f;
	};
}