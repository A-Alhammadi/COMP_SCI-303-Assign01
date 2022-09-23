#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include "Header.h"

using namespace std;

int main() {

	const int ARRAYSIZE = 100;
	int numbers[ARRAYSIZE];
	int count = 0;
	int func;

	string File;

	cout << "Enter the file name: " << endl;
	cin >> File; //get name of file with the 10 * 10 integers

	ifstream input;
	input.open(File);
	if (!input) //if the file is not found print that and close
	{
		cout << "Input file not found." << endl;
		system("pause");
		return -1;

	}

	while (!input.eof())
	{
		input >> numbers[count];
		count++;
	}

	cout << "Select a function to run on the array (enter 1 for the search function, enter 2 for the modify function," <<
		" enter 3 for the add integer function, or enter 4 for the remove integer function) OR ENTER 5 TO EXIT :" << endl;
	cin >> func; // get option chosen

	while (func < 1 || func > 5){
		cout << endl << " Please enter a number from 1 to 5: " << endl;
		cin >> func;
	}
	while (func > 0 && func < 6) { // while input is 1 to 5 run this loop
		if (func > 0 && func < 5) {//if the input is 1 to 4 call the function selected
			switch (func) { // use int given to run the selected function
			case 1:
				search(File, count);
				break;
			case 2:
				modifyInt(File, count);
				break;
			case 3:
				addInt(File, count);
				break;
			case 4:
				removeInt(File, count);
				break;
			}
		}
		else { // this will only occur if the selected number is 5 (i.e. the exit opton)
			break; // while loop breaks
		}
		cout << "Select a function to run on the array (enter 1 for the search function, enter 2 for the modify function," <<
			" enter 3 for the add integer function, or enter 4 for the remove integer function) OR ENTER 5 TO EXIT :" << endl;
		cin >> func;
	}
	return 0;
}

void search(string File, int count) {
	int array[100];
	int cnt = count;
	int number;

	ifstream input;
	input.open(File);

	cout << "Enter an integer to search for: " << endl;
	cin >> number; //get integer to search for in array 

	for (int x = 0; x <= cnt; x++) {//fill in the array with integers from the input file starting with 0
		input >> array[x];

		if (array[x] == number) {//if the enter number is found, print the number and what index it was found in
			cout << "The Number: " << number << " was found at index " << x << endl;
		}
	}
}

void modifyInt(string File, int count) {

	int cnt = count;
	int arr[100];
	int ind;
	int newint;

	ifstream input;
	input.open(File);

	for (int y = 0; y <= cnt; y++) {
		input >> arr[count];
	}

	cout << "Enter the index number of the integer you wish to change: " << endl;//This part takes in the index number to be changed
	cin >> ind;                                                                  //and the new integer then the old integer at the index given                                                           // is changed to the new one at the index number provided
	cout << "Enter the new value you want to change to: " << endl;
	cin >> newint;
	arr[ind] = newint;
	cout << "The integer at index " << ind << " has been changed to : " << arr[ind] << endl;
}

void addInt(string File, int count) {
	int size = count + 1; // the variable to be used for the pointer below to create a new array one size larger than the count provided for the previous array
	int* s = new int[size];
	int arry[100];
	int cnt = 0;
	int add = 0;

	ifstream input;
	input.open(File);

	while (!input.eof())
	{
		input >> arry[cnt];
		cnt++;
	}

	cout << "Enter the integer you would like to add to the end of the array: " << endl;
	cin >> add;//gets the new integer to add to array

	for (int i = 0; i < cnt; i++)
		*(s + i) = arry[i];// add the first 100 elements to the dynamic array

	*(s + 100) = add; //set index 100 (i.e. element 101) to the provided integer

	if (s[count + 1] = add) { //check if the integer was added and print result
		cout << "The integer: " << s[count + 1] << " has been added successfully." << endl;//prints result, s[count + 1] i.e. s[100] should print the number added if successful
	}
}
void removeInt(string File, int count) {
	int cnt = count;
	int arry[100];
	int arr[100];
	int ind;

	ifstream input;
	input.open(File);

	for (int x = 0; x <= cnt; x++)
		input >> arr[x];

	for (int x = 0; x <= cnt; x++)
		input >> arry[x];

	cout << "Enter the index number of the integer you want to remove from the array: " << endl;
	cin >> ind; // get index number of element to be removed

	for (int i = ind; i <= cnt; i++)// starting at the element removed, make it equal to the next element and so on for the rest
	{
		arr[i] = arry[i + 1];
	}
	arr[99] = {}; // make sure the last element is blank

	cout << "The integer at index " << ind << " has been removed." << endl;
	//cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << " " << arr[3]; // testing
}