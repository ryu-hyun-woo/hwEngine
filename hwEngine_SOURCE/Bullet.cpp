#include "Bullet.h"
#include "Bullet.h"
#include "Bullet.h"

namespace hw
{
	Bullet::Bullet()
	{
		SetSpeed(5.f);
		SetSize(10.f, 10.f);
		SetActive(false);
	}

	void Bullet::Update()
	{
		if (!mActive)
		{
			return;
		}

		if (mActive)
		{
			mX += mSpeed;
		}

		if (mX > 1600)
		{
			SetActive(false);
		}
	}

	void Bullet::SetPosition(float x, float y)
	{
		mX = x;
		mY = y;
	}

	void Bullet::Fire(float x, float y)
	{
		SetActive(true);
		SetPosition(x, y);
	}
}
