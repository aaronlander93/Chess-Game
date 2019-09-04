#include "stdafx.h"
#include "ValidMove.h"
using namespace std;

bool ValidMove::isValidMove(map<int, int> squareToPiece, int oldSquare, int newSquare, int pieceType)
{
	bool isValid = false;

	switch (pieceType)
	{
	case 1:
		//Pawn
		isValid = isValidPawn(oldSquare, newSquare);
		return isValid;

	case 2:
		//Rook
		isValid = isValidRook(oldSquare, newSquare);
		return isValid;
	
	case 3:
		isValid = isValidKnight(oldSquare, newSquare);
		return isValid;

	case 4:
		isValid = isValidBishop(oldSquare, newSquare);
		return isValid;
		
	case 5:
		isValid = isValidQueen(oldSquare, newSquare);
		return isValid;
	case 6:
		isValid = isValidKing(oldSquare, newSquare);
		return isValid;
	}
	return false;
}

bool ValidMove::isValidPawn(int oldSquare, int newSquare)
{
	if (oldSquare < 16 && oldSquare > 7)
	{
		if (oldSquare + 8 == newSquare || oldSquare + 16 == newSquare)
		{
			return true;
		}
	}
	else if (oldSquare + 8 == newSquare)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ValidMove::isValidRook(int oldSquare, int newSquare)
{
	for (int i = oldSquare; i <= 64; i += 8)
	{
		if (i == newSquare)
		{
			return true;
		}
	}

	for (int i = oldSquare; i >= 0; i -= 8)
	{
		if (i == newSquare)
		{
			return true;
		}
	}

	for (int i = oldSquare + 1; i <= 64; i++)
	{
		if (i % 8 == 0)
		{
			break;
		}
		else if (i == newSquare)
		{
			return true;
		}
	}

	for (int i = oldSquare - 1; i >= 0; i--)
	{
		if (i % 8 == 0)
		{
			if (i == newSquare)
			{
				return true;
			}
			else
			{
				break;
			}
		}
		if (i == newSquare)
		{
			return true;
		}
	}

	return false;
}

bool ValidMove::isValidKnight(int oldSquare, int newSquare)
{
	if (oldSquare + 6 == newSquare || oldSquare - 6 == newSquare) return true;
	if (oldSquare + 10 == newSquare || oldSquare - 10 == newSquare) return true;
	if (oldSquare + 15 == newSquare || oldSquare - 15 == newSquare) return true;
	if (oldSquare + 17 == newSquare || oldSquare - 17 == newSquare) return true;

	return false;
}

bool ValidMove::isValidBishop(int oldSquare, int newSquare)
{
	for (int i = oldSquare; i <= 64; i += 9)
	{
		if (i == newSquare)
		{
			return true;
		}
	}

	for (int i = oldSquare; i >= 0; i -= 9)
	{
		if (i == newSquare)
		{
			return true;
		}
	}

	for (int i = oldSquare; i <= 64; i += 7)
	{
		if (i == newSquare)
		{
			return true;
		}
	}

	for (int i = oldSquare; i >= 0; i -= 7)
	{
		if (i == newSquare)
		{
			return true;
		}
	}

	return false;
}

bool ValidMove::isValidQueen(int oldSquare, int newSquare)
{
	if (isValidRook(oldSquare, newSquare) || isValidBishop(oldSquare, newSquare))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ValidMove::isValidKing(int oldSquare, int newSquare)
{
	if (oldSquare + 1 == newSquare || oldSquare - 1 == newSquare) return true;
	if (oldSquare + 7 == newSquare || oldSquare - 7 == newSquare) return true;
	if (oldSquare + 8 == newSquare || oldSquare - 8 == newSquare) return true;
	if (oldSquare + 9 == newSquare || oldSquare - 9 == newSquare) return true;

	return false;
}