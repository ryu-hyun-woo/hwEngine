#include "Input.h"

namespace hw
{
	char keyCode[] = {
		'Q', 'W', 'E', 'R', 'A', 'S', 'D', 'F', '1', '2', '3',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP, VK_SPACE
	};

	Input::Key Input::mKeys[255]{};
	
	Input::Input()
	{
	}

	Input::~Input()
	{
	}

	void Input::Initialize()
	{
		CreateKeys();
	}

	void Input::Update()
	{
		for (auto& item : mKeys)
		{
			if (GetAsyncKeyState(item.key) & 0x8000)
			{
				if (item.state == eKeyState::Down || item.state == eKeyState::Pressed)
				{
					item.state = eKeyState::Pressed;
				}
				else
				{
					item.state = eKeyState::Down;
				}
			}
			else
			{
				if (item.state == eKeyState::Down|| item.state == eKeyState::Pressed)
				{
					item.state = eKeyState::Up;
				}
				else
				{
					item.state = eKeyState::None;
				}
			}
		}
	}

	void Input::CreateKeys()
	{
		for (auto& code : keyCode)
		{
			mKeys[code].key = code;
			mKeys[code].state = eKeyState::None;
		}
	}
}
