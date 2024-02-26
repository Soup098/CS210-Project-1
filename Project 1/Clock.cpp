#include <iostream>
#include "Clock.h"
using namespace std;

void addHour(int& hr)
// function to increment the time of both clocks by 1 hour
{
	hr = hr + 1;
	if (hr > 23) {
		hr = 0;
	}
}

void addMinute(int& min, int& hr)
/*function to increment the time of both clocks by 1 minute
* The function has minutes and hours as a paramater, so that add hour can be used in the if statement
*/ 
{
	min = min + 1;
	if (min > 59) {
		min = 0;
		addHour(hr); // The if statment calls the addHour() function if the users input rolls the minutes over.
	}
}

void addSecond(int& sec, int& min , int& hr)
/*function to increment the time of both clocks by 1 second.
* the function has second, minutes and hours as paramaters, so that minutes and hours can be used in if statment.
*/
{
	sec = sec + 1;
	if (sec > 59) {
		sec = 0;
		addMinute(min, hr);//If statement calls addMinute() function if the users input rolls the seconds over.
	}
	
}



std::string get24HourFormat(int hrs, int min, int sec)
{
	std::string clock24Output;
	// This function uses if statments to gather the hours, minutes and seconds, then concantanates them into a string in 24 hour clock format.
	if (hrs < 10) {
		clock24Output += "0";
	}
	clock24Output += std::to_string(hrs) + ":";

	if (min < 10) {
		clock24Output += "0";
	}
	clock24Output += std::to_string(min) + ":";
	if (sec < 10) {
		clock24Output += "0";
	}
	clock24Output += std::to_string(sec);


	return clock24Output;
}

std::string get12HourFormat(int hrs, int min, int sec)
// This function uses if statements to gather the hours, minutes and seconds, then concantanates them into a string in 12 hour clock format.
{
	string amOrPm;//local variables declared.
	std::string clock12Output;
	// if statements that switches variable string between AM and PM based on hours.
	if (hrs <= 11) {
		amOrPm = " AM";
	}
	else {
		amOrPm = " PM";
	}

	// if statement that ensures that hours being displayed are always in 1-12 range.
	if (hrs < 1) {
		hrs = 12;
	}
	else if (hrs > 12) {
		hrs = hrs - 12;
	}

	// if statements that concantanates hours, minutes and seconds into the 12 hour format
	if (hrs < 10) {
		clock12Output += "0";
	}
	clock12Output += std::to_string(hrs) + ":";
	
	if (min < 10) {
		clock12Output += "0";
	}
	clock12Output += std::to_string(min) + ":";
	if (sec < 10) {
		clock12Output += "0";
	}
	clock12Output += std::to_string(sec) + amOrPm;


	return clock12Output;
}

