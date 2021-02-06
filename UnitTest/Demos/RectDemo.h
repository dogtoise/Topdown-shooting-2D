#pragma once

class RectDemo : public IObject
{
public :
	// IObject��(��) ���� ��ӵ�
	virtual void Init() override;

	virtual void Destroy() override;

	virtual void Update() override;

	virtual void Render() override;

	virtual void PreRender() override;

	virtual void GUI() override;
private :
	//class Rect* r1 = nullptr;
	vector<class Rect*> rects;

};