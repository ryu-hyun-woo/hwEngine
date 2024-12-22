#pragma once
#include "GameObject.h"
#include "Bullet.h"

namespace hw
{
	class Player : public GameObject
	{
	public:
		Player();
		~Player();

		void Fire();
		void Update();
		void Render(HDC hdc);

	private:
		Bullet mBullets[50];
		UINT mBulletIndex;
	};
}