#pragma once
#include "World.h"
#include "Snake.h"
#include <Windows.h>
#include <chrono>

class Application
{
public:
	Application(int l_windowSizeX, int l_windowSizeY);
	~Application() = default;

	void handleInput();
	void update();
	void Render();

	bool isDone();

private:
	int m_windowSizeX;
	int m_windowSizeY;

	World m_world;
	Snake m_snake;

	//Time calculations
	std::chrono::system_clock::time_point t;
	float fElapsed;

	bool m_done;
};

