#pragma once

namespace hw
{
	struct Vector2
	{
		Vector2(float x = 0, float y = 0) 
			: mX(x)
			, mY(y)
		{
		}

		Vector2 operator-(const Vector2& other)
		{
			return { mX - other.mX, mY - other.mY };
		}

		Vector2 operator+(const Vector2& other)
		{
			return { mX + other.mX, mY + other.mY };
		}

		Vector2 operator/(const Vector2& other)
		{
			if (other.mX != 0 && other.mY != 0)
			{
				return { mX / other.mX, mY / other.mY };
			}
		}

		float mX;
		float mY;
	};
}