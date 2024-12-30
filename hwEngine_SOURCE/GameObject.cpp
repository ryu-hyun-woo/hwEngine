#include "GameObject.h"
#include "GameObject.h"
#include "GameObject.h"

namespace hw
{ 
	int sObjectId = 0;

	GameObject::GameObject()
		: mSpeed(0)
		, mColor(RGB(0,0,0))
		, mActive(false)
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

		Rectangle(hdc, (int)mPosition.mX, 
						(int)mPosition.mY, 
						(int)(mPosition.mX + mSize.mX), 
						(int)(mPosition.mY + mSize.mY));

		SelectObject(hdc, oldBrush);
		SelectObject(hdc, oldPen);

		DeleteObject(blueBrush);
		DeleteObject(redPen);
	}
}
