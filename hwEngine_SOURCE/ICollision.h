#pragma once

namespace hw
{
	class GameObject;
	class ICollision
	{
	public:
		virtual ~ICollision() = default;
		virtual const GameObject& GetGameObject() const = 0;
		virtual void OnCollision() = 0;
	};
}
