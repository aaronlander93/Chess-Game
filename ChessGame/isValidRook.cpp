#include "stdafx.h"
#include "ValidMove.h"

bool ValidMove::isValidRook(int oldSquare, int newSquare, int pieceType, map<int, int> squareToPiece) {
	bool collision = false;

	for (int i = oldSquare + 8; i <= 64; i += 8) {
		if (i == newSquare && !collision) {
			return true;
		}
		if (isPieceOnSquare(squareToPiece, i) && !collision) {
			collision = true;
		}
	}

	collision = false;

	for (int i = oldSquare - 8; i >= 0; i -= 8) {
		if (i == newSquare && !collision) {
			return true;
		}
		if (isPieceOnSquare(squareToPiece, i) && !collision) {
			collision = true;
		}
	}

	collision = false;

	for (int i = oldSquare + 1; i <= 64; i++) {
		if (i == newSquare && !collision) {
			return true;
		}
		if (isPieceOnSquare(squareToPiece, i) && !collision) {
			collision = true;
		}
		if (i % 8 == 0) {
			break;
		}
	}

	collision = false;

	for (int i = oldSquare - 1; i >= 0; i--) {
		if (i == newSquare && !collision) {
			return true;
		}
		if (isPieceOnSquare(squareToPiece, i) && !collision) {
			collision = true;
		}
		if (i % 8 == 0) {
			break;
		}
	}

	return false;
}