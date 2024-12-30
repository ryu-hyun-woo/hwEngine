#include "Player.h"
#include "Player.h"
#include "Player.h"
#include "Player.h"
#include "Input.h"
#include "CollisionManager.h"
#include "SceneManager.h"

namespace hw
{
	Player::Player()
		: mBulletIndex(0)
	{
	}

	Player::~Player()
	{
	}

	void Player::Fire()
	{
		Vector2 firePosition = { mPosition.mX + mSize.mX / 2, 
							  	 mPosition.mY + mSize.mY / 2 };
		mBullets[mBulletIndex % 50].Fire(firePosition);
		mBulletIndex++;
	}

	void Player::Initialize()
	{
		SetActive(true);
		for (auto& bullet : mBullets)
		{
			bullet.Initialize();
		}
	}

	void Player::Update()
	{
		float move = 0.1f * mSpeed;

		if (Input::IsKeyPressed('A'))
		{
			mPosition.mX -= move;
		}

		if (Input::IsKeyPressed('D'))
		{
			mPosition.mX += move;
		}

		if (Input::IsKeyPressed('W'))
		{
			mPosition.mY -= 0.1f * mSpeed;
		}

		if (Input::IsKeyPressed('S'))
		{
			mPosition.mY += 0.1f * mSpeed;
		}

		if (Input::IsKeyPressed('1'))
		{
			SceneManager::LoadScene("TITLE")->Initialize();
		}

		if (Input::IsKeyPressed('2'))
		{
			SceneManager::LoadScene("GAME")->Initialize();
		}

		if (Input::IsKeyPressed('3'))
		{
			SceneManager::LoadScene("END")->Initialize();
		}

		if (Input::IsKeyDown(VK_SPACE))
		{
			Fire();
		}


		for (auto& bullet : mBullets)
		{
			if (bullet.GetActive())
			{
				bullet.Update();
			}
		}

	}
	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		for (auto& bullet : mBullets)
		{
			if (bullet.GetActive())
			{
				bullet.Render(hdc);
			}
		}
	}

	void Player::Release()
	{
		SetActive(false);
	}
}
