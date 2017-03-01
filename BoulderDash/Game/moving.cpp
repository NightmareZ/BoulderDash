#include "moving.h"

namespace BoulderDash
{
	bool Moving::contains(int x, int y)
	{
		return m_oldCell.x == x && m_oldCell.y == y ||
			   m_targetCell.x == x && m_targetCell.y == y;
	}

	void Moving::update(int timeSpan)
	{
		if (m_msecs > 0)
			m_msecs -= timeSpan;
	}

	bool Moving::isDone()
	{
		return m_msecs <= 0;
	}
}