#include "stdafx.h"
#include "CheckMate.h"

using namespace std;

bool CheckMate::isCheck(map<int, int> squareToPiece, bool whiteMove) {
	bool check = false;
	int square;

	if (whiteMove) {
		for (int i = 0; i < 63; i++) {
			if (squareToPiece[i] == 6) {
				square = i;
			}
		}
		check = isCheckWhite(squareToPiece, square);
	}
	else {
		for (int i = 0; i < 63; i++) {
			if (squareToPiece[i] == -6) {
				square = i;
			}
		}
		check = isCheckBlack(squareToPiece, square);
	}

	return check;
}
bool CheckMate::isCheck(map<int, int> squareToPiece, bool whiteMove, 
	int oldSquare, int newSquare, int pieceType) {

	//Assume previous move is valid and make change
	squareToPiece[oldSquare] = 0;
	squareToPiece[newSquare] = pieceType;

	bool check = false;
	int square;
	if (whiteMove) {
		for (int i = 0; i < 63; i++) {
			if (squareToPiece[i] == 6) {
				square = i;
			}
		}
		check = isCheckWhite(squareToPiece, square);
	}
	else {
		for (int i = 0; i < 63; i++) {
			if (squareToPiece[i] == -6) {
				square = i;
			}
		}
		check = isCheckBlack(squareToPiece, square);
	}

	return check;
}

bool CheckMate::isCheckWhite(map<int, int> squareToPiece, int square) {
	//Pawn attack
	if (squareToPiece[square + 7] == -1 || squareToPiece[square + 9] == -1) {
		return true;
	}
	//Rook attack
	for (int i = square + 8; i <= 64; i += 8) {
		if (squareToPiece[i] == -2 || squareToPiece[i] == -5) {
			return true;
		}
		else if (squareToPiece[i] > 0) {
			break;
		}
	}

	for (int i = square - 8; i >= 0; i -= 8) {
		if (squareToPiece[i] == -2 || squareToPiece[i] == -5) {
			return true;
		}
		else if (squareToPiece[i] > 0) {
			break;
		}
	}

	for (int i = square + 1; i <= 64; i++) {
		if (i % 8 == 0) {
			break;
		}
		else if (squareToPiece[i] == -2 || squareToPiece[i] == -5) {
			return true;
		}
		else if (squareToPiece[i] > 0) {
			break;
		}
	}

	for (int i = square - 1; i >= 0; i--) {
		if (squareToPiece[i] == -2 || squareToPiece[i] == -5) {
			return true;
		}
		else if (squareToPiece[i] > 0) {
			break;
		}
		else if (i % 8 == 0) {
			break;
		}
	}
	//Knight attack
	if (squareToPiece[square + 6] == -3 || squareToPiece[square - 6] == -3) return true;
	if (squareToPiece[square + 10] == -3 || squareToPiece[square - 10] == -3) return true;
	if (squareToPiece[square + 15] == -3 || squareToPiece[square - 15] == -3) return true;
	if (squareToPiece[square + 17] == -3 || squareToPiece[square - 17] == -3) return true;
	
	//Bishop attack
	for (int i = square + 9; i <= 64; i += 9) {
		if (squareToPiece[i] == -4 || squareToPiece[i] == -5) {
			return true;
		}
		else if (squareToPiece[i] != 0) {
			break;
		}
		if ((i+1) % 8 == 0) {
			break;
		}
	}

	for (int i = square - 9; i >= 0; i -= 9) {
		if (squareToPiece[i] == -4 || squareToPiece[i] == -5) {
			return true;
		}
		else if (squareToPiece[i] != 0) {
			break;
		}
		if (i % 8 == 0) {
			break;
		}
	}

	for (int i = square + 7; i <= 64; i += 7) {
		if (squareToPiece[i] == -4 || squareToPiece[i] == -5) {
			return true;
		}
		else if (squareToPiece[i] != 0) {
			break;
		}
		if (i % 8 == 0) {
			break;
		}
	}

	for (int i = square - 7; i >= 0; i -= 7) {
		if (squareToPiece[i] == -4 || squareToPiece[i] == -5) {
			return true;
		}
		else if (squareToPiece[i] != 0) {
			break;
		}
		if ((i+1) % 8 == 0) {
			break;
		}
	}

	//King attack
	if (squareToPiece[square - 1] == -6) return true;
	if (squareToPiece[square + 1] == -6) return true;
	if (squareToPiece[square - 8] == -6) return true;
	if (squareToPiece[square + 8] == -6) return true;
	if (squareToPiece[square - 7] == -6) return true;
	if (squareToPiece[square + 7] == -6) return true;
	if (squareToPiece[square - 9] == -6) return true;
	if (squareToPiece[square + 9] == -6) return true;
	return false;
}

bool CheckMate::isCheckBlack(map<int, int> squareToPiece, int square) {
	return false;
}
