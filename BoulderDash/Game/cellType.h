#ifndef CELLTYPE_H
#define CELLTYPE_H

namespace BoulderDash
{
	enum CellType
	{
		NONE = 0,
		GROUND = 1,
		BOX = 2,
		HUMAN = 0x100,
		CRYSTAL = 0x200,
		BOULDER = 0x300,
		DOOR = 0x400,
		ENEMY0 = 0x500,
		ENEMY1 = 0x600,
		HEART = 0x700,
		CLOCK = 0x800,

		GROUNDS = 0xff,
		OBJECTS = 0xff00,
		UNDEFINED = 0xffffffff
	};

	bool canMoveToCell(CellType cell);
	bool canMoveEnemyToCell(CellType cell);
}

#endif