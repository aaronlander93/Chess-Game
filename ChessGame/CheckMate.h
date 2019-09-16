#include "stdafx.h"

using namespace std;

#ifndef CHECKMATE_H
#define CHECKMATE_H

class CheckMate
{
public:
	bool isCheck(map<int, int>, bool);
	bool isCheck(map<int, int>, bool, int, int, int);

private:
	bool isCheckWhite(map<int, int>, int);
	bool isCheckBlack(map<int, int>, int);
};
#endif