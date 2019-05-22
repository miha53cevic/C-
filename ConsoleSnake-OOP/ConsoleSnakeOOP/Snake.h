#pragma once
#include <conio.h>
#include <list>

enum Direction
{
	UP, DOWN, LEFT, RIGHT
};

class Snake
{
public:
	Snake(int l_windowSizeX, int l_windowSizeY);
	~Snake() = default;

	void draw(char** map);
	void update(char** map);
	void input();

	std::list < std::pair<int, int> >* getSnake();

	bool Collision(char** map);
	void growSnake();

private:
	int m_windowSizeX;
	int m_windowSizeY;

	std::list < std::pair<int, int> > m_snake;

	int m_snakeSize;

	Direction m_dir;
};

