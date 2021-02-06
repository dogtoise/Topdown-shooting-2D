#pragma once
#include "IFlockBehaviour.h"

namespace FlockAI
{
	class SteeredCohesionBehaviour : public IFlockBehaviour
	{
	public :


		// IFlockBehaviour��(��) ���� ��ӵ�
		virtual Vector3 CalculateMove(FlockAgent * agent, vector<Transform*> context, Flock * flock) override;

	private :
		Vector3 currentVelocity; 
		float agentSmoothTime = 0.5f;
	};
}