#include "stdafx.h"
#include "ValidMove.h"

bool ValidMove::isValidWhitePawn(int oldSquare, int newSquare, map<int, int> squareToPiece) {
	if (oldSquare < 16 && oldSquare > 7) {
		if (oldSquare + 8 == newSquare) {
			return true;
		}
		else if (oldSquare + 16 == newSquare && !isPieceOnSquare(squareToPiece, newSquare - 8)) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (oldSquare + 8 == newSquare) {
		return true;
	}
	else {
		return false;
	}
}