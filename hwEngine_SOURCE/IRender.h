#pragma once

namespace hw
{
	class IRender
	{
	public:
		virtual ~IRender() = default;
		virtual void Render(HDC hdc) = 0;
	};
}