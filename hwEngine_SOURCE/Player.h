#pragma once
#include "GameObject.h"
#include "Bullet.h"
#include "IRelease.h"

namespace hw
{
	class Player : public GameObject
				 , public IUpdate
				 , public IInitialize 
				 , public IRelease 
	{
	public:
		Player();
		~Player();

		void Initialize() override;
		void Update() override;
		void Render(HDC hdc) override;
		void Release() override;

		void Fire();

	private:
		Bullet mBullets[50];
		UINT mBulletIndex;
	};
}