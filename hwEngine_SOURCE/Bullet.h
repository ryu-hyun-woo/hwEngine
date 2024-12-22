#pragma once
#include "GameObject.h"
#include "ICollision.h"

namespace hw
{
	class Bullet : public GameObject 
	{
	public:
		Bullet();

		void Update();
		void SetPosition(float x, float y);
		void Fire(float x, float y);

	private:
	};
}