#include < time.h>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>
#include <iostream>
using namespace std;



class Wheel {

public:

	Wheel();

	void spin();

	int* read();



private:

	int slots[9];

	int internalPtr;

};




// Constructor

Wheel::Wheel() {

	srand((int)time(NULL));



	internalPtr = (rand() % 9);



	for (int i = 0; i < 9; i++) {

		slots[i] = i + 1;

	}

}





// Spin the internal pointer around spins times.

void Wheel::spin() {

	int spins = (rand() % 50) + 10;



	for (int i = 0; i < spins; i++) {

		internalPtr++;



		if (internalPtr > 8) { internalPtr = 0; }

	}

}





// Read the wheel for its values and return 3 values in an array

int* Wheel::read() {

	int prev = internalPtr - 1;

	int next = internalPtr + 1;



	if (prev < 0) { prev = 8; }

	if (next > 8) { next = 0; }



	int* values = new int[3];



	// Get values from wheel for pointer and before/after pointer.

	values[0] = slots[prev];

	values[1] = slots[internalPtr];

	values[2] = slots[next];



	return values;

}#pragma once
