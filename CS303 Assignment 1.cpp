// CS303 Assignment 1 - Duy Lam //
#include <iostream>
#include <fstream>
#include "functions.h"
#include <stdexcept>
#include <string>
using namespace std;

int main()
{
    ifstream inFile;

    // Used to determine if text file can be found or not, had issues of txt document not being read and showing an empty console.
    inFile.open("A1input.txt");
    if (!inFile) {
        std::cout << "Error: Unable to locate and open text file.";
        exit(1);
    }
    
    // If file is found, opens and converts into array. Initial parameters are set.
    ifstream myFile("A1input.txt");
    int array[999];
    int arrayMaxIndex = 100;
    int count = 0;
    int numbers;
    bool validInput = false;
    while (!myFile.eof()){
        myFile >> numbers;
        array[count] = numbers;
        count++;
    }
    //Function that checks if the user inputted number is in the array.
    string inputNum;
    cout << "\nEnter a integer to find in the array: ";
    cin >> inputNum;
    bool foundInputNum = false;
    int num;
        while(!foundInputNum){
            while (!validInput){
                try {
                    num = std::stoi(inputNum);  // THROWS EXCEPTION: Inputted Incorrect Data Type
                    validInput = true;  // Set the flag to true if conversion is successful
                    if (num <= 0 || num > count) {
                        throw out_of_range(" is outside of range and/or not in the array. Try a different integer: ");
                        validInput = false; //reset
                    }
                }
                catch (const std::invalid_argument& e) {
                    cout << "Error: Invalid Input: Please enter a valid integer between 1-" << count << ": ";
                    cin >> inputNum; //reprompt
                }
                catch (const std::out_of_range& e) {
                    cout << inputNum << e.what();
                    cin >> inputNum;
                    validInput = false;
                }
            } 
            for (int i = 0; i < 100; i++) {
                if (num == array[i]) {
                    cout << num << " is located at index " << i << ".\n";
                    foundInputNum = true;
                }
            }
        }

    // Modifying a value at user inputted index.//
    // User inputs index value.
    string inputIndexValue;
    cout << "\nEnter the index value of the number you would like to modify: ";
    cin >> inputIndexValue;
    int iIVNum;
    validInput = false;
    while (!validInput) {
        try {
            iIVNum = std::stoi(inputIndexValue);  // THROWS EXCEPTION: Inputted Incorrect Data Type
            validInput = true;  // Set the flag to true if conversion is successful
            if (iIVNum <= 0 || iIVNum >= arrayMaxIndex) { // EXCEPTION: Int value exceeds array size
                throw out_of_range("Error: Invalid Input: Please enter a valid integer between 1-");
                validInput = false; //reset
            }
        }
        catch (const std::invalid_argument& e) {
            cout << "Error: Invalid Input: Please enter a valid integer: ";
            cin >> inputIndexValue; //reprompt
            validInput = false;
        }
        catch (const std::out_of_range& e) {
            cout << e.what() << count-1 << ": ";
            cin >> inputIndexValue;
            validInput = false;
        }
    }
    // User inputs integer to replace with at index
    string repNum;
    cout << "Enter an integer to replace the number in that index value with: ";
    cin >> repNum;
    int rNNum;
    validInput = false;
    while (!validInput) {
        try {
            rNNum = std::stoi(repNum);  // THROWS EXCEPTION: Inputted Incorrect Data Type
            validInput = true;
        }
        catch (const std::invalid_argument& e) {
            cout << "Error: Invalid Input: Please enter a valid integer: ";
            cin >> repNum;
        }
    }
    modifyValue(array, iIVNum, rNNum);

    // Adding a value to the end of the array //
    string inpNewVal;
    cout << "\nEnter a value to add to the end of the array: ";
    cin >> inpNewVal;
    int iNVNum;
    validInput = false;
    while (!validInput){
        try {
            iNVNum = std::stoi(inpNewVal);  // THROWS EXCEPTION: Inputted Incorrect Data Type
            validInput = true;
        }
        catch (const std::invalid_argument& e) {
            cout << "Error: Invalid Input: Please enter a valid integer: ";
            cin >> inpNewVal;
        }
    }
    addValue(array, arrayMaxIndex, iNVNum);
    arrayMaxIndex++;
    cout << "\nThe New Array:" << "\n";
    showArray(array, arrayMaxIndex);
    cout << "\n";

    // Replacing an index value with zero.
    string inputIndexVal2;
    cout << "\nEnter the index value to change it's integer to zero: ";
    cin >> inputIndexVal2;
    int iIV2Num = 0;
    while (!validInput) {
        try {
            iIV2Num = std::stoi(inputIndexVal2);  // THROWS EXCEPTION: Inputted Incorrect Data Type
            validInput = true;  // Set the flag to true if conversion is successful
            if (iIV2Num <= 0 || iIV2Num >= count) { // EXCEPTION: Int value exceeds array size
                throw out_of_range("Error: Invalid Input: Please enter a valid integer between 1-99: ");
                validInput = false;
            }
        }
        catch (const std::invalid_argument& e) {
            cout << "Error: Invalid Input: Please enter a valid integer: ";
            cin >> inputIndexVal2;
            validInput = false;
        }
        catch (const std::out_of_range& e) {
            cout << e.what() << count << ": ";
            cin >> inputIndexVal2;
            validInput = false;
        }
    }
    iIV2Num = std::stoi(inputIndexVal2);
    repwZero(array,iIV2Num);
    cout << "\nYour new array is: " << endl;
    showArray(array, arrayMaxIndex);

    cout << "\n\nClosing program \n";
    return 0;
}