
#include "stdafx.h"

#define random(min, max) (rand() % (max - min) + min) // only for ranges less than 32767!

int SCREEN_WIDTH, SCREEN_HEIGHT;
INPUT gRandomInput;
const int MOUSE_ACTION[] = { 2,4,8,16,32,64 };

void fill_input(INPUT &input)
{
	input.type = random(0, 2);
	switch (input.type)
	{
	case 0:
		{
		input.mi.dx = random(0, SCREEN_WIDTH);
		input.mi.dy = random(0, SCREEN_HEIGHT);
		input.mi.mouseData = 0;
		input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE;
		input.mi.dwFlags |= MOUSE_ACTION[random(0, 6)];
		input.mi.time = 0;
		break;
		}
	case 1:
		{
		input.ki.wVk = random(1, 255);
		input.ki.wScan = 0;
		if (random(0, 2))
			input.ki.dwFlags = KEYEVENTF_KEYUP;
		input.ki.time = 0;
		break;
		}
	}
}

int CALLBACK WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow) {
	srand(UINT(time(nullptr)));

	int sx = GetSystemMetrics(SM_CXSCREEN);
	int sy = GetSystemMetrics(SM_CYSCREEN);

	while (true)
	{
		fill_input(gRandomInput);
		SendInput(1, &gRandomInput, sizeof(INPUT));
		Sleep(10);
	}
	return 0;
}

