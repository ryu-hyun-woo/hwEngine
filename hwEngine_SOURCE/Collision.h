#pragma once
#include <vector> 
#include <array> 
#include "GameObject.h" 

namespace hw
{
	class Collision
	{
	public:
		Collision();
		~Collision();

		void Update();
		bool CheckObject(const GameObject& obj1, const GameObject& obj2);

		static void SetCollisionObject(GameObject* object)
		{
			//if (!object) return;
			//if (object && std::find(mGameObjects.begin(), mGameObjects.end(), object) == mGameObjects.end()) 
			//{
			//	mGameObjects.push_back(object);
			//}

			mGameObjects[mGameObjectIndex++] = object;
		}

	private:
		//static std::vector<GameObject*> mGameObjects;
		static std::array<GameObject*, 300> mGameObjects;
		static UINT mGameObjectIndex;
	};
}