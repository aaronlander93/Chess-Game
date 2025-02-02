// ChessGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ValidMove.h"
#include "CheckMate.h"
#include "SFML/Graphics.hpp"

using namespace sf;
using namespace std;

void loadPieces(Sprite*, Texture*);
void setPositions(Sprite*);
map<int, int> loadSquareCoords();
map<int, int> mapSquareToPiece();
void drawCastle(map<int, int>, Sprite*, int, int);
int getCantorPair(int, int);

const int NUM_PIECES = 32;
const int SIDE_LENGTH = 63;
const int EMPTY_SQUARE = 0;

int main() {
	RenderWindow window(VideoMode(504, 504), "Chess", Style::Close);
	
	ValidMove valid;
	CheckMate check;

	Texture t1;
	Texture images[NUM_PIECES];
	Sprite pieces[NUM_PIECES];
	Sprite board;

	map<int, int> squareCoords;
	squareCoords = loadSquareCoords();

	map<int, int> squareToPiece;
	squareToPiece= mapSquareToPiece();

	t1.loadFromFile("images/board.png");
	loadPieces(pieces, images);

	board.setTexture(t1);
	
	setPositions(pieces);

	bool isPieceHeld = false;
	bool whiteMove = true;

	int pieceHeld = false;
	int origX;
	int origY;
	
	while (window.isOpen()) {
		Event evnt;
		
		while (window.pollEvent(evnt)) {
			switch (evnt.type) {
			case Event::Closed:
				window.close();
				break;
			}
			if (Mouse::isButtonPressed(Mouse::Left)) {
				Vector2i mPosition = Mouse::getPosition(window);
				int x = mPosition.x;
				int y = mPosition.y;

				for (int i = 0; i < NUM_PIECES; i++) {
					FloatRect fBounds = pieces[i].getGlobalBounds();
					Vector2f fPosition = pieces[i].getPosition();
					
					//Ensures only one piece can be held at a time
					if (isPieceHeld && pieceHeld != i) {
						continue;
					}
					//Check if mouse is within width of piece
					if (x >= fBounds.left && x <= (fBounds.width + fBounds.left)) {
						//Check if mouse is within height of piece
						if (y >= fBounds.top && y <= (fBounds.height + fBounds.top)) {
							//Capture original position of piece
							if (!isPieceHeld) {
								origX = fPosition.x;
								origY = fPosition.y;
							}

							//Piece picked up
							isPieceHeld = true;
							pieceHeld = i;
							window.draw(pieces[i]);

							mPosition = Mouse::getPosition(window);
							fBounds = pieces[pieceHeld].getGlobalBounds();

							float newX = float(mPosition.x) - (fBounds.width / 2);
							float newY = float(mPosition.y) - (fBounds.height / 2);

							pieces[pieceHeld].setPosition(newX, newY);
							fPosition = pieces[pieceHeld].getPosition();
						}
					}
				}			
			}
			else if (evnt.type == Event::MouseButtonReleased && isPieceHeld) {
				//Piece released
				Vector2i mPosition = Mouse::getPosition(window);
				FloatRect fBounds = pieces[pieceHeld].getGlobalBounds();

				float newX = (floor(mPosition.x / SIDE_LENGTH) * SIDE_LENGTH) + (SIDE_LENGTH / 2);
				float newY = (floor(mPosition.y / SIDE_LENGTH) * SIDE_LENGTH) + (SIDE_LENGTH / 2);

				newX = newX - (fBounds.width / 2);
				newY = newY - (fBounds.height / 2);

				int oldSquare = getCantorPair(origX, origY);
				int newSquare = getCantorPair(newX, newY);
				oldSquare = squareCoords[oldSquare];
				newSquare = squareCoords[newSquare];

				int pieceType = squareToPiece[oldSquare];
				bool validMove = valid.isValidMove(squareToPiece, oldSquare, newSquare, pieceType, whiteMove);			
				bool isCheck = check.isCheck(squareToPiece, whiteMove, oldSquare, newSquare, pieceType);

				if (validMove && !isCheck) {
					//Check for castle
					if (abs(pieceType) == 6) {
						int castleType = valid.castleType(squareToPiece, newSquare, pieceType);
						if (castleType) {
							drawCastle(squareToPiece, pieces, castleType, pieceType);
						}
					}
					if (squareToPiece[newSquare] != 0) {
						//Remove opposing piece
						Vector2f opPosition;
						int opPiece;

						for (int i = 0; i < NUM_PIECES; i++) {
							opPosition = pieces[i].getPosition();
							if (opPosition.x == newX && opPosition.y == newY) {
								opPiece = i;
								break;
							}
						}
						pieces[opPiece].setPosition(-100, -100);
					}
					//Update piece position
					pieces[pieceHeld].setPosition(newX, newY);
					squareToPiece[oldSquare] = 0;
					squareToPiece[newSquare] = pieceType;

					whiteMove = !whiteMove;

					//See if move just made puts opponent in check
					isCheck = check.isCheck(squareToPiece, whiteMove);

				} else {
					//Square occupied. Place piece back in original square
					pieces[pieceHeld].setPosition(origX, origY);
				}
				isPieceHeld = false; 
			}
		}
		
		window.display();
		window.draw(board);

		for (int i = 0; i < NUM_PIECES; i++) {
			if (isPieceHeld && i == pieceHeld) {
				continue;
			}
			else {
				window.draw(pieces[i]);
			}
		}
		//If piece is held, draw to the top layer
		if (isPieceHeld) {
			window.draw(pieces[pieceHeld]);
		}
	}
	
}

 void loadPieces(Sprite* pieces, Texture* images) {

	 //Load white pieces
	 images[0].loadFromFile("images/whiterook.png");
	 images[1].loadFromFile("images/whiteknight.png");
	 images[2].loadFromFile("images/whitebishop.png");
	 images[3].loadFromFile("images/whitequeen.png");
	 images[4].loadFromFile("images/whiteking.png");
	 images[5].loadFromFile("images/whitebishop.png");
	 images[6].loadFromFile("images/whiteknight.png");
	 images[7].loadFromFile("images/whiterook.png");
	 for(int i = 8; i < 16;i++) images[i].loadFromFile("images/whitepawn.png");
	 
	 //Load black pieces
	 for (int i = 16; i < 24; i++) images[i].loadFromFile("images/blackpawn.png");
	 images[24].loadFromFile("images/blackrook.png");
	 images[25].loadFromFile("images/blackknight.png");
	 images[26].loadFromFile("images/blackbishop.png");
	 images[27].loadFromFile("images/blackqueen.png");
	 images[28].loadFromFile("images/blackking.png");
	 images[29].loadFromFile("images/blackbishop.png");
	 images[30].loadFromFile("images/blackknight.png");
	 images[31].loadFromFile("images/blackrook.png");
	 

	 for (int i = 0; i < 32; i++) pieces[i].setTexture(images[i]);
}

