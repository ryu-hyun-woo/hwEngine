#pragma once
#include "GameObject.h"
#include "IInitialize.h"
#include "CollisionManager.h"
#include "ICollision.h"
#include "IRelease.h"

namespace hw
{
	class Bullet : public GameObject
				 , public IUpdate
				 , public IInitialize
				 , public ICollision
				 , public IRelease
	{
	public:
		Bullet();

		void Initialize() override;
		void Update() override;
		void OnCollision() override;
		void Release() override;

		void SetPosition(const Vector2& position);
		void Fire(const Vector2& position);
	private:
	};
}