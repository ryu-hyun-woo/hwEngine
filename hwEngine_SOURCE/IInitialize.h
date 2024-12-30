#pragma once

namespace hw
{
	class IInitialize
	{
	public:
		virtual ~IInitialize() = default;
		virtual void Initialize() = 0;
	};
}