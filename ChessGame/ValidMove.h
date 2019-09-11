#include "stdafx.h"

using namespace std;

#ifndef VALIDMOVE_H
#define VALIDMOVE_H

class ValidMove
{
public:
	bool isValidMove(map<int, int> , int , int, int, bool);
	int castleType(map<int, int>, int, int);


private:
	bool isTurn(int, bool);
	bool isAttemptedTake(map<int, int>, int, int);
	bool isPieceOnSquare(map<int, int>, int);
	bool isValidBlackPawn(int, int, map<int, int>);
	bool isValidWhitePawn(int, int, map<int, int>);
	bool isValidRook(int, int, int, map<int, int>);
	bool isValidKnight(int, int);
	bool isValidBishop(int, int, map<int, int>);
	bool isValidQueen(int, int, map<int, int>);
	bool isValidKing(int, int);
};

#endif