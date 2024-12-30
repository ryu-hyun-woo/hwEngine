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

		SceneManager::CreateScene("TITLE");
		SceneManager::CreateScene("GAME");
		SceneManager::CreateScene("END");
		
		//Player
		mPlayer1.SetPosition({ 100.f, 100.f });
		mPlayer1.SetSize({ 100.f, 100.f });
		mPlayer1.SetSpeed(3.0f);
		mPlayer1.SetColor(RGB(255, 255, 0));

		mPlayer2.SetPosition({ 200.f, 200.f });
		mPlayer2.SetSize({ 100.f, 200.f });
		mPlayer2.SetSpeed(2.0f);
		mPlayer2.SetColor(RGB(0, 0, 0));

		mPlayer3.SetPosition({ 100.f, 100.f });
		mPlayer3.SetSize({ 100.f, 100.f });
		mPlayer3.SetSpeed(3.0f);
		mPlayer3.SetColor(RGB(125, 125, 125));

		//Enemy
		mEnemy1.SetPosition({ 200.f, 400.f });
		mEnemy1.SetSize({100.f, 100.f });
		mEnemy1.SetSpeed(5.0f);
		mEnemy1.SetColor(RGB(255, 0, 0));

		mEnemy2.SetPosition({ 300.f, 700.f });
		mEnemy2.SetSize({150.f, 150.f });
		mEnemy2.SetSpeed(5.0f);
		mEnemy2.SetColor(RGB(255, 125, 125));

		mEnemy3.SetPosition({ 200.f, 500.f });
		mEnemy3.SetSize({150.f, 150.f });
		mEnemy3.SetSpeed(5.0f);
		mEnemy3.SetColor(RGB(255, 75, 75));

		Scene* scene = SceneManager::LoadScene("TITLE");
		scene->RegisterGameObject<Player>(&mPlayer1);
		scene->RegisterGameObject<Enemy>(&mEnemy1);

		scene = SceneManager::LoadScene("GAME");
		scene->RegisterGameObject<Player>(&mPlayer2);
		scene->RegisterGameObject<Enemy>(&mEnemy2);

		scene = SceneManager::LoadScene("END");
		scene->RegisterGameObject<Player>(&mPlayer3);
		scene->RegisterGameObject<Enemy>(&mEnemy3);

		scene = SceneManager::LoadScene("TITLE");
		scene->Initialize();
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
		SceneManager::Update();
	}

	void Application::LateUpdate()
	{
		SceneManager::LateUpdate();
	}

	void Application::Render()
	{
		Rectangle(mBackHdc, 0, 0, mWidth, mHeight);

		SceneManager::Render(mBackHdc);

		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}
}
