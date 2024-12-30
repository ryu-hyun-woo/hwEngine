#include "CollisionManager.h"

namespace hw
{
	std::vector<GameObject*> CollisionManager::mGameObjects = {};
	
	CollisionManager::CollisionManager()
	{
		mGameObjects.reserve(300);
	}

	CollisionManager::~CollisionManager()
	{
	}


	void CollisionManager::Update()
	{
		size_t size = mGameObjects.size();

		if (size <= 1)
		{
			return;
		}

		for (int i = 0; i <= size - 1; i++)
		{
			GameObject& obj1 = *mGameObjects[i];

			if (!obj1.GetActive()) 
			{ 
				continue; 
			}

			for (int j = i + 1; j < size; j++)
			{
				GameObject& obj2 = *mGameObjects[j];

				if (!obj2.GetActive()) 
				{ 
					continue; 
				}

				if (CheckAABBObject(obj1, obj2))
				{
					//생각해보기 비용큼
					dynamic_cast<ICollision*>(&obj1)->OnCollision();
					dynamic_cast<ICollision*>(&obj2)->OnCollision();
				}
			}
		}
	}

	bool CollisionManager::CheckAABBObject(const GameObject& obj1, const GameObject& obj2)
	{
		float obj1Left = obj1.GetPosition().mX;
		float obj1Right = obj1Left + obj1.GetSize().mX;
		float obj1Top = obj1.GetPosition().mY;
		float obj1Bottom = obj1Top + obj1.GetSize().mY;

		float obj2Left = obj2.GetPosition().mX;
		float obj2Right = obj2Left + obj2.GetSize().mX;
		float obj2Top = obj2.GetPosition().mY;
		float obj2Bottom = obj2Top + obj2.GetSize().mY;

		return (obj1Right > obj2Left &&
				obj1Left < obj2Right &&
				obj1Bottom > obj2Top &&
				obj1Top < obj2Bottom);
	}
}
