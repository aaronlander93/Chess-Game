#include "stdafx.h"
#include "ValidMove.h"

using namespace std;

bool ValidMove::isValidMove(map<int, int> squareToPiece, int oldSquare, int newSquare, int pieceType, bool whiteMove)
{
	//Check if it's player's turn
	if (!isTurn(pieceType, whiteMove))
	{
		return false;
	}

	bool isValid = false;

	//Identify if white or black pawn. All other pieces can be treated the same
	if (pieceType != -1)
	{
		pieceType = abs(pieceType);
	}

	switch (pieceType)
	{
	case -1:
		//Black pawn
		isValid = isValidBlackPawn(oldSquare, newSquare, squareToPiece);
		break;

	case 1:
		//White pawn
		isValid = isValidWhitePawn(oldSquare, newSquare, squareToPiece);
		break;

	case 2:
		//Rook
		isValid = isValidRook(oldSquare, newSquare, pieceType, squareToPiece);
		break;
	
	case 3:
		//Knight
		isValid = isValidKnight(oldSquare, newSquare);
		break;

	case 4:
		//Bishop
		isValid = isValidBishop(oldSquare, newSquare, squareToPiece);
		break;
		
	case 5:
		//Queen
		isValid = isValidQueen(oldSquare, newSquare, squareToPiece);
		break;
	case 6:
		//King
		isValid = isValidKing(oldSquare, newSquare);
		break;
	}
	return isValid;
}

int ValidMove::castleType(map<int, int> squareToPiece, int newSquare, int pieceType)
{
	int whiteKing = 6;
	int blackKing = -6;
	int whiteRook = 2;
	int blackRook = -2;
	//White king
	if (pieceType == 6)
	{
		//Attempting to castle
		if (newSquare == 6)
		{
			//King and rook in appropriate spot
			if (squareToPiece[4] == whiteKing && squareToPiece[7] == whiteRook)
			{
				//No pieces blocking
				if (!isPieceOnSquare(squareToPiece, 5) && !isPieceOnSquare(squareToPiece, 6))
				{
					return 1;
				}
				//Piece blocking
				else
				{
					return 0;
				}
			}
		}
		else if (newSquare == 2)
		{
			if (squareToPiece[4] == 6 && squareToPiece[0] == 2)
			{
				//No pieces blocking
				if (!isPieceOnSquare(squareToPiece, 1) && !isPieceOnSquare(squareToPiece, 2) && !isPieceOnSquare(squareToPiece, 3))
				{
					return 2;
				}
			}
		}
	}
	//Black King
	else if (pieceType == blackKing)
	{
		if(newSquare == 62)
		{
			if(squareToPiece[63] == blackRook && squareToPiece[60] == blackKing)
			{
				if(!isPieceOnSquare(squareToPiece, 61) && !isPieceOnSquare(squareToPiece, 62))
				{
					return 3;
				}
			}
		}
		else if(newSquare == 58)
		{
			if(squareToPiece[56] == blackRook && squareToPiece[60] == blackKing)
			{
				if (!isPieceOnSquare(squareToPiece, 57) && !isPieceOnSquare(squareToPiece, 58) && !isPieceOnSquare(squareToPiece, 59))
				{
					return 4;
				}
				else
				{
					return 0;
				}
			}
		}
	}

	return 0;
}

