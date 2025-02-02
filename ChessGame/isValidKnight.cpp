#include "stdafx.h"
#include "ValidMove.h"

bool ValidMove::isValidKnight(int oldSquare, int newSquare) {

	if (oldSquare + 6 == newSquare) {
		for (int i = 0; i < 63; i += 8) {
			if (oldSquare == i || oldSquare == i + 1) {
				return false;
			}
			else {
				return true;
			}
		}
	}
	else if (oldSquare - 6 == newSquare) {
		for (int i = 6; i < 63; i += 8) {
				if (oldSquare == i || oldSquare == i + 1) {
					return false;
				}
				else {
					return true;
				}
		}
	}

	if (oldSquare + 10 == newSquare || oldSquare - 10 == newSquare) return true;
	if (oldSquare + 15 == newSquare || oldSquare - 15 == newSquare) return true;
	if (oldSquare + 17 == newSquare || oldSquare - 17 == newSquare) return true;

	return false;
}