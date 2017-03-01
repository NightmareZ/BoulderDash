#ifndef ENEMY_H
#define ENEMY_H

#include "..\Engine\point.h"
#include <utility>
#include "direction.h"
#include "level.h"

namespace BoulderDash
{
	typedef std::pair<Engine::Point<int>, Engine::Point<int>> PointsPair;

	class Enemy
	{
	private:
		Engine::Point<int> m_pt;
		Direction m_direction;
	public:
		Enemy(Engine::Point<int> pt)
			: m_pt(pt), m_direction(BOTTOM)
		{ }

		virtual PointsPair update(Level* level, int timeSpan) { return PointsPair(m_pt, m_pt); }
		Direction findDirectionToHuman(Level* level);
		Engine::Point<int> getLocation() const { return m_pt; }
		void setLocation(int x, int y);
		Direction getDirection() const { return m_direction; }
	};
}

#endif