#pragma once
#include "GameObject.h"
#include "ICollision.h"

namespace hw
{
	class Enemy : public GameObject 
	{
	public:
		Enemy();
		
		void Update();
		void SetRandom();
		void OffsetOutLine();

	private:
		enum class Direction 
		{
			Left,
			Right,
			Top,
			Bottom,
			None
		};
		int mCount;
		Direction mDirection;
	};
}