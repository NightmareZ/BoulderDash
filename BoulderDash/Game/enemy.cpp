#include "enemy.h"
#include "cellType.h"

namespace BoulderDash
{
	Direction Enemy::findDirectionToHuman(Level* level)
	{
		int w = level->getWidth();
		int h = level->getHeight();

		Engine::Point<int> target = level->findHumanPosition();
		Engine::Point<int> start = getLocation();

		int* arr = new int[w * h];
		for (int j = 0; j < h; ++j)
			for (int i = 0; i < w; ++i)
			{
				CellType cell = level->get(i, j);
				arr[j * w + i] = (cell == NONE || cell == HUMAN) ? 0 : -1;
			}
		arr[start.y * w + start.x] = 1;

		bool finded = false;
		int steps = 1;
		int currentStep = arr[start.y * w + start.x];
		while (steps)
		{
			steps = 0;
			done:

			if (!finded)
			{
				int nextStep = currentStep + 1;

				for (int j = 0; j < h; ++j)
					for (int i = 0; i < w; ++i)
						if (arr[j * w + i] == currentStep)
						{
							if (j > 0 && !arr[(j - 1) * w + i])
							{
								arr[(j - 1) * w + i] = nextStep;
								++steps;

								if (i == target.x && j - 1 == target.y)
								{
									finded = true;
									goto done;
								}
							}

							if (i < w - 1 && !arr[j * w + i + 1])
							{
								arr[j * w + i + 1] = nextStep;
								++steps;

								if (i + 1 == target.x && j == target.y)
								{
									finded = true;
									goto done;
								}
							}

							if (j < h - 1 && !arr[(j + 1) * w + i])
							{
								arr[(j + 1) * w + i] = nextStep;
								++steps;

								if (i == target.x && j + 1 == target.y)
								{
									finded = true;
									goto done;
								}
							}

							if (i > 0 && !arr[j * w + i - 1])
							{
								arr[j * w + i - 1] = nextStep;
								++steps;

								if (i - 1 == target.x && j == target.y)
								{
									finded = true;
									goto done;
								}
							}
						}

				currentStep = nextStep;
			}
			else
				break;
		}

		Direction direction;

		if (!finded)
		{
			direction = static_cast<Direction>(rand() % 4);
		}
		else
		{
			direction = BOTTOM;
			int currentStep = arr[target.y * w + target.x];

			while (!(target.x == start.x && target.y == start.y))
			{
				int nextStep = currentStep - 1;

				if (target.y > 0 && arr[(target.y - 1) * w + target.x] == nextStep)
				{
					direction = BOTTOM;
					target = Engine::Point<int>(target.x, target.y - 1);
				}
				else if (target.x < w - 1 && arr[target.y * w + target.x + 1] == nextStep)
				{
					direction = LEFT;
					target = Engine::Point<int>(target.x + 1, target.y);
				}
				else if (target.y < h - 1 && arr[(target.y + 1) * w + target.x] == nextStep)
				{
					direction = TOP;
					target = Engine::Point<int>(target.x, target.y + 1);
				}
				else if (target.x > 0 && arr[target.y * w + target.x - 1] == nextStep)
				{
					direction = RIGHT;
					target = Engine::Point<int>(target.x - 1, target.y);
				}

				currentStep = nextStep;
			}
		}

		delete arr;
		return direction;
	}

	void Enemy::setLocation(int x, int y)
	{
		if (x > m_pt.x)
			m_direction = RIGHT;
		else if (x < m_pt.x)
			m_direction = LEFT;
		else if (y > m_pt.y)
			m_direction = BOTTOM;
		else if (y < m_pt.y)
			m_direction = TOP;
		else
			m_direction = BOTTOM;

		m_pt = Engine::Point<int>(x, y);
	}
}