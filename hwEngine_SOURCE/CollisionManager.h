#pragma once
#include <vector> 
#include <array> 
#include "GameObject.h" 
#include "ICollision.h" 

namespace hw
{
	class CollisionManager
	{
	public:
		CollisionManager();
		~CollisionManager();

		void Update();
		bool CheckAABB(const GameObject& obj1, const GameObject& obj2);

		static void RegisterCollisionObject(ICollision* object)
		{
			if (!object)
			{
				return;
			}

			if (std::find(mCollisionObjects.begin(), mCollisionObjects.end(), object) 
				== mCollisionObjects.end()) 
			{
				mCollisionObjects.push_back(object);
			}
		}

	private:
		static std::vector<ICollision*> mCollisionObjects;
	};
}