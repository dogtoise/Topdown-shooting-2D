#include "Framework.h"//������ΰ�� ../ : ���������� ����������
#include "Window.h"
#include "Graphics.h"
#include "Utilities/UpdateDispatcher.h"
#include "MySQL/LogManager.h"
//#include "Program.h"
//������ : c://program ���� ��ü���
//����� : ./ �������� , ../ ��������

DXDesc Window::desc;

//Program* Window::program = nullptr;
HINSTANCE instance;

Window::Window(DXDesc desc)
{
	WNDCLASSEX wndClass;

	wndClass.cbClsExtra = 0;//���񿵿� ������ �߾�������.
	wndClass.cbWndExtra = 0;//�̰͵� �߾�������.
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//���� ���� �޸𸮿� �ö󰣰� �����ؿ��½�.
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);//Ŀ����� ȭ��ǥ����� Ŀ���� �����´�.
	wndClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);//������ �ΰ�
	wndClass.hIconSm = wndClass.hIcon;
	wndClass.hInstance = desc.instance;//�����ڿ��� �޾��ִ°� ����α׷����� Ȯ���ϴ°�
	wndClass.lpfnWndProc = (WNDPROC)WndProc;//�޼���ó���Լ��� �ּҰ� ��.�Լ������Ͱ� ���°�
	wndClass.lpszClassName = desc.AppName.c_str();//Ŭ���� �̸������ֱ�
	wndClass.lpszMenuName = NULL;//�޴��̸��ε� �Ⱦ��⶧���� ���� ��־����.
	wndClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;//������ â�� ��Ÿ��
	wndClass.cbSize = sizeof(WNDCLASSEX);//������츦 ����ؼ� �������.

	WORD wHr = RegisterClassEx(&wndClass);
	assert(wHr != 0);//������� �����ϸ� �̰� ���õǼ� ������ ǥ�õ�������. / ������ ���

	desc.handle = CreateWindowEx
	(
		WS_EX_APPWINDOW,//��Ÿ�� Ȯ��� �ɼ�
		desc.AppName.c_str(),//Ŭ���� ����
		desc.AppName.c_str(),//������ â�� �̸�
		WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_OVERLAPPEDWINDOW,//��Ÿ��
		CW_USEDEFAULT,//������ â�� ��ǥ,�⺻�� ������ X ��ǥ�� ����
		CW_USEDEFAULT,//������ â�� ��ǥ,�⺻�� ������ Y ��ǥ�� ����
		CW_USEDEFAULT,//������ â�� ���� ũ��,�⺻�� ���߿��߰�
		CW_USEDEFAULT,//������ â�� ���� ũ��,�⺻�� ���߿��߰�
		NULL,//�θ�â�� �ڵ�
		(HMENU)NULL,//�޴��� �ĺ��������� �����ʾƼ� �� ������
		desc.instance,//� ������ ���α׷����� �ĺ���
		NULL//�Ⱦ� �׳ɵ�
	);

	RECT rect = { 0, 0, (LONG)desc.width, (LONG)desc.height };

	UINT centerX = (GetSystemMetrics(SM_CXSCREEN) - (UINT)desc.width) / 2;
	UINT centerY = (GetSystemMetrics(SM_CYSCREEN) - (UINT)desc.height) / 2;

	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

	MoveWindow
	(
		desc.handle
		, centerX, centerY
		, rect.right - rect.left, rect.bottom - rect.top
		, true
	);

	ShowWindow(desc.handle, SW_SHOWNORMAL);//������â�� ���̰����ִ°�
	SetForegroundWindow(desc.handle);//����������� �������� �ö�����ϴ°�
	SetFocus(desc.handle);//��Ŀ�� , Ű���峪 ���콺�� �������� �����̵Ǵ�â.

	ShowCursor(true);//����
	Window::desc = desc;

	::instance = desc.instance;

}

Window::~Window()
{
	DestroyWindow(desc.handle);
	UnregisterClass(desc.AppName.c_str(), desc.instance);
}

WPARAM Window::Run(IObject* mainObj)//�޼���ó���Լ��� �Ѱ��ִ¿�Ȱ / ���߿� ���� �ǵ帲
{
	MSG msg = { 0 };
	
	this->mainObj = mainObj;

	Graphics::Create();
	Keyboard::Create();
	Mouse::Create();
	Time::Create();
	Gui::Create();
	LogManager::Create();

	this->mainObj->Init();

	Time::Get()->Start();

	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))//�޼��� ť / ��⿭ �������� �޼������� ó���Ѵ�. / PM_REMOVE �� �޼����� �а� �����ִ� ��Ȱ. / GetMessage �ٸ��޼����� ���ö����� ��� / PeekMessage �޼����� �ȵ��͵� �ٸ��۾��� ��� ������.
		{
			if (msg.message == WM_QUIT)
				break;
		
			TranslateMessage(&msg);//Ű���� �޼���ó���� �����ִ��Լ�.
			DispatchMessage(&msg);//�޼����Լ��� �޼����� �����ִ¿�Ȱ.
		}
		else
		{
			MainRender();
		//	Keyboard::Get()->Update();
		////	program->Update();
		//	Graphics::Get()->Begin();
		//	{
		//	//	program->Render();
		//	}
		//	Graphics::Get()->End();
		}
	}
	this->mainObj->Destroy();
	
	//SAFE_DELETE(program);
	LogManager::Delete();
	Gui::Delete();
	Time::Delete();
	Mouse::Delete();
	Keyboard::Delete();
	Graphics::Delete();




	return msg.wParam;
}


HWND handle;
LRESULT Window::WndProc(HWND handle, UINT message, WPARAM wParam, LPARAM lParam)//�޼��� ó���Լ� / api �ϴµ��ȿ��� �ǵ帲
{
	Mouse::Get()->InputProc(message, wParam, lParam);
	Gui::Get()->MsgProc(handle, message, wParam, lParam);

	if (message == WM_CREATE)
	::handle = handle;


	if (message == WM_CLOSE || message == WM_DESTROY)
	{
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(handle, message, wParam, lParam);
}

void Window::MainRender()
{

	if (ImGui::GetIO().WantCaptureMouse == false)
	{
		Mouse::Get()->Update();
		Keyboard::Get()->Update();
	}

	Time::Get()->Update();
	Gui::Get()->Update();
	mainObj->Update();
	UpdateDispatcher::Update();

	mainObj->PreRender();
	//	program->Update();
	Graphics::Get()->Begin();
	{
		//	program->Render();
		mainObj->Render();
		
		mainObj->GUI();
		Gui::Get()->Render();
	}
	Graphics::Get()->End();
}
