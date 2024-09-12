#include <iostream>
#include <fstream>
#include "functions.h"
using namespace std;

void modifyValue(int array[], int iIVNum, int rNNum) {
	int oldValue = array[iIVNum];
	array[iIVNum] = rNNum; // Assigns replacement number at user inputed index value.
	int newValue = array[iIVNum];
	// Prints out the modified number at index; before and after modifying.
	cout << "Old Integer at " << iIVNum << ": " << oldValue << "\n";
	cout << "New Integer at " << iIVNum << ": " << rNNum << "\n";
}

void addValue(int array[], int arrayMaxIndex, int iNVNum) {
	array[arrayMaxIndex] = iNVNum; // Assigns inputted integer at the highest index value; end of the array.
}

void showArray(int array[], int arrayMaxIndex) {
	for (int i = 0; i < arrayMaxIndex; i++) { // Print loop, until i = arrayMaxIndex.
		cout << array[i] << " ";
	}
}

void repwZero(int array[], int iIV2Num) {
	array[iIV2Num] = 0; // Assigns 0 at user inputted index value.
}