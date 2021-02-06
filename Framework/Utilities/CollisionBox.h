#pragma once

//#define COLLISION_RENDER
class CollisionBox
{
public:
	CollisionBox(Vector3 * position, Vector3 * scale, float * rotation);
	~CollisionBox();

public:
	bool OBB(CollisionBox * other);
	static bool OBB(CollisionBox * box1, CollisionBox * box2);

	void Update();
	void Render();
	const Vector3& GetPosition() const;
	const Vector3& GetScale() const;

	const float& GetRotation() const;
	void SetTransform(Vector3* position, Vector3 * scale, float * rotation);

	bool IsStaying(CollisionBox * other);
	void PushStayedCollider(CollisionBox * other);
	void PopStayedCollider(CollisionBox * other);
private:
	// rect�� ȸ���� y���� �޾ƿ´�.
	static Vector3 GetHeightVector(CollisionBox collisionBox);
	// rect�� ȸ���� x���� �޾ƿ´�.
	static Vector3 GetWidthVector(CollisionBox collisionBox);
	// ���� ����ȭ
	static 	Vector3 GetUnitVector(Vector3 vec);

private:
	Vector3 * position;
	Vector3 * scale;
	float * rotation;

private:
	vector<VertexTexture> vertices;
	VertexBuffer * vb = nullptr;

	vector<UINT> indices;
	IndexBuffer* ib = nullptr;

	VertexShader * vs = nullptr;
	PixelShader * ps = nullptr;
	ID3DBlob * vsBlob = nullptr;

	InputLayout * il = nullptr;
	ID3DBlob * psBlob = nullptr;

	D3DXMATRIX world;
	D3DXMATRIX S, R, T;

	WorldBuffer * wb = nullptr;

	list<CollisionBox*> stayingColliders;

};