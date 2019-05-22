#include "Snake.h"

Snake::Snake(int l_windowSizeX, int l_windowSizeY)
{
	m_windowSizeX = l_windowSizeX;
	m_windowSizeY = l_windowSizeY;

	m_snakeSize = 2;
	m_dir = Direction::LEFT;

	for (int i = 0; i < m_snakeSize; i++)
		m_snake.push_back({ l_windowSizeX / 2 + i, l_windowSizeY / 2 });
}

void Snake::update(char** map)
{
	//Move snake
	if (m_dir == Direction::UP) m_snake.push_front({ m_snake.front().first, m_snake.front().second - 1 });
	else if (m_dir == Direction::DOWN) m_snake.push_front({ m_snake.front().first, m_snake.front().second + 1 });
	else if (m_dir == Direction::LEFT) m_snake.push_front({ m_snake.front().first - 1, m_snake.front().second });
	else if (m_dir == Direction::RIGHT) m_snake.push_front({ m_snake.front().first + 1, m_snake.front().second });

	//Check if outside of screen
	if (m_snake.front().first < 0) m_snake.front().first = m_windowSizeX - 1;
	else if (m_snake.front().first >= m_windowSizeX) m_snake.front().first = 0;
	else if (m_snake.front().second < 0) m_snake.front().second = m_windowSizeY - 1;
	else if (m_snake.front().second >= m_windowSizeY) m_snake.front().second = 0;

	map[m_snake.back().second][m_snake.back().first] = ' ';
	m_snake.pop_back();
}

void Snake::draw(char** map)
{
	for (auto &i : m_snake)
		map[i.second][i.first] = 'o';

	map[m_snake.front().second][m_snake.front().first] = 'O';
}

void Snake::input()
{
	if (_kbhit())
	{
		char input = _getch();

		if (input == 'a' && m_dir != Direction::RIGHT) m_dir = Direction::LEFT;
		else if (input == 'd' && m_dir != Direction::LEFT) m_dir = Direction::RIGHT;
		else if (input == 'w' && m_dir != Direction::DOWN) m_dir = Direction::UP;
		else if (input == 's' && m_dir != Direction::UP) m_dir = Direction::DOWN;
	}
}

void Snake::growSnake()
{
	m_snake.push_back({ m_snake.back() });

	m_snakeSize++;
}

bool Snake::Collision(char** map)
{
	if (map[m_snake.front().second][m_snake.front().first] == 'o')
		return true;
	else return false;
}

std::list < std::pair<int, int> >* Snake::getSnake() { return &m_snake; }
