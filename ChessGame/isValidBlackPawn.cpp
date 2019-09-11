#include "stdafx.h"
#include "ValidMove.h"

bool ValidMove::isValidBlackPawn(int oldSquare, int newSquare, map<int, int> squareToPiece) {
	if (oldSquare < 56 && oldSquare > 47) {
		if (oldSquare - 8 == newSquare) {
			return true;
		}
		else if (oldSquare - 16 == newSquare && !isPieceOnSquare(squareToPiece, newSquare + 8)) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (oldSquare - 8 == newSquare) {
		return true;
	}
	else {
		return false;
	}
}