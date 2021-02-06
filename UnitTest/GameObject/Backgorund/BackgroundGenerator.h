#pragma once
#include "Game/GameObject.h"
#include "Background.h"
#include "Game/Transform.h"


// ��ġ�� �ʰ�
namespace BG
{
	enum GenerateType
	{
		LEFT = 0,
		LEFT_TOP,
		LEFT_BOTTOM,
		RIGHT,
		RIGHT_TOP,
		RIGHT_BOTTOM,
		TOP,
		BOTTOM,
		NONE,
	};
}
using namespace BG;
class Background;
class BackgroundGenerator
{
public :
	BackgroundGenerator();
	~BackgroundGenerator();
	
	template <typename TBackground>
	void Init(Vector3 startOffset)
	{
		for (int i = 0; i < 9; i++)
		{
			backgrounds.push_back(new TBackground());
			backgrounds[i]->SetActive(false);
		}
		backgrounds[0]->transform->position = startOffset;
		backgrounds[0]->SetActive(true);
	}
	void Update();
	

private :
	// ī�޶� �ۿ� �ִ� bg��� setactive(false)
	void CullBackground();
	Background * GetBgUnderPlayer();
	GenerateType CheckGenerateCondition(Background * center);
	bool IsExistsAtPos(Vector3 pos);

private :
	vector<Background *> backgrounds;
};