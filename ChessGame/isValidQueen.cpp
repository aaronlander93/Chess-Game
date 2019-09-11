#include "stdafx.h"
#include "ValidMove.h"

bool ValidMove::isValidQueen(int oldSquare, int newSquare, int pieceType, map<int, int> squareToPiece) {
	if (isValidRook(oldSquare, newSquare, pieceType, squareToPiece) || isValidBishop(oldSquare, newSquare, squareToPiece)) {
		return true;
	}
	else {
		return false;
	}
}