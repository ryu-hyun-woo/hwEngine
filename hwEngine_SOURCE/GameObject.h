#pragma once
#include "CommonInclude.h"
#include "Input.h"

namespace hw
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Update();
		void Render(HDC hdc);
		void LateUpdate();

		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		}

		void SetSize(float width, float height)
		{
			mWidth = width;
			mHeight = height;
		}

		void SetSpeed(float speed)
		{
			mSpeed = speed;
		}

		void SetColor(COLORREF color)
		{
			mColor = color;
		}

		void SetActive(bool active)
		{
			mActive = active;
		}

		bool GetActive() const { return mActive; }
		float GetPositionX() const { return mX; }
		float GetPositionY() const { return mY; }
		float GetWidth() const { return mWidth; }
		float GetHeight() const { return mHeight; }

	protected:
		float mX;
		float mY;
		float mWidth;
		float mHeight;
		float mSpeed;
		COLORREF mColor;
		bool mActive;
	};
}