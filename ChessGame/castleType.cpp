#include "stdafx.h"
#include "ValidMove.h"

int ValidMove::castleType(map<int, int> squareToPiece, int newSquare, int pieceType) {
	int whiteKing = 6;
	int blackKing = -6;
	int whiteRook = 2;
	int blackRook = -2;

	//White king
	if (pieceType == 6) {
		//Attempting to castle
		if (newSquare == 6) {
			//King and rook in appropriate spot
			if (squareToPiece[4] == whiteKing && squareToPiece[7] == whiteRook) {
				//No pieces blocking
				if (!isPieceOnSquare(squareToPiece, 5) && !isPieceOnSquare(squareToPiece, 6)) {
					return 1;
				}
				//Piece blocking
				else {
					return 0;
				}
			}
		}
		else if (newSquare == 2) {
			if (squareToPiece[4] == 6 && squareToPiece[0] == 2) {
				//No pieces blocking
				if (!isPieceOnSquare(squareToPiece, 1) && !isPieceOnSquare(squareToPiece, 2) && 
					!isPieceOnSquare(squareToPiece, 3)) {
					return 2;
				}
			}
		}
	}
	else if (pieceType == blackKing) {
		if (newSquare == 62) {
			if (squareToPiece[63] == blackRook && squareToPiece[60] == blackKing) {
				if (!isPieceOnSquare(squareToPiece, 61) && !isPieceOnSquare(squareToPiece, 62)) {
					return 3;
				}
			}
		}
		else if (newSquare == 58) {
			if (squareToPiece[56] == blackRook && squareToPiece[60] == blackKing) {
				if (!isPieceOnSquare(squareToPiece, 57) && !isPieceOnSquare(squareToPiece, 58) && 
					!isPieceOnSquare(squareToPiece, 59)) {
					return 4;
				}
				else {
					return 0;
				}
			}
		}
	}

	return 0;
}