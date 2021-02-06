#pragma once
#include "Game/GameObject.h"

class FSMState
{
public :
	virtual void Enter(GameObject * owner) {};
	// ���� ���� ���̰� �ʿ��ϴٸ� �ش� state ��ȯ
	// ���̰� �ʿ���ٸ� nullptr ��ȯ
	virtual FSMState * Update(GameObject * owner) { return nullptr; };
	virtual void Exit(GameObject * owner) {};
};