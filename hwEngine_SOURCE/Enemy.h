#pragma once
#include "GameObject.h"
#include "IUpdate.h"
#include "IInitialize.h"
#include "ICollision.h"
#include "IRelease.h"

namespace hw
{
	class Enemy : public GameObject 
				, public IUpdate
				, public IInitialize
				, public ICollision 
				, public IRelease
	{
	public:
		Enemy();
		
		void Initialize() override;
		void Update() override;
		void OnCollision() override;
		void Release() override;
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