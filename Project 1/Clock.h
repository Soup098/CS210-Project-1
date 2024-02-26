#ifndef ADD_H_INCLUDED
#define ADD_H_INCLUDED
#include <string>



void addHour(int& hr);
void addMinute(int& min, int& hr);
void addSecond(int& sec, int& min, int& hr);
std::string get12HourFormat(int hrs, int min, int sec);
std::string get24HourFormat(int hrs, int min, int sec);


#endif