void setPositions(Sprite* pieces) {
	int x = 1;
	int y = 442;

	//White pieces
	for (int i = 0; i < 16; i++) {
		pieces[i].setPosition(x, y);
		x += 63;

		if (x > 504) {
			x = 1;
			y -= 63;
		}
	}

	x = 1;
	y = 64;
	//Black pieces
	for (int i = 16; i < 32; i++) {
		pieces[i].setPosition(x, y);
		x += 63;

		if (x > 504) {
			x = 1;
			y -= 63;
		}
	}
}

map<int, int> mapSquareToPiece() {
	map<int, int> squareToPiece;

	//Rooks
	squareToPiece[0] = 2;
	squareToPiece[7] = 2;
	squareToPiece[56] = -2;
	squareToPiece[63] = -2;

	//Knights
	squareToPiece[1] = 3;
	squareToPiece[6] = 3;
	squareToPiece[57] = -3;
	squareToPiece[62] = -3;

	//Bishops
	squareToPiece[2] = 4;
	squareToPiece[5] = 4;
	squareToPiece[58] = -4;
	squareToPiece[61] = -4;

	//Queens
	squareToPiece[3] = 5;
	squareToPiece[59] = -5;

	//Kings
	squareToPiece[4] = 6;
	squareToPiece[60] = -6;

	//Pawns
	for (int i = 8; i < 16; i++) squareToPiece[i] = 1;
	for (int i = 48; i < 56; i++) squareToPiece[i] = -1;

	//Empty squares
	for (int i = 16; i < 48; i++) squareToPiece[i] = 0;
	return squareToPiece;
}

