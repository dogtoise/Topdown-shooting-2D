#pragma once

struct DXDesc
{
	wstring AppName;
	HINSTANCE instance;
	HWND handle;
	UINT width;//������ â�� ���� ���� ũ��
	UINT height;
};

class Window
{
public:
	Window(DXDesc desc);
	~Window();

	WPARAM Run(IObject* mainObj); //���ӷ��� �Լ�




private:
	//�Լ�ȣ�� �Ծ�
	//stdcall
	//cdecl
	static LRESULT CALLBACK WndProc //�޼��� ó���Լ�
	(
		HWND handle,//�â���� �˾ƺ��� â�� �ĺ���
		UINT message,//� �޼����� ���Դ��� �˾ƺ��°�.
		WPARAM wParam,//Ű������ ���õ����� �Ű���尡 ���ȴ��� �˾ƺ��°�.
		LPARAM lParam //���콺�� ��ǥ Ŭ���� ���ȴ��� ���콺�� ��ǥ�� �˾ƺ��°�.
	);
	void MainRender();
	static DXDesc desc;
	IObject* mainObj = nullptr;
	//static class Program* program;
};