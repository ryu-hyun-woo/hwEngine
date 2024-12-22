#include "Player.h"
#include "Player.h"
#include "Input.h"
#include "Collision.h"

namespace hw
{
	Player::Player()
		: mBulletIndex(0)
	{
		//for (const auto& bullet : mBullets)
		//{
		//	Collision::SetCollisionObject(bullet);
		//}

		for (int i = 0; i < 50; i++)
		{
			Collision::SetCollisionObject(&mBullets[i]);
		}
	}

	Player::~Player()
	{
	}

	void Player::Fire()
	{
		mBullets[mBulletIndex % 50].Fire(mX + mWidth / 2, mY + mHeight / 2);
		mBulletIndex++;
	}

	void Player::Update()
	{
		if (Input::IsKeyPressed('A'))
		{
			mX -= 0.1f * mSpeed;
		}

		if (Input::IsKeyPressed('D'))
		{
			mX += 0.1f * mSpeed;
		}

		if (Input::IsKeyPressed('W'))
		{
			mY -= 0.1f * mSpeed;
		}

		if (Input::IsKeyPressed('S'))
		{
			mY += 0.1f * mSpeed;
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
}
