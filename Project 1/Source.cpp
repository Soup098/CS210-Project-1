using namespace std;
#include <iostream>
#include <iomanip>
#include <string>
#include "Clock.h"

int hours;
int minutes;
int seconds;
int choice;
string clock24;
string clock12;

void printClocks() {
	/* This function outputs the clocks in 24 hour and 12 hours format
	* uses two different functions within the function to grab the clocks
	* and adds a bit of styling format to them.
	*/
	cout << "24 Hour Clock  ";
	cout << "12 Hour Clock" << endl;
	clock24 = get24HourFormat(hours, minutes, seconds);
	cout << "  " << clock24 << "      ";
	clock12 = get12HourFormat(hours, minutes, seconds);
	cout << clock12 << endl;
	cout << endl;
}
void printMenu() {
	/* function to output the menu to get users input.
	*/
	cout << "Main Menu" << endl;
	cout << string(20,'*') << endl;
	cout << "1 - Add One Hour" << endl;
	cout << "2 - Add One Minute" << endl;
	cout << "3 - Add One Second" << endl;
	cout << "4 - Exit Program" << endl;
	cout << string(20, '*') << endl;
	
}

int main() {
	/*Begin the main program loop with the following while loop that checks for the user input,
	* and outputs an error message if the users input is out of range.
	* User has to redo input if outside of range.
	*/
	while (true) {
		cout << "Please enter the time: " << endl;
		cout << "Hours: ";
		cin >> hours;
		if (hours < 0 || hours > 24) {
			cout << "Error, number must be between 0 and 24" << endl;
			continue;
		}
		cout << "Minutes: ";
		cin >> minutes;
		if (minutes < 0 || minutes > 59) {
			cout << "Error, number must be between 0 and 59" << endl;
			continue;
		}
		cout << "Seconds: ";
		cin >> seconds;
		if (seconds < 0 || seconds > 59) {
			cout << "Error, number must be between 0 and 59" << endl;
			continue;
		}
		cout << endl;
		break;
	}
		
	/* The following while loop calls the printClocks() and printMenu() functions.
	* It then executes based on the users input from the menu.
	* If the users input is 4, it breaks out of the loop and ends the program.
	* Otherwise, the program calls one of the three increment functions based on the users input.
	*/
	while (choice != 4) {
		cout << endl;
		printClocks();
		printMenu();

		cout << "Choice: " << endl;
		cin >> choice;

		if (choice == 1) {
			addHour(hours);
		}
		if (choice == 2) {
			addMinute(minutes, hours);
		}
		if (choice == 3) {
			addSecond(seconds, minutes, hours);
		}
		
	}
	cout << "Good Bye"; // Good bye!

	return 0;
}
