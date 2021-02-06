#pragma once
#include "IFlockBehaviour.h"
class Transform;
namespace FlockAI
{
	class FlockAgent;
	class Flock;
	class AlignmentBehaviour : public IFlockBehaviour
	{
	public :

		// IFlockBehaviour��(��) ���� ��ӵ�
		virtual Vector3 CalculateMove(FlockAgent * agent, vector<Transform*> context, Flock * flock) override;
	};
}