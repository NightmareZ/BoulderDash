#include "cellType.h"

namespace BoulderDash
{
	bool canMoveToCell(CellType cell)
	{
		return cell == NONE ||
			   cell == GROUND ||
			   cell == CRYSTAL ||
			   cell == DOOR ||
			   cell == HEART ||
			   cell == CLOCK ||
			   cell == ENEMY0 ||
			   cell == ENEMY1;
	}

	bool canMoveEnemyToCell(CellType cell)
	{
		return cell == NONE || cell == HUMAN;
	}
}