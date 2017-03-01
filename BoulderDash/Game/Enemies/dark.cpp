#include "dark.h"
#include <cstdlib>

namespace BoulderDash
{
	namespace Enemies
	{
		PointsPair Dark::update(Level* level, int timeSpan)
		{
			m_time -= timeSpan;

			if (m_time > 0)
				return PointsPair(getLocation(), getLocation());

			m_time = m_totalTime;
			Engine::Point<int> location = getLocation();

			switch (findDirectionToHuman(level))
			{
			case TOP:
				return PointsPair(location, Engine::Point<int>(location.x, location.y - 1));

			case RIGHT:
				return PointsPair(location, Engine::Point<int>(location.x + 1, location.y));

			case BOTTOM:
				return PointsPair(location, Engine::Point<int>(location.x, location.y + 1));

			case LEFT:
				return PointsPair(location, Engine::Point<int>(location.x - 1, location.y));
			}

			return PointsPair(getLocation(), getLocation());
		}

		int Dark::m_totalTime = 1000;
	}
}