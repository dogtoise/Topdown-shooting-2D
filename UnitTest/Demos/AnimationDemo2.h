#pragma once

class AnimationDemo2 : public IObject
{
public:
	// IObject��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Destroy() override;
	virtual void Update() override;
	virtual void PreRender() override;
	virtual void Render() override;
	virtual void GUI() override;

private:
	class AnimationRect2* animationRect;
};