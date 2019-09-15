#include "stdafx.h"
#include "ValidMove.h"

bool ValidMove::isValidBlackPawn(int oldSquare, int newSquare, map<int, int> squareToPiece) {
	if (oldSquare < 56 && oldSquare > 47) {
		if (oldSquare - 16 == newSquare && !isPieceOnSquare(squareToPiece, oldSquare - 8) 
			&& !isPieceOnSquare(squareToPiece, newSquare)) {
			return true;
		}
	}
	if (oldSquare - 8 == newSquare && !isPieceOnSquare(squareToPiece, newSquare)) {
		return true;
	}
	else if (oldSquare - 7 == newSquare || oldSquare - 9 == newSquare) {
		int piece = -1;
		if (isAttemptedTake(squareToPiece, piece, newSquare)) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}