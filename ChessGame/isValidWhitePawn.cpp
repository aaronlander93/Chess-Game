#include "stdafx.h"
#include "ValidMove.h"

bool ValidMove::isValidWhitePawn(int oldSquare, int newSquare, map<int, int> squareToPiece) {
	if (oldSquare < 16 && oldSquare > 7) {
		if (oldSquare + 8 == newSquare || oldSquare + 9 == newSquare) {
			return true;
		}
		else if (oldSquare + 16 == newSquare && !isPieceOnSquare(squareToPiece, newSquare - 8) 
			&& !isPieceOnSquare(squareToPiece, newSquare)) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (oldSquare + 8 == newSquare && !isPieceOnSquare(squareToPiece, newSquare)) {
		return true;
	}
	else if (oldSquare + 7 == newSquare) {
		for (int i = 0; i < 63; i += 8) {
			if (oldSquare == i) {
				return false;
			}
			else {
				return true;
			}
		}
	}
	else {
		return false;
	}
}