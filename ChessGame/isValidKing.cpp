#include "stdafx.h"
#include "ValidMove.h"

bool ValidMove::isValidKing(int oldSquare, int newSquare) {
	if (oldSquare + 1 == newSquare || oldSquare - 1 == newSquare) return true;
	if (oldSquare + 7 == newSquare || oldSquare - 7 == newSquare) return true;
	if (oldSquare + 8 == newSquare || oldSquare - 8 == newSquare) return true;
	if (oldSquare + 9 == newSquare || oldSquare - 9 == newSquare) return true;

	//Castle attempt
	if (oldSquare + 2 == newSquare || oldSquare - 2 == newSquare) return true;

	return false;
}