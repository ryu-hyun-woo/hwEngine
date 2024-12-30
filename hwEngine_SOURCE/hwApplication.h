#pragma once
#include "CommonInclude.h"
#include "GameObject.h"
#include "Enemy.h"
#include "Input.h"
#include "Bullet.h"
#include "Player.h"
#include "CollisionManager.h"
#include "SceneManager.h"

namespace hw
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hWnd, UINT width, UINT height);
		void CreateBackBuffer(UINT width, UINT height);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		UINT mWidth;
		UINT mHeight;

		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mNewBitmap;
		HBITMAP mOldBitmap;

		CollisionManager mCollision;

		Player mPlayer1;
		Enemy mEnemy1;

		Player mPlayer2;
		Enemy mEnemy2;

		Player mPlayer3;
		Enemy mEnemy3;

		Input mInput;
	};
}