#include "Enemy.h"
#include "Enemy.h"
#include "Enemy.h"
#include "Enemy.h"
#include "Enemy.h"
#include "Collision.h"
#include <cstdlib>
#include <ctime>
#include <memory>

namespace hw
{
	Enemy::Enemy()
		: mCount(0)
		, mDirection(Direction::None)
	{
		Collision::SetCollisionObject(this);
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
				mX -= move;
			}
			else if (mDirection == Direction::Right)
			{
				mX += move;
			}
			else if (mDirection == Direction::Top)
			{
				mY -= move;
			}
			else if (mDirection == Direction::Bottom)
			{
				mY += move;
			}

			OffsetOutLine();
		}

		mCount--;
	}

	void Enemy::SetRandom()
	{
		mCount = rand() % 500 + 200;
		mDirection = (Direction) (rand() % 4);
	}

	void Enemy::OffsetOutLine()
	{
		if (mX < 0)
		{
			mX = 0;
			mCount = 0;
		}
		else if (mX + mWidth > 1600)
		{
			mX = 1600 - mWidth;
			mCount = 0;
		}
		else if (mY < 0)
		{
			mY = 0;
			mCount = 0;
		}
		else if (mY + mHeight > 900)
		{
			mY = 900 - mHeight;
			mCount = 0;
		}
	}

}
