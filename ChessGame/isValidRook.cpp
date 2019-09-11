#include "stdafx.h"
#include "ValidMove.h"

bool ValidMove::isValidRook(int oldSquare, int newSquare, int pieceType, map<int, int> squareToPiece) {
	bool collision = false;

	for (int i = oldSquare + 8; i <= 64; i += 8) {
		if (isPieceOnSquare(squareToPiece, i) && !collision) {
			if (i == newSquare && isAttemptedTake(squareToPiece, pieceType, newSquare)
				&& !collision) {
				return true;
			}
			collision = true;
		}

		if (i == newSquare && !collision) {
			return true;
		}
	}

	collision = false;

	for (int i = oldSquare - 8; i >= 0; i -= 8) {
		if (isPieceOnSquare(squareToPiece, i) && !collision) {
			collision = true;
		}
		if (i == newSquare && !collision) {
			return true;
		}
	}

	collision = false;

	for (int i = oldSquare + 1; i <= 64; i++) {
		if (isPieceOnSquare(squareToPiece, i) && !collision) {
			collision = true;
		}
		if (i % 8 == 0) {
			break;
		}
		else if (i == newSquare && !collision) {
			return true;
		}
	}

	collision = false;

	for (int i = oldSquare - 1; i >= 0; i--) {
		if (isPieceOnSquare(squareToPiece, i) && !collision) {
			collision = true;
		}

		if (i % 8 == 0) {
			if (i == newSquare && !collision) {
				return true;
			}
			else {
				break;
			}
		}
		if (i == newSquare && !collision) {
			return true;
		}
	}

	return false;
}