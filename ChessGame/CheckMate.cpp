#include "stdafx.h"
#include "CheckMate.h"

using namespace std;

bool CheckMate::isCheck(map<int, int> squareToPiece, bool whiteMove, int square) {
	bool check = false;

	if (whiteMove) {
		check = isCheckWhite(squareToPiece, square);
	}
	else {
		check = isCheckBlack(squareToPiece, square);
	}

	return check;
}

bool CheckMate::isCheckWhite(map<int, int> squareToPiece, int square) {
	//Pawn attack
	if (squareToPiece[square + 7] == -1 || squareToPiece[square + 9] == -1) {
		return true;
		cout << "check" << endl;
	}
	//Rook attack

	//Knight attack

	//Bishop attack

	//Queen attack
	return false;
}

bool CheckMate::isCheckBlack(map<int, int> squareToPiece, int square) {
	return false;
}
