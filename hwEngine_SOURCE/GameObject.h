#pragma once
#include "CommonInclude.h"
#include "IUpdate.h"
#include "IRender.h"
#include "ILateUpdate.h"

namespace hw 
{
	class GameObject : public IRender 
	{
	public:
		GameObject();
		~GameObject() = default;

		void Render(HDC hdc) override;

		void SetPosition(const Vector2& position) { mPosition = position; }
		void SetSize(const Vector2& size) { mSize = size; }
		void SetSpeed(float speed) { mSpeed = speed; }
		void SetColor(COLORREF color) { mColor = color; }
		void SetActive(bool active) { mActive = active; }

		bool GetActive() const { return mActive; }
		const Vector2& GetPosition() const { return mPosition; }
		const Vector2& GetSize() const { return mSize; }

	protected:
		Vector2 mPosition;
		Vector2 mSize;

		float mSpeed;
		COLORREF mColor;
		bool mActive;
	};
}