map<int, int> loadSquareCoords() {
	map<int, int> squareCoords;

	const int NUM_SQUARES = 64;
	int x = 1;
	int y = 442;

	for (int i = 0; i < NUM_SQUARES; i++) {
		int coords[2];
		coords[0] = x;
		coords[1] = y;
		
		int cantorPair = getCantorPair(x, y);
		squareCoords.insert({ cantorPair, i });

		x += SIDE_LENGTH;

		if (x >= 503) {
			x = 1;
			y -= SIDE_LENGTH;
		}
	}

	return squareCoords;
}
void drawCastle(map<int, int> squareToPiece, Sprite* pieces, int castleType, int pieceHeld)
{
	Vector2f rPosition;
	Vector2f kPosition;

	int oldX, oldY;
	int newX, newY;
	int oldSquare, newSquare;
	int whiteRookFigure, blackRookFigure;
	int squareDistance;

	int whiteRook = 2;
	int blackRook = -2;

	switch (castleType) {
	case 1:
		//Move rook
		whiteRookFigure = 7;
		oldSquare = 7;
		newSquare = 5;

		squareToPiece[oldSquare] = EMPTY_SQUARE;
		squareToPiece[newSquare] = whiteRook;

		rPosition = pieces[whiteRookFigure].getPosition();
		oldX = rPosition.x;
		oldY = rPosition.y;

		squareDistance = SIDE_LENGTH * (abs(newSquare - oldSquare));
		newX = oldX - squareDistance;
		newY = oldY;

		pieces[whiteRookFigure].setPosition(newX, newY);
		break;

	case 2:
		whiteRookFigure = 0;
		oldSquare = 0;
		newSquare = 3;

		squareToPiece[oldSquare] = EMPTY_SQUARE;
		squareToPiece[newSquare] = whiteRook;

		rPosition = pieces[whiteRookFigure].getPosition();
		oldX = rPosition.x;
		oldY = rPosition.y;

		squareDistance = SIDE_LENGTH * (abs(newSquare - oldSquare));
		newX = oldX + squareDistance;
		newY = oldY;

		pieces[whiteRookFigure].setPosition(newX, newY);
		break;

	case 3:
		blackRookFigure = 31;
		oldSquare = 63;
		newSquare = 61;

		squareToPiece[oldSquare] = EMPTY_SQUARE;
		squareToPiece[newSquare] = blackRook;

		rPosition = pieces[blackRookFigure].getPosition();
		oldX = rPosition.x;
		oldY = rPosition.y;

		squareDistance = SIDE_LENGTH * (abs(newSquare - oldSquare));
		newX = oldX - squareDistance;
		newY = oldY;

		pieces[blackRookFigure].setPosition(newX, newY);
		break;

	case 4:
		blackRookFigure = 24;
		oldSquare = 56;
		newSquare = 59;

		squareToPiece[oldSquare] = EMPTY_SQUARE;
		squareToPiece[newSquare] = blackRook;

		rPosition = pieces[blackRookFigure].getPosition();
		oldX = rPosition.x;
		oldY = rPosition.y;

		squareDistance = SIDE_LENGTH * (abs(newSquare - oldSquare));
		newX = oldX + squareDistance;
		newY = oldY;

		pieces[blackRookFigure].setPosition(newX, newY);
	}
}

int getCantorPair(int x, int y) {
	return (((x + y)*(x + y + 1)) / 2) + y;
}