#include <stdio.h>
#include "common.h"

#pragma comment(lib, "opengl32.lib") //�����ڹ�����������
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "winmm.lib") //timeGetTime

#include "command/command_render_point.h"
#include "command/command_render_line.h"
#include "command/command_render_line_loop.h"
#include "command/command_render_line_strip.h"
#include "command/command_render_tringles.h"
#include "command/command_render_tringlestrip.h"
#include "command/command_render_tringlefan.h"
#include "command/command_render_quads.h"
#include "command/command_render_pan_rotate_zoom_matrix_light.h"
#include "command/command_render_texture.h"
#include "command/command_render_objmodel.h"
#include "command/command_render_skybox.h"
#include "context/camera.h"
#include "context/image_sprite.h"
#include "context/ground.h"


LH::Camera camera;
POINT originalPos;
bool isRotateView;
/* �����û���������;LRESULT(��������ֵ����); CALLBACK(���÷�ʽ)
   hwnd(���ھ�������ڱ���û���������һ������); msg(��ϢID������1��ʾ�û���ק�˴���);
   wParam(��Ϣ���������������û���ק���ڣ������ϵ�ʲô�ط�ȥ��); lParam(��Ϣ��������)
*/
LRESULT CALLBACK GLWindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_MOUSEMOVE:
		//if (isRotateView)
		//{
		//	POINT currentPos;
		//	currentPos.x = LOWORD(lParam);
		//	currentPos.y = HIWORD(lParam);
		//	ClientToScreen(hwnd, &currentPos);
		//	int deltaX = currentPos.x - originalPos.x;
		//	int deltaY = currentPos.y - originalPos.y;
		//	float angle = (float)deltaY / 100000;
		//	if (deltaY > 0)
		//	{
		//		camera.Pitch(angle);
		//	}
		//	else if (deltaY <0)
		//	{
		//		camera.Pitch(-angle);
		//	}
		//}
		break;
	case WM_RBUTTONDOWN:
		//originalPos.x = LOWORD(lParam);
		//originalPos.y = HIWORD(lParam);
		//ClientToScreen(hwnd, &originalPos); //ת����Ļ����
		//SetCapture(hwnd);
		//ShowCursor(false);
		//isRotateView = true;
		break;
	case WM_RBUTTONUP:
		//SetCursorPos(originalPos.x, originalPos.y);
		//ReleaseCapture();
		//ShowCursor(true);
		//isRotateView = false;
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case 'A':
			camera.mIsMoveLeft = true;
			break;
		case 'D':
			camera.mIsMoveRight = true;
			break;
		case 'W':
			camera.mIsMoveForward = true;
			break;
		case 'S':
			camera.mIsMoveBackward = true;
			break;
		default:
			break;
		}
		break;
	case WM_KEYUP:
		switch (wParam)
		{
		case 'A':
			camera.mIsMoveLeft = false;
			break;
		case 'D':
			camera.mIsMoveRight = false;
			break;
		case 'W':
			camera.mIsMoveForward = false;
			break;
		case 'S':
			camera.mIsMoveBackward = false;
			break;
		default:
			break;
		}
		break;
	case WM_CLOSE: //Ŀǰֻ�����˳����ڵ���Ϣ
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

