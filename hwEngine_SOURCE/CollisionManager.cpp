#include "CollisionManager.h"

namespace hw
{
	std::vector<ICollision*> CollisionManager::mCollisionObjects = {};
	
	CollisionManager::CollisionManager()
	{
		mCollisionObjects.reserve(300);
	}

	CollisionManager::~CollisionManager()
	{
	}


	void CollisionManager::Update()
	{
		size_t size = mCollisionObjects.size();

		if (size <= 1)
		{
			return;
		}

		for (int i = 0; i <= size - 1; i++)
		{
			const GameObject& obj1 = mCollisionObjects[i]->GetGameObject();

			if (!obj1.GetActive()) 
			{ 
				continue; 
			}

			for (int j = i + 1; j < size; j++)
			{
				const GameObject& obj2 = mCollisionObjects[j]->GetGameObject();

				if (!obj2.GetActive()) 
				{ 
					continue; 
				}

				if (CheckAABB(obj1, obj2))
				{
					mCollisionObjects[i]->OnCollision();
					mCollisionObjects[j]->OnCollision();
				}
			}
		}
	}

	bool CollisionManager::CheckAABB(const GameObject& obj1, const GameObject& obj2)
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
