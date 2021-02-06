#pragma once
#include "Interfaces/IObject.h"
class SceneTransition
{
public :
	SceneTransition();
	~SceneTransition();
	IObject * GetCurrentScene();

	void PushScene(string sceneName, IObject * scene, function<void(IObject *, IObject * )> onChanged);


	// �ٲ� push�ϴ°� �ݹ����� ����
	
private :
	IObject * currentScene = nullptr;
	vector<IObject * > scenes;
};