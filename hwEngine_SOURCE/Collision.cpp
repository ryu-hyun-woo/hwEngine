#include "Collision.h"

namespace hw
{
	//std::vector<GameObject*> Collision::mGameObjects = {};
	std::array<GameObject*, 300> Collision::mGameObjects = {};
	UINT Collision::mGameObjectIndex = 0;
	
	Collision::Collision()
	{
		//mGameObjects.reserve(300);
	}

	Collision::~Collision()
	{
	}


	void Collision::Update()
	{
		//size_t size = mGameObjects.size();
		size_t size = mGameObjectIndex;
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

				if (CheckObject(obj1, obj2))
				{
					obj1.SetActive(false);
					obj2.SetActive(false);
				}
			}
		}
	}

	bool Collision::CheckObject(const GameObject& obj1, const GameObject& obj2)
	{
		float obj1Left = obj1.GetPositionX();
		float obj1Right = obj1Left + obj1.GetWidth();
		float obj1Top = obj1.GetPositionY();
		float obj1Bottom = obj1Top + obj1.GetHeight();

		float obj2Left = obj2.GetPositionX();
		float obj2Right = obj2Left + obj2.GetWidth();
		float obj2Top = obj2.GetPositionY();
		float obj2Bottom = obj2Top + obj2.GetHeight();

		return (obj1Right > obj2Left &&
				obj1Left < obj2Right &&
				obj1Bottom > obj2Top &&
				obj1Top < obj2Bottom);
	}
}
