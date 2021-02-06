#pragma once
#include "FSMState.h"


class GameObject;

class EnemyState : public  FSMState
{
public:

	virtual void Enter(GameObject * owner) override {};
	// ���� ���� ���̰� �ʿ��ϴٸ� �ش� state ��ȯ
	// ���̰� �ʿ���ٸ� nullptr ��ȯ
	virtual FSMState * Update(GameObject * owner) override { return nullptr; };
	virtual void Exit(GameObject * owner) override {};

};
namespace EnemyAI
{


	class MovingState : public EnemyState
	{
	public:
		// EnemyState��(��) ���� ��ӵ�
		virtual void Enter(GameObject * owner) override;
		virtual FSMState * Update(GameObject * owner) override;
		virtual void Exit(GameObject * owner) override;
	private:
		float moveRot = 0;
	};

	class ThinkingState : public  EnemyState
	{
	public:
		// EnemyState��(��) ���� ��ӵ�
		virtual void Enter(GameObject * owner) override;
		virtual FSMState * Update(GameObject * owner) override;
		virtual void Exit(GameObject * owner) override;
	};

	class AttackState : public  EnemyState
	{
	public:
		// EnemyState��(��) ���� ��ӵ�
		virtual void Enter(GameObject * owner) override;
		virtual FSMState * Update(GameObject * owner) override;
		virtual void Exit(GameObject * owner) override;
	};
	class DiyingState : public  EnemyState
	{
	public:
		// EnemyState��(��) ���� ��ӵ�
		virtual void Enter(GameObject * owner) override;
		virtual FSMState * Update(GameObject * owner) override;
		virtual void Exit(GameObject * owner) override;
	};
}