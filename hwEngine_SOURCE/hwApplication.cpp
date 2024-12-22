#include "hwApplication.h"

namespace hw
{
	Application::Application()
		: mWidth(0)
		, mHeight(0)
		, mHwnd(nullptr)
		, mHdc(nullptr)
		, mBackHdc(nullptr)
		, mNewBitmap(nullptr)
		, mOldBitmap(nullptr)
	{
	}

	Application::~Application()
	{
		ReleaseDC(mHwnd, mHdc);
		SelectObject(mBackHdc, mOldBitmap);
		DeleteDC(mBackHdc);
		DeleteObject(mNewBitmap);
	}

	void Application::Initialize(HWND hWnd, UINT width, UINT height)
	{
		mHwnd = hWnd;
		mHdc = GetDC(hWnd);
		CreateBackBuffer(width, height);

		mWidth = width;
		mHeight = height;

		mInput.Initialize();

		//Player
		mPlayer.SetPosition(100.f, 100.f);
		mPlayer.SetSize(100.f, 100.f);
		mPlayer.SetSpeed(3.0f);
		mPlayer.SetColor(RGB(255, 255, 0));

		//Enemy
		mEnemy.SetPosition(700.f, 200.f);
		mEnemy.SetSize(150.f, 150.f);
		mEnemy.SetSpeed(5.0f);
		mEnemy.SetColor(RGB(255, 0, 0));
	}

	void Application::CreateBackBuffer(UINT width, UINT height)
	{
		mBackHdc = CreateCompatibleDC(mHdc);
		mNewBitmap = CreateCompatibleBitmap(mHdc, width, height);
		mOldBitmap = (HBITMAP)SelectObject(mBackHdc, mNewBitmap);
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		mInput.Update();
		mCollision.Update();
		mPlayer.Update();
		mEnemy.Update();
	}

	void Application::LateUpdate()
	{
		mPlayer.LateUpdate();
		mEnemy.LateUpdate();
	}

	void Application::Render()
	{
		Rectangle(mBackHdc, 0, 0, mWidth, mHeight);
		mPlayer.Render(mBackHdc);
		mEnemy.Render(mBackHdc);

		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}
}
