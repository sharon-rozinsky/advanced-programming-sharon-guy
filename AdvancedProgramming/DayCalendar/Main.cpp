#include <iostream>
#include "DayCalendar_t.h"
#include "Meeting_t.h"
#include "Test_t.h"
#include "ExtendedMeeting_t.h"



//==============================================================
Meeting_t<int>* getMeetingInt()
{
	string subject;
	int startTime;
	int endTime;

	cout << "Enter meeting details" << endl;
	cout << "subject: ";
	cin.get();
	std::getline(std::cin, subject);
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
	cin.get();
	std::getline(std::cin, subject);
	cout << "start time: ";
	cin >> startTime;
	cout << "end time: ";
	cin >> endTime;

	return new Meeting_t<float>(subject, startTime, endTime);
}

ExtendedMeeting_t<int>* getExtendedMeetingInt()
{
	string subject;
	string location;
	int startTime;
	int endTime;

	cout << "Enter meeting details" << endl;
	cout << "subject: ";
	cin.get();
	std::getline(std::cin, subject);
	cout << "start time: ";
	cin >> startTime;
	cout << "end time: ";
	cin >> endTime;
	cout << "location: ";
	cin.get();
	std::getline(std::cin, location);

	return new ExtendedMeeting_t<int>(subject, startTime, endTime, location);
}

ExtendedMeeting_t<float>* getExtendedMeetingFloat()
{
	string subject;
	string location;
	float startTime;
	float endTime;

	cout << "Enter meeting details" << endl;
	cout << "subject: ";
	cin.get();
	std::getline(std::cin, subject);
	cout << "start time: ";
	cin >> startTime;
	cout << "end time: ";
	cin >> endTime;
	cout << "location: ";
	cin.get();
	std::getline(std::cin, location);

	return new ExtendedMeeting_t<float>(subject, startTime, endTime, location);
}

int main() {
	bool cont = true;			// trigger to stop loop
	bool intCal = true;
	int calType = 0;
	string calName;

	cout << "Init day calendar, please choose calendar type.\n1. Integer.\n2. Float.\n";
	cin >> calType;
	cout << endl;
	cout << "Enter calendar name: " << endl;
	cin.get();
	std::getline(std::cin, calName);
	if (calType == 1)
	{
		Test_t<int>* test = new Test_t<int>(calName);
		while (cont) {
			unsigned int c;
			Meeting_t<int>* meetingInt;

			cout << "Enter your choice:" << endl
				<< "1 - add meeting" << endl
				<< "2 - add meeting with location" << endl
				<< "3 - find meeting" << endl
				<< "4 - remove meeting" << endl
				<< "5 - print calendar" << endl
				<< "0 - quit" << endl;
			cin >> c;

			switch (c) {
			case 1:
				test->addMeeting(getMeetingInt());
				break;
			case 2:
				test->addMeeting(getExtendedMeetingInt());
				break;
			case 3:
				test->find();
				break;
			case 4:
				test->removeMeeting();
				break;
			case 5:
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
		}
		delete test;

	}
	else
	{
		Test_t<float>* test = new Test_t<float>(calName);
		while (cont) {
			unsigned int c;
			Meeting_t<float>* meetingFloat;

			cout << "Enter your choice:" << endl
				<< "1 - add meeting" << endl
				<< "2 - add meeting with location" << endl
				<< "3 - find meeting" << endl
				<< "4 - remove meeting" << endl
				<< "5 - print calendar" << endl
				<< "0 - quit" << endl;
			cin >> c;

			switch (c) {
			case 1:
				test->addMeeting(getMeetingFloat());
				break;
			case 2:
				test->addMeeting(getExtendedMeetingFloat());
				break;
			case 3:
				test->find();
				break;
			case 4:
				test->removeMeeting();
				break;
			case 5:
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

		}
		delete test;
	}
	return 0;
}