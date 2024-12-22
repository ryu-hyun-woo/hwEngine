#pragma once
#include "CommonInclude.h"

namespace hw
{

	extern char keyCode[];

	enum eKeyState
	{
		Down,
		Pressed,
		Up,
		None	
	};

	class Input
	{
	public:
		Input();
		~Input();

		void Initialize();
		void Update();
		void CreateKeys();

		static bool IsKeyDown(char code) { return  mKeys[code].state == eKeyState::Down; }
		static bool IsKeyUp(char code) { return  mKeys[code].state == eKeyState::Up; }
		static bool IsKeyPressed(char code) { return  mKeys[code].state == eKeyState::Pressed; }

	private:
		struct Key
		{
			char key;
			eKeyState state;
		};

		static Key mKeys[255];
	};
}