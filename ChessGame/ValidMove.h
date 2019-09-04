#include "stdafx.h"

using namespace std;

#ifndef VALIDMOVE_H
#define VALIDMOVE_H

class ValidMove
{
public:
	bool isValidMove(map<int, int> , int , int, int);

private:
	bool isValidPawn(int, int);
	bool isValidRook(int, int);
	bool isValidKnight(int, int);
	bool isValidBishop(int, int);
	bool isValidQueen(int, int);
	bool isValidKing(int, int);
};

#endif