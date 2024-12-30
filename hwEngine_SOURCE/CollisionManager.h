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
		bool CheckAABBObject(const GameObject& obj1, const GameObject& obj2);

		static void RegisterCollisionObject(GameObject* object)
		{
			if (!object)
			{
				return;
			}

			if (std::find(mGameObjects.begin(), mGameObjects.end(), object) == mGameObjects.end()) 
			{
				mGameObjects.push_back(object);
			}
		}

	private:
		static std::vector<GameObject*> mGameObjects;
	};
}