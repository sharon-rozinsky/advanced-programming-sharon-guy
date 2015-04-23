#include <iostream>
#include <stdio.h>
#include "DayCalendar_t.h"
#include "Meeting_t.h"
using namespace std;


int main() {
	Meeting_t<int>* meeting = new Meeting_t<int>("meeting1", 5, 6);
	Meeting_t<int>* meeting2 = new Meeting_t<int>("meeting2", 3, 4);
	Meeting_t<int>* meeting3 = new Meeting_t<int>("meeting3", 10, 12);
	Meeting_t<int>* meeting4 = new Meeting_t<int>("meeting4", 1, 2);
	DayCalendar_t<int> *cal = new DayCalendar_t<int>("cal");
	cal->addMeeting(meeting);
	cal->addMeeting(meeting2);
	cal->addMeeting(meeting3);
	cal->addMeeting(meeting4);
	cal->printCalendar();
	cal->findMeeting(5);
	cal->removeMeeting(5);
	cal->printCalendar();
	cal->removeMeeting(5);
	cal->printCalendar();
	getchar();
	return 0;
}