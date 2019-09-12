#include "stdafx.h"
#include "ValidMove.h"

using namespace std;

bool ValidMove::isValidMove(map<int, int> squareToPiece, int oldSquare, int newSquare, int piece, bool whiteMove) {
	//Check if it's player's turn
	if (!isTurn(piece, whiteMove)) {
		return false;
	}

	bool isValid = false;
	int pieceType = abs(piece);

	//Identify if white or black pawn. All other pieces can be treated the same
	if (piece != -1) {
		pieceType = abs(piece);
	}
	else {
		pieceType = -1;
	}

	switch (pieceType) {
	case -1:
		//Black pawn
		isValid = isValidBlackPawn(oldSquare, newSquare, squareToPiece);
		break;

	case 1:
		//White pawn
		isValid = isValidWhitePawn(oldSquare, newSquare, squareToPiece);

		if (isValid) {

		}
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
		isValid = isValidQueen(oldSquare, newSquare, pieceType, squareToPiece);
		break;
	case 6:
		//King
		isValid = isValidKing(oldSquare, newSquare);
		break;
	}

	if (isValid) {
		bool pieceOnSquare = isPieceOnSquare(squareToPiece, newSquare);

		if (!pieceOnSquare) {
			return true;
		}
		else if (pieceOnSquare && isAttemptedTake(squareToPiece, piece, newSquare)) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}



bool ValidMove::isTurn(int pieceType, bool whiteTurn) {
	//White piece and black turn
	if (pieceType > 0 && !whiteTurn) {
		return false;
	} else if (pieceType < 0 && whiteTurn) {
		return false;
	} else {
		return true;
	}
}

bool ValidMove::isAttemptedTake(map<int, int> squareToPiece, int pieceType, int square) {
	if (pieceType > 0 && squareToPiece[square] < 0) {
		return true;
	} else if (pieceType < 0 && squareToPiece[square] > 0) {
		return true;
	} else {
		return false;
	}
}

bool ValidMove::isPieceOnSquare(map<int, int> squareToPiece, int square) {
	return squareToPiece[square];
}





