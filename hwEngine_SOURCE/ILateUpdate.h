#pragma once

namespace hw
{
	class ILateUpdate
	{
	public:
		virtual ~ILateUpdate() = default;
		virtual void LateUpdate() = 0;
	};
}
