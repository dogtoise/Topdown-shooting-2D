#pragma once


class RTTDemo : public IObject
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
	class RenderTexture * rtt = nullptr;
	class Rect* r = nullptr; // �׳� ���������� ��� 
	class Rect* r2 = nullptr;
	class Rect* r3 = nullptr;
	
	class TextureRect* rt2 = nullptr; // <- RTT�� �̹����� ���⿡ ���  (minimap)


	class TextureRect* rt1 = nullptr; // greyscale?

};