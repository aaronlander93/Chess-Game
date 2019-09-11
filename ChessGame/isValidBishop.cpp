#include "stdafx.h"
#include "ValidMove.h"

bool ValidMove::isValidBishop(int oldSquare, int newSquare, map<int, int> squareToPiece)
{
	bool collision = false;
	int pieceType = 4;

	for (int i = oldSquare + 9; i <= 64; i += 9) {
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

	for (int i = oldSquare - 9; i >= 0; i -= 9) {
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

	for (int i = oldSquare + 7; i <= 64; i += 7) {
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

	for (int i = oldSquare - 7; i >= 0; i -= 7) {
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

	return false;
}