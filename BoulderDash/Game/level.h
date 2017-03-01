#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "..\Engine\point.h"
#include "cellType.h"

namespace BoulderDash
{
	class Level
	{
	private:
		int m_width, m_height;
		int m_time;
		CellType* m_map;
	public:
		Level(const char* filename);
		~Level();

		CellType get(int x, int y) const;
		CellType get(Engine::Point<int> pt) const { return get(pt.x, pt.y); }

		void set(int x, int y, CellType value);
		void set(Engine::Point<int> pt, CellType value) { set(pt.x, pt.y, value); }

		int getWidth() const { return m_width; }
		int getHeight() const { return m_height; }

		int getTime() const { return m_time; }
		static int minCellsOnScreen;
		Engine::Point<int> findHumanPosition();
		std::vector<Engine::Point<int>> findEmenies();
		int getCrystalsCount() const;
	};
}

#endif