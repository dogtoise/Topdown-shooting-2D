#pragma once

class ShaderFilterDemo : public IObject
{
public:
	// IObject��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Destroy() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void PreRender() override;
	virtual void GUI() override;

private:
	class TextureFilterRect * tr1 = nullptr;
};