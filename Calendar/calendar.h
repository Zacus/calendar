#pragma once
#pragma once

#ifndef CALENDAR_H
#define CALENDAR_H

#include<map>
using std::map;

//#include<boost/assign/list_of.hpp>
//using boost::assign::map_list_of;

typedef struct calendar {
	int year;
	int month;
	int daysofmonth;
	int firstdayofmonth;
	int leap;
}cal;
cal info;
//typedef struct calendar cal;
int input();
int output();
int estimate_input(const int year);  //judge whether the input meets the conditions             
int estimate_years(const int year);  //leap year or nonleap year ?
int first_day(const int year);
int  isContinueSearch();      //Whether to continue to check other year's calendar
//void enum2String(const int mon);
void print();
void printmonth(cal info);   //print month
void enum2String(cal info);  //Converts the month enumeration type to a string type
cal init(const int year);   //initialization
cal setmonthinfo(cal info);  //Create a monthly message
//void FebMonth(const int year);           
enum month {
	Jan,
	Feb,
	Mar,
	Apr,
	May,
	Jun,
	Jul,
	Aug,
	Sept,
	Oct,
	Nov,
	Dec
};
/**********************need boost library in linux or windows*********************/

//map<int,/*string*/const char *> month2String=map_list_of
/*    (Jan,"一月")
	(Feb,"二月")
	(Mar,"三月")
	(Apr,"四月")
	(May,"五月")
	(Jun,"六月")
	(Jul,"七月")
	(Aug,"八月")
	(Sept,"九月")
	(Oct,"十月")
	(Nov,"十一月")
	(Dec,"十二月")
;*/









#endif