bool ValidMove::isTurn(int pieceType, bool whiteTurn)
{
	//White piece and black turn
	if (pieceType > 0 && !whiteTurn)
	{
		return false;
	}

	//Black piece and white turn
	else if (pieceType < 0 && whiteTurn)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool ValidMove::isAttemptedTake(map<int, int> squareToPiece, int pieceType, int square)
{
	if (pieceType > 0 && squareToPiece[square] < 0)
	{
		return true;
	}
	else if (pieceType < 0 && squareToPiece[square] > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool ValidMove::isPieceOnSquare(map<int, int> squareToPiece, int square)
{
	return squareToPiece[square];
}

bool ValidMove::isValidBlackPawn(int oldSquare, int newSquare, map<int, int> squareToPiece)
{
	if (oldSquare < 56 && oldSquare > 47)
	{
		if (oldSquare - 8 == newSquare)
		{
			return true;
		}
		else if(oldSquare - 16 == newSquare && !isPieceOnSquare(squareToPiece, newSquare + 8))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (oldSquare - 8 == newSquare)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ValidMove::isValidWhitePawn(int oldSquare, int newSquare, map<int, int> squareToPiece)
{
	if (oldSquare < 16 && oldSquare > 7)
	{
		if (oldSquare + 8 == newSquare)
		{
			return true;
		}
		else if (oldSquare + 16 == newSquare && !isPieceOnSquare(squareToPiece, newSquare - 8))
		{
			return true;
		}
		else
		{
			return false;
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

bool ValidMove::isValidRook(int oldSquare, int newSquare, int pieceType, map<int, int> squareToPiece)
{
	bool collision = false;

	for (int i = oldSquare + 8; i <= 64; i += 8)
	{
		if (isPieceOnSquare(squareToPiece, i) && !collision)
		{
			if (i == newSquare && isAttemptedTake(squareToPiece, pieceType, newSquare)
				&& !collision)
			{
				return true;
			}
			collision = true;
		}

		if (i == newSquare && !collision)
		{
			return true;
		}
	}

	collision = false;

	for (int i = oldSquare - 8; i >= 0; i -= 8)
	{
		if (isPieceOnSquare(squareToPiece, i) && !collision)
		{
			collision = true;
		}
		if (i == newSquare && !collision)
		{
			return true;
		}
	}

	collision = false;

	for (int i = oldSquare + 1; i <= 64; i++)
	{
		if (isPieceOnSquare(squareToPiece, i) && !collision)
		{
			collision = true;
		}
		if (i % 8 == 0)
		{
			break;
		}
		else if (i == newSquare && !collision)
		{
			return true;
		}
	}

	collision = false;

	for (int i = oldSquare - 1; i >= 0; i--)
	{
		if (isPieceOnSquare(squareToPiece, i) && !collision)
		{
			collision = true;
		}

		if (i % 8 == 0)
		{
			if (i == newSquare && !collision)
			{
				return true;
			}
			else
			{
				break;
			}
		}
		if (i == newSquare && !collision)
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

bool ValidMove::isValidBishop(int oldSquare, int newSquare, map<int, int> squareToPiece)
{
	bool collision = false;
	int pieceType = 4;

	for (int i = oldSquare + 9; i <= 64; i += 9)
	{
		if (isPieceOnSquare(squareToPiece, i) && !collision)
		{			
			if (i == newSquare && isAttemptedTake(squareToPiece, pieceType, newSquare)
				&& !collision)
			{
				return true;
			}

			collision = true;
		}
		if (i == newSquare && !collision)
		{
			return true;
		}
	}

	collision = false;

	for (int i = oldSquare - 9; i >= 0; i -= 9)
	{
		if (isPieceOnSquare(squareToPiece, i) && !collision)
		{
			if (i == newSquare && isAttemptedTake(squareToPiece, pieceType, newSquare)
				&& !collision)
			{
				return true;
			}

			collision = true;
		}

		if (i == newSquare && !collision)
		{
			return true;
		}
	}

	collision = false;

	for (int i = oldSquare + 7; i <= 64; i += 7)
	{
		if (isPieceOnSquare(squareToPiece, i) && !collision)
		{
			if (i == newSquare && isAttemptedTake(squareToPiece, pieceType, newSquare) 
				&& !collision)
			{
				return true;
			}

			collision = true;
		}

		if (i == newSquare && !collision)
		{
			return true;
		}
	}

	collision = false;

	for (int i = oldSquare - 7; i >= 0; i -= 7)
	{
		if (isPieceOnSquare(squareToPiece, i) && !collision)
		{
			if (i == newSquare && isAttemptedTake(squareToPiece, pieceType, newSquare)
				&& !collision)
			{
				return true;
			}
			collision = true;
		}

		if (i == newSquare && !collision)
		{
			return true;
		}
	}

	return false;
}

bool ValidMove::isValidQueen(int oldSquare, int newSquare, map<int, int> squareToPiece)
{
	if (isValidRook(oldSquare, newSquare, squareToPiece) || isValidBishop(oldSquare, newSquare, squareToPiece))
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

	//Castle attempt
	if (oldSquare + 2 == newSquare || oldSquare - 2 == newSquare) return true;

	return false;
}