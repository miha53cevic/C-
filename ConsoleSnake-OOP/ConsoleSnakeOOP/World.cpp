#include "World.h"

World::World(int l_windowSizeX, int l_windowSizeY)
{
	m_windowSizeX = l_windowSizeX;
	m_windowSizeY = l_windowSizeY;

	//Stvaranje Pointer to pointer 2D polja
	map = new char*[l_windowSizeY];
	for (int i = 0; i < l_windowSizeY; i++)
		map[i] = new char[l_windowSizeX];

	//Popunjavanje polja sa ' '
	for (int y = 0; y < m_windowSizeY; y++)
		for (int x = 0; x < m_windowSizeX; x++)
			map[y][x] = ' ';


	//First time setup
	spawnApple();
	m_Score = 0;
}

void World::update(Snake* snake)
{
	std::pair<int, int> snakeHead = snake->getSnake()->front();

	if (snakeHead.first == m_appleX && snakeHead.second == m_appleY)
	{
		snake->growSnake();
		spawnApple();

		//Add Score
		m_Score++;
	}
}

void World::draw()
{
	printf("==============================================\n");
	printf("| Console Snake by miha53cevic	 Score: %d    |\n", m_Score);
	printf("==============================================\n");

	printf("\n");

	for (int y = 0; y < m_windowSizeY; y++)
	{
		for (int x = 0; x < m_windowSizeX; x++)
		{
			switch (map[y][x])
			{
			case 'O':
				printf("O");
				break;
			case 'o':
				printf("o");
				break;
			case ' ':
				printf(".");
				break;
			case 'x':
				printf("x");
				break;
			}
		}
		printf("\n");
	}
}

void World::spawnApple()
{
	m_appleX = rand() % m_windowSizeX;
	m_appleY = rand() % m_windowSizeY;

	map[m_appleY][m_appleX] = 'x';
}

char** World::getMap() { return map; }

