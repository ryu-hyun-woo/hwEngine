#include "Enemy.h"
#include "Enemy.h"
#include "CollisionManager.h"
#include <cstdlib>
#include <ctime>
#include <memory>

namespace hw
{
	Enemy::Enemy()
		: mCount(0)
		, mDirection(Direction::None)
	{
	}

	void Enemy::Initialize()
	{
		SetActive(true);
		CollisionManager::RegisterCollisionObject(this);
		srand((unsigned int)time(nullptr));
		mSpeed = 3.0f;
	}

	void Enemy::Update()
	{
		if (mCount <= 0)
		{
			SetRandom();
		}
		else
		{
			float move = 0.1f * mSpeed;

			if (mDirection == Direction::Left)
			{
				mPosition.mX -= move;
			}
			else if (mDirection == Direction::Right)
			{
				mPosition.mX += move;
			}
			else if (mDirection == Direction::Top)
			{
				mPosition.mY -= move;
			}
			else if (mDirection == Direction::Bottom)
			{
				mPosition.mY += move;
			}

			OffsetOutLine();
		}

		mCount--;
	}

	void Enemy::OnCollision()
	{
		SetActive(false);
	}

	void Enemy::Release()
	{
		SetActive(false);
	}

	void Enemy::SetRandom()
	{
		mCount = rand() % 500 + 200;
		mDirection = (Direction) (rand() % 4);
	}

	void Enemy::OffsetOutLine()
	{
		if (mPosition.mX < 0)
		{
			mPosition.mX = 0;
			mCount = 0;
		}
		else if (mPosition.mX + mSize.mX > SCREEN_SIZE_X)
		{
			mPosition.mX = SCREEN_SIZE_X - mSize.mX;
			mCount = 0;
		}
		else if (mPosition.mY < 0)
		{
			mPosition.mY = 0;
			mCount = 0;
		}
		else if (mPosition.mY + mSize.mY > SCREEN_SIZE_Y)
		{
			mPosition.mY = SCREEN_SIZE_Y - mSize.mY;
			mCount = 0;
		}
	}

}
