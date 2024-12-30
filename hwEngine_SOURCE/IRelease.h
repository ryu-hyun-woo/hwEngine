#pragma once

namespace hw
{
	class IRelease
	{
	public:
		virtual ~IRelease() = default;
		virtual void Release() = 0;
	private:
	};
}