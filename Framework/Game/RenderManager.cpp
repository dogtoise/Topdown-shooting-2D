#include "Framework.h"
#include "RenderManager.h"
#include "GameObject.h"
#include "Game/GameObjectManager.h"
#include "Game/Transform.h"

void RenderManager::PushRenderable(GameObject* gameObject)
{
	renderables.push_back(gameObject);
	sort(renderables.begin(), renderables.end(), [](GameObject* lhs, GameObject* rhs)->bool
	{
		if ((int)lhs->GetRenderLayer() >= (int)rhs->GetRenderLayer())
			return false;
		else
			return true;
	});
}

void RenderManager::PopRenderable(GameObject * gameObject)
{
	for (int i = 0; i < renderables.size() ;i++)
	{
		if (renderables[i] == gameObject)
			renderables.erase(renderables.begin() + i);
	}
}

void RenderManager::PreRender()
{
	//for (auto renderable : renderables)
	//{
	//	if (renderable->GetActive() == false)
	//		continue;
	//	renderable->PreRender();
	//}
}

void RenderManager::Render()
{

	auto activeRenderables = cpplinq::from_iterators(renderables.begin(), renderables.end())
		>> cpplinq::where([&](GameObject * objPtr)
	{
		if (objPtr->GetActive() == false)
			return false;
		// �÷��̾�� ���� �Ÿ� ������������(ȭ�� ���̸�) ������Ʈ ���� (����� �ؾ���)
		if (GameObjectManager::Get() != nullptr)
		{
			auto player = GameObjectManager::Get()->GetPlayer();
			if (player)
			{
				float dist = DxMath::GetDist(player->transform->position, objPtr->transform->position);
				if (dist > WinMaxWidth && objPtr->GetObjectLayer() != ObjectLayer::BACKGROUND && objPtr->GetObjectLayer() != ObjectLayer::UI)
					return false;
			}
		}
		return true;
	})
		>> cpplinq::to_vector();

	for (auto renderable : activeRenderables)
		renderable->Render();
}

void RenderManager::SortRenderable()
{
	sort(renderables.begin(), renderables.end(), [](GameObject* lhs, GameObject* rhs)->bool
	{
		if ((int)lhs->GetRenderLayer() >= (int)rhs->GetRenderLayer())
			return false;
		else
			return true;
	});
}

RenderManager::RenderManager()
{
}

RenderManager::~RenderManager()
{
}
