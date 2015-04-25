#include <iostream>
#include "DayCalendar_t.h"
#include "Meeting_t.h"
#include "Test_t.h"
using namespace std;


//==============================================================
Meeting_t<int>* getMeetingInt()
{
	string subject;
	int startTime;
	int endTime;

	cout << "Enter meeting details" << endl;
	cout << "subject: ";
	cin >> subject;
	cout << "start time: ";
	cin >> startTime;
	cout << "end time: ";
	cin >> endTime;

	return new Meeting_t<int>(subject, startTime, endTime);
}

Meeting_t<float>* getMeetingFloat()
{
	string subject;
	float startTime;
	float endTime;

	cout << "Enter meeting details" << endl;
	cout << "subject: ";
	cin >> subject;
	cout << "start time: ";
	cin >> startTime;
	cout << "end time: ";
	cin >> endTime;

	return new Meeting_t<float>(subject, startTime, endTime);
}


int main() {
	bool cont = true;			// trigger to stop loop
	bool intCal = true;
	int calType = 0;
	
	string calName;
	cout << "Init day calendar, please choose calendar type.\n1. Integer.\n2.float.\n";
	cin >> calType;
	cout << endl;
	cout << "Enter calendar name: " << endl;
	cin >> calName;

	if (calType == 1)
	{
		Test_t<int>* test = new Test_t<int>(calName);
		while (cont) {
			unsigned int c;
			Meeting_t<int>* meetingInt;
			Meeting_t<float>* meetingFloat;
			int index;

			cout << "Enter your choice:" << endl
				<< "1 - add meeting" << endl
				<< "2 - find meeting" << endl
				<< "3 - remove meeting" << endl
				<< "4 - print calendar" << endl
				<< "0 - quit" << endl;
			cin >> c;

			switch (c) {
			case 1:
				test->addMeeting(getMeetingInt());
				break;
			case 2:
				meetingInt = getMeetingInt();
				test->find(meetingInt);
				delete meetingInt;
				break;
			case 3:
				meetingInt = getMeetingInt();
				test->removeMeeting(meetingInt);
				delete meetingInt;
				break;
			case 4:
				test->print();
				break;
			case 0:
				cont = false;
				break;
			default:
				cont = false;
				break;
			}

			cout << "----------------------------------------------" << endl;

			delete test;
		}
	}
	else
	{
		Test_t<float>* test = new Test_t<float>(calName);
		while (cont) {
			unsigned int c;
			Meeting_t<int>* meetingInt;
			Meeting_t<float>* meetingFloat;
			int index;

			cout << "Enter your choice:" << endl
				<< "1 - add meeting" << endl
				<< "2 - find meeting" << endl
				<< "3 - remove meeting" << endl
				<< "4 - print calendar" << endl
				<< "0 - quit" << endl;
			cin >> c;

			switch (c) {
			case 1:
				test->addMeeting(getMeetingFloat());
				break;
			case 2:
				meetingFloat = getMeetingFloat();
				test->find(meetingFloat);
				delete meetingFloat;
				break;
			case 3:
				meetingFloat = getMeetingFloat();
				test->removeMeeting(meetingFloat);
				delete meetingFloat;
				break;
			case 4:
				test->print();
				break;
			case 0:
				cont = false;
				break;
			default:
				cont = false;
				break;
			}

			cout << "----------------------------------------------" << endl;

			delete test;
		}
	}

	

	return 0;
}