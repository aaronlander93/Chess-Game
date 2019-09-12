#include "stdafx.h"
#include "ValidMove.h"

bool ValidMove::isValidBishop(int oldSquare, int newSquare, map<int, int> squareToPiece)
{
	bool collision = false;

	for (int i = oldSquare + 9; i <= 64; i += 9) {
		if (i == newSquare && !collision) {
			return true;
		}
		else if (isPieceOnSquare(squareToPiece, i) && !collision) {
			collision = true;
		}
	}
	collision = false;
	for (int i = oldSquare - 9; i >= 0; i -= 9) {
		if (i == newSquare && !collision) {
			return true;
		}
		else if (isPieceOnSquare(squareToPiece, i) && !collision) {
			collision = true;
		}
	}
	collision = false;

	for (int i = oldSquare + 7; i <= 64; i += 7) {
		if (i == newSquare && !collision) {
			return true;
		}
		else if (isPieceOnSquare(squareToPiece, i) && !collision) {
			collision = true;
		}
	}

	collision = false;

	for (int i = oldSquare - 7; i >= 0; i -= 7) {
		if (i == newSquare && !collision) {
			return true;
		}
		else if (isPieceOnSquare(squareToPiece, i) && !collision) {
			collision = true;
		}
	}
	return false;
}