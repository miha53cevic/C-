#include "Application.h"

Application::Application(int l_windowSizeX, int l_windowSizeY)
	: m_world(l_windowSizeX, l_windowSizeY)
	, m_snake(l_windowSizeX, l_windowSizeY)
{
	m_done = false;

	m_windowSizeX = l_windowSizeX;
	m_windowSizeY = l_windowSizeY;
}

void Application::handleInput()
{
	m_snake.input();
}

void Application::update()
{
	//DELTA TIME
	float frameTime = 1.f / 4.f;
	
	auto elapsed = std::chrono::system_clock::now() - t;

	fElapsed += std::chrono::duration<float>(elapsed).count();

	if (fElapsed >= frameTime)
	{
		m_snake.update(m_world.getMap());

		fElapsed -= fElapsed;
	}

	m_world.update(&m_snake);

	t = std::chrono::system_clock::now();

	if (m_snake.Collision(m_world.getMap()))
	{
		m_done = true;
		system("pause");
	}
}

void Application::Render()
{
	//REMOVES CURSOR
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

	//REFRESHES SCREEN WITHOUTH FLICKER
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD pos;

	pos.X = 0;
	pos.Y = 0;
	SetConsoleCursorPosition(hConsole, pos);

	//Draw Calls
	m_world.draw();
	m_snake.draw(m_world.getMap());
}

bool Application::isDone() { return m_done; }

