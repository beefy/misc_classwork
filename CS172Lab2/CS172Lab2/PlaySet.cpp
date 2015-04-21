#include <iostream>
#include <string>
#include "Card.h"

Card deck[30];
Card current[12];

bool isSet(Card cardA, Card cardB, Card cardC) {

	bool goodColor;
	bool goodShape;
	bool goodFilling;
	bool goodNumber;

	goodColor = ((cardA.color == cardB.color && cardB.color == cardC.color) ||
		(cardA.color != cardB.color && cardB.color != cardC.color && cardA.color != cardC.color));

	goodFilling = ((cardA.filling == cardB.filling && cardB.filling == cardC.filling) ||
		(cardA.filling != cardB.filling && cardB.filling != cardC.filling && cardA.filling != cardC.filling));

	goodShape = ((cardA.shape == cardB.shape && cardB.shape == cardC.shape) ||
		(cardA.shape != cardB.shape && cardB.shape != cardC.shape && cardA.shape != cardC.shape));

	goodNumber = ((cardA.number == cardB.number && cardB.number == cardC.number) ||
		(cardA.number != cardB.number && cardB.number != cardC.number && cardA.number != cardC.number));

	return (goodColor && goodShape && goodFilling && goodNumber);
}

void main() {

}
