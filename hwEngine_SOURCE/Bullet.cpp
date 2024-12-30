#include "Bullet.h"
#include "Bullet.h"
#include "Bullet.h"

namespace hw
{
	Bullet::Bullet()
	{
	}

	void Bullet::Initialize()
	{
		SetSpeed(5.f);
		SetSize({ 10.f, 10.f });
		CollisionManager::RegisterCollisionObject(this);
	}

	void Bullet::Update()
	{
		if (!mActive)
		{
			return;
		}

		mPosition.mX += mSpeed;

		if (mPosition.mX > SCREEN_SIZE_X)
		{
			SetActive(false);
		}
	}

	void Bullet::OnCollision()
	{
		SetActive(false);
	}

	void Bullet::Release()
	{
		SetActive(false);
	}

	void Bullet::SetPosition(const Vector2& position)
	{
		mPosition = position;
	}

	void Bullet::Fire(const Vector2& position)
	{
		SetActive(true);
		SetPosition(position);
	}
}
