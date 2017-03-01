#ifndef GHOST_H
#define GHOST_H

#include "..\enemy.h"

namespace BoulderDash
{
	namespace Enemies
	{
		class Ghost: public Enemy
		{
		private:
			int m_time;
			static int m_totalTime;
		public:
			Ghost(Engine::Point<int> pt)
				: Enemy(pt), m_time(m_totalTime)
			{ }

			virtual PointsPair update(Level* level, int timeSpan);
		};
	}
}

#endif
