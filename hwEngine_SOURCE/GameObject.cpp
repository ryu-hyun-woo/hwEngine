#include "GameObject.h"
#include "GameObject.h"

namespace hw
{ 
	int sObjectId = 0;

	GameObject::GameObject()
		: mX(0)
		, mY(0)
		, mWidth(0)
		, mHeight(0)
		, mSpeed(0)
		, mColor(RGB(0,0,0))
		, mActive(true)
	{
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{
	}

	void GameObject::LateUpdate()
	{
	}

	void GameObject::Render(HDC hdc)
	{
		if (!mActive)
		{
			return;
		}

		HBRUSH blueBrush = CreateSolidBrush(mColor);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, mColor);
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

		Rectangle(hdc, (int)mX, (int)mY, (int)(mX + mWidth), (int)(mY + mHeight));

		SelectObject(hdc, oldBrush);
		SelectObject(hdc, oldPen);

		DeleteObject(blueBrush);
		DeleteObject(redPen);
	}
}
