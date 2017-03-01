#ifndef DARK_H
#define DARK_H

#include "..\enemy.h"

namespace BoulderDash
{
	namespace Enemies
	{
		class Dark: public Enemy
		{
		private:
			int m_time;
			static int m_totalTime;
		public:
			Dark(Engine::Point<int> pt)
				: Enemy(pt), m_time(m_totalTime)
			{ }

			virtual PointsPair update(Level* level, int timeSpan);
		};
	}
}

#endif
