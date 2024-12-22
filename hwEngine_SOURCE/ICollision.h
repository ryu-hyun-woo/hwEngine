#pragma once

namespace hw
{
	class ICollision
	{
	public:
		virtual ~ICollision() = default;

		virtual void OnCollision() = 0;
	};
}
