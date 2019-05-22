#pragma once
#include <string>
#include <iostream>
#include "Snake.h"

class World
{
public:
	World(int l_windowSizeX, int l_windowSizeY);
	~World() = default;

	void update(Snake* snake);
	void draw();

	char** getMap();

private:
	int m_windowSizeX;
	int m_windowSizeY;

	int m_appleX;
	int m_appleY;

	char **map;

	void spawnApple();

	unsigned int m_Score;
};

