#ifndef MOVING_H
#define MOVING_H

#include <utility>
#include "level.h"
#include "..\Engine\point.h"

namespace BoulderDash
{
	class Moving
	{
	private:
		Engine::Point<int> m_oldCell, m_targetCell;
		int m_totalMsecs;
		int m_msecs;
	public:
		Moving(Engine::Point<int> oldCell, Engine::Point<int> targetCell, int msecs)
			: m_oldCell(oldCell), m_targetCell(targetCell), m_msecs(msecs), m_totalMsecs(msecs)
		{ }

		bool contains(int x, int y);
		void update(int timeSpan);
		bool isDone();
		float donePercents() { return 1.f - (m_totalMsecs - m_msecs) / static_cast<float>(m_totalMsecs); }
		Engine::Point<int> old() { return m_oldCell; }
		Engine::Point<int> target() { return m_targetCell; }
	};
}

#endif