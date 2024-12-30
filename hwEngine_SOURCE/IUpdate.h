#pragma once

namespace hw
{
	class IUpdate
	{
	public:
		virtual ~IUpdate() = default;
		virtual void Update() = 0;
	};
}