/* INT����������ֵ���ͣ�; WINAPI���������η�,ǿ�����÷�ʽ��;
   ����ϵͳ����ʱ����Ĳ�����hInstance����ǰӦ�ó����ʵ��),hPrevInstance����һ�θ�Ӧ�ó���������ʵ������
   lpCmdLine������������������Ĳ�����,nShowCmd��������ʾ��ز�����*/ 
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	//�������ڰ����Ĳ���ע�ᣬ��������ʾ�������û�����

	//ע�ᴰ��
	WNDCLASSEX windClass; //�ô˽ṹ����߲���ϵͳ������Ҫһ��ʲô���Ĵ���
	windClass.cbClsExtra = NULL; //�������͵Ķ���ռ䣨�ڴ����ǲ���Ҫ����Ŀռ䣩
	windClass.cbSize = sizeof(WNDCLASSEX); //windClass�������ʵ��ռ�õ��ڴ�
	windClass.cbWndExtra = 0; //���ڵĶ����ڴ�
	windClass.hbrBackground = NULL; //ʹ��OpenGL��������ɫ��������Ҫ��GDI����ΪNULL
	windClass.hCursor = LoadCursor(NULL, IDC_ARROW); //���ù�꣨�ڴ�����Ϊ��ͷ��꣩
	windClass.hIcon = NULL; //Ӧ�ó������ļ�������ʾ��ͼ�꣨�ڴ˲����ã�
	windClass.hIconSm = NULL; //Ӧ�ó��������������Ͻ���ʾ��ͼ��
	windClass.hInstance = hInstance; //����ϵͳ����Ĳ���
	windClass.lpfnWndProc = GLWindowProc; //�˺��������û���������������˭���������ǵĴ���
	windClass.lpszClassName = L"GLWindow"; //��������
	windClass.lpszMenuName = NULL; //�˵������֣�û�в˵������գ�
	windClass.style = CS_VREDRAW | CS_HREDRAW; //����ˢ��ʱ���õ��ػ淽ʽ���ڴ˲���ˮƽ���ߴ�ֱ�ػ�ķ�ʽ��
	ATOM atom = RegisterClassEx(&windClass);
	if (!atom)
	{
		MessageBox(NULL, L"Notice", L"Error", MB_OK);
		return 0;
	}

	//�ӿڴ�С
	RECT rect;
	rect.left = 0;
	rect.right = 800;
	rect.top = 0;
	rect.bottom = 600;
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, NULL); // ���ڷ��Ͳ˵����
	int windowWidth = rect.right - rect.left;
	int windowHeight = rect.bottom - rect.top;

	//��������
	//�������ζ�ӦΪ�����ڴ����ķ�񣬴������ƣ�ע��ʱ�����ƣ�, �������ϽǱ����������ڵķ�񣬴�����ʼλ�ã����ڵĿ�͸�, �����ڵľ�����˵������ ����ʵ��
	HWND hwnd = CreateWindowEx(NULL, L"GLWindow", L"Opengl Window", WS_OVERLAPPEDWINDOW, 100, 100, windowWidth, windowHeight, NULL, NULL, hInstance, NULL);

	//����opengl��Ⱦ����
	HDC dc = GetDC(hwnd);
	PIXELFORMATDESCRIPTOR pfd;
	memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.nVersion = 1;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.cColorBits = 32; //һ������ռ��32bit��RGBA�ֱ�ռ��8bit
	pfd.cDepthBits = 24; //��Ȼ�����ÿ������ռ24it��������
	pfd.cStencilBits = 8; //�ɰ建����ÿ������ռ8bit
	pfd.iPixelType = PFD_TYPE_RGBA; //������������
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER; //����һ��������flag
	int pixelFormat = ChoosePixelFormat(dc, &pfd);
	SetPixelFormat(dc, pixelFormat, &pfd);
	HGLRC rc = wglCreateContext(dc); //��Ⱦ����
	wglMakeCurrent(dc, rc); //ʹ��Ⱦ������Ч

	//��ʼ��
	glClearColor(0.1f, 0.4f, 0.6f, 1.0f); //��������ɫ

	//command
	LH::RenderObjModelCommand* objModelCommand = new LH::RenderObjModelCommand();
	objModelCommand->Init();

	LH::RenderSkyBoxCommand* skyBoxCommand = new LH::RenderSkyBoxCommand();
	skyBoxCommand->Init_i();

	//�����
	camera.mViewPortWidth = windowWidth;
	camera.mViewPortHeight = windowHeight;
	

	//��ʾ����
	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd); //������ʾ�����п�������ģ���Ҫˢ��һ�δ���

	//ʹ�ö�����������Ż�
	//float verters[] = { //������Щ���������Ǵ�ģ�������������
	//	-1 * (windowWidth / 2.0), -1 * (windowHeight / 2.0), 0.0f,
	//	0.0f, -1 * (windowHeight / 2.0), 0.0f,
	//	0.0f, 0.0f, 0.0f,
	//	-1 * (windowWidth / 2.0), 0.0f, 0.0f
	//};

	//float texcoords[] = {
	//	0.0f, 0.0f,
	//	1.0f, 0.0f,
	//	1.0f, 1.0f,
	//	0.0f, 1.0f
	//};

	//2d����
	//LH::ImageSprite imageSprite;
	//LH::Texture* textture = LH::Texture::LoadTextures("res/head.png");
	//imageSprite.SetTexture(textture);
	//imageSprite.SetRect(-200.0f, -200.0f, 100, 100);
	//�Լ�����texture:��������
	LH::ImageSprite imageSprite;
	LH::Texture* textture = new LH::Texture();
	textture->CreateTexture(256);
	imageSprite.SetTexture(textture);
	imageSprite.SetRect(-200.0f, -200.0f, 20.f, 20.f);


	//����
	LH::Ground ground;
	ground.Init();

	//��ѭ�������ִ�����ʾ
	MSG msg;
	static float sTimeSinceStartUp = timeGetTime() / 1000.0f;
	while (true)
	{
		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		float currentTime = timeGetTime() / 1000.0f;
		float timeElapse = currentTime - sTimeSinceStartUp;
		sTimeSinceStartUp = currentTime;

		camera.SwitchTo3D();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //������ɫ��������glClear(GL_DEPTH_BUFFER_BIT)�����ֵȫ�����1.0����Χ0~1

		//set up camera
		camera.Update(timeElapse);

		skyBoxCommand->SetCameraPosition(camera.mEye.x, camera.mEye.y, camera.mEye.z);
		skyBoxCommand->Render();

		//����
		ground.Draw();

		//����
		glDisable(GL_DEPTH_TEST);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_COLOR, GL_ONE);
		glPushMatrix();
		glTranslatef(0.0f, -2.0f, 0.0f);
		glRotatef(180.0f, 1.0f, 0.0f, 0.0f);
		objModelCommand->Render();
		glPopMatrix();
		glEnable(GL_DEPTH_TEST);
		glDisable(GL_BLEND);
		//����
		objModelCommand->Render();

		//glViewport(0, windowHeight / 2, windowWidth / 2, windowHeight / 2);//�涨����������,���ӿ�
		//��2Dͼ��֮ǰ��Ҫ�л���2D�������
		camera.SwitchTo2D();
		////////////////////
		//glBegin(GL_QUADS);
		//glTexCoord2f(0.0, 0.0);
		//glVertex3f(-1*(windowWidth/2.0), -1*(windowHeight/2.0), 0.0f);
		//glTexCoord2f(1.0, 0.0);
		//glVertex3f(0.0f, -1*(windowHeight / 2.0), 0.0f);
		//glTexCoord2f(1.0, 1.0);
		//glVertex3f(0.0f, 0.0f, 0.0f);
		//glTexCoord2f(0.0, 1.0);
		//glVertex3f(-1*(windowWidth / 2.0), 0.0f, 0.0f);
		//glEnd();
		//���������Ż�
		//glPushMatrix();
		//glEnableClientState(GL_VERTEX_ARRAY); //������������
		//glVertexPointer(3/*һ������ٸ�����*/, GL_FLOAT/*ÿ�����ݵ�����*/, 0/*��û�м��*/, verters/*Դ����*/);
		//glEnableClientState(GL_TEXTURE_COORD_ARRAY); //������������
		//glTexCoordPointer(2/*һ������ٸ�����*/, GL_FLOAT/*ÿ�����ݵ�����*/, 0/*��û�м��*/, texcoords/*Դ����*/);
		//glDrawArrays(GL_QUADS, 0/*��0�ŵ㿪ʼ��*/, 4/*���ĸ���*/);
		//glPopMatrix();
		//2D�����װ
		imageSprite.Draw();

		SwapBuffers(dc); //����ǰ�󻺳���ʹ���û����Կ���
	}
	return 0;
}