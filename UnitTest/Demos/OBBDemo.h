#pragma once

class OBBDemo : public IObject
{
	// IObject��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Destroy() override;
	virtual void Update() override;
	virtual void PreRender() override;
	virtual void Render() override;
	virtual void GUI() override;

private :
	class OBBRect* ob1 = nullptr;
	class OBBRect* ob2 = nullptr;
};