#pragma once
#include "RenderManager.h"
#include"Utilities/Layers.h"
#include "GameObjectManager.h"
class Transform;
class CollisionBox;
class Animator;
class AlphaBuffer;
class DissolveBuffer;
class ColorBuffer;
class GameObject 
{
	friend class GameObjectManager;
	friend class RenderManager;
public :
	GameObject(Vector3 position, Vector3 size, float rotation, bool hasAnimation);
	GameObject(const GameObject& ref) = default;
	virtual ~GameObject();

private:
	void Update();
	void PreRender();
	void Render();
public:
	void SetActive(bool active);
	bool GetActive();
	RenderLayer GetRenderLayer();
	ObjectLayer GetObjectLayer();
	string GetTag()const { return tag; }
	CollisionBox * GetCollisionBox();

	AlphaBuffer * GetAlphaBuffer();
	ColorBuffer * GetColorBuffer();
	DissolveBuffer * GetDissolveBuffer();
	bool IsRigidbody()
	{
		return isRigidbody;
	}
	virtual void Delete()
	{
		GameObjectManager::Get()->DeleteGameObject(this);
	}
protected :
	virtual void OnPreUpdate();
	virtual void OnUpdate(); 
	virtual void OnPostUpdate();
	virtual void OnPreRender();
	virtual void OnRender();
	virtual void OnPostRender();
	void GeometryUpdate();
	// OnPreEnable, OnPreDisable
	// �� �Լ��� ���� ������Ʈ�� ��Ÿ���� �� Ȥ�� ������� ����
	// ó���ϰ� ���� ������ ��� ó���� �� ��Ÿ���ų� ������� �� �� �ִ�.

	// caution : preEnable�� ����� ��� �ݵ��
	// ���� OnSetAcitve�� ȣ�����ٰ�
	virtual void OnPreEnable(function<void(void)> OnSetActive);
	virtual void OnEnable();
	// caution : preEnable�� ����� ��� �ݵ��
	// ���� OnSetAcitve�� ȣ�����ٰ�
	virtual void OnPreDisable(function<void(void)> OnSetActive);
	virtual void OnDisable();

public :
	virtual void OnCollisionEnter(GameObject* other) 
	{
		if (isRigidbody && other->IsRigidbody() == false)
			other->OnCollisionEnter(this);
	}
	virtual void OnCollisionStay(GameObject* other) 
	{
		if (isRigidbody && other->IsRigidbody() == false)
			other->OnCollisionStay(this);
	}
	virtual void OnCollisionExit(GameObject* other) 
	{
		if (isRigidbody && other->IsRigidbody() == false)
			other->OnCollisionExit(this);
	}

protected :
	void SetDirty(bool dirty);
	bool GetDirty();

	void SetRenderToCollisionBox(bool b);
	void SetSRV(ID3D11ShaderResourceView * srv);
	void SetShader(wstring shaderPath);
	
	void SetCollisionTr(Vector3 * position, Vector3 * scale, float * rotation);
	void SetTag(string tag) { this->tag = tag; }
	

	void SetRenderLayer(RenderLayer renderLayer);
	void SetObjectLayer(ObjectLayer objectLayer);


public :
	ID3D11ShaderResourceView * GetSRV()
	{
		return srv;
	}
	ID3D11ShaderResourceView * GetOriginalSRV()
	{
		return originalSRV;
	}
	Animator * GetAnimator();
	void SetRigidbody(bool isRigidbody)
	{
		this->isRigidbody = isRigidbody;
	}
public :
	class Transform * transform;

private :

private :

	class IntegratedRect * integratedRect = nullptr;
	class AnimationRect* animRect = nullptr;
	class CollisionBox * collisionBox = nullptr;
private :
	bool isDirty = false;
	bool bRenderCollisionBox = false;
	bool isActive = true;
	bool isRigidbody = false;
	string tag = "default";
	ID3D11ShaderResourceView * srv = nullptr;
	ID3D11ShaderResourceView * originalSRV = nullptr; // ������ SRV
	 
	RenderLayer renderLayer = RenderLayer::DEFAULT;
	ObjectLayer objectLayer = ObjectLayer::DEFAULT;
};