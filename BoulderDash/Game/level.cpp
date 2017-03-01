#include "level.h"
#include <cstdio>

namespace BoulderDash
{
	Level::Level(const char* filename)
	{
		FILE* file = fopen(filename, "r");
		fscanf(file, "%d %d", &m_width, &m_height);
		fscanf(file, "%d", &m_time);
		m_map = new CellType[m_width * m_height];
		char* buf = new char[m_width + 1];

		for (int j = 0; j < m_height; ++j)
		{
			fscanf(file, "%s", buf);

			for (int i = 0; i < m_width; ++i)
			{
				char curr = buf[i];
				CellType cell = UNDEFINED;
				switch (curr)
				{
				case '0':
					cell = GROUND;
					break;
				case '1':
					cell = BOX;
					break;
				case '2':
					cell = CRYSTAL;
					break;
				case '3':
					cell = HUMAN;
					break;
				case '4':
					cell = BOULDER;
					break;
				case '5':
					cell = DOOR;
					break;
				case '6':
					cell = ENEMY0;
					break;
				case '7':
					cell = ENEMY1;
					break;
				case '8':
					cell = HEART;
					break;
				case '9':
					cell = CLOCK;
					break;
				case 'x':
					cell = NONE;
					break;
				default:
					cell = GROUND;
				}
				m_map[j * m_width + i] = cell;
			}
		}

		fclose(file);
	}

	Level::~Level()
	{
		delete m_map;
	}

	CellType Level::get(int x, int y) const
	{
		return m_map[y * m_width + x];
	}

	void Level::set(int x, int y, CellType value)
	{
		m_map[y * m_width + x] = value;
	}

	int Level::minCellsOnScreen = 12;

	Engine::Point<int> Level::findHumanPosition()
	{
		for (int j = 0; j < m_height; ++j)
			for (int i = 0; i < m_width; ++i)
				if (get(i, j) == HUMAN)
					return Engine::Point<int>(i, j);
	}

	std::vector<Engine::Point<int>> Level::findEmenies()
	{
		std::vector<Engine::Point<int>> enemies;

		for (int j = 0; j < m_height; ++j)
			for (int i = 0; i < m_width; ++i)
			{
				CellType cell = get(i, i);
				if (cell == ENEMY0 || cell == ENEMY1)
					enemies.push_back(Engine::Point<int>(i, j));
			}

		return enemies;
	}

	int Level::getCrystalsCount() const
	{
		int count = 0;

		for (int j = 0; j < m_height; ++j)
			for (int i = 0; i < m_width; ++i)
				if ((get(i, j) & OBJECTS) == CRYSTAL)
					++count;

		return count;
	}
}