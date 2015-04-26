#include <string>
#include <ostream>
#include "DayCalendar_t.h"
#include "Meeting_t.h"
using namespace std;

template <class T>
class Test_t {
public:
	Test_t();
	Test_t(const string name)
	{
		dayCal = new DayCalendar_t<T>(name);
	}
	~Test_t()
	{
		delete dayCal;
	}

	void addMeeting(Meeting_t<T>* meeting)
	{
		try{
			dayCal->addMeeting(meeting);
			cout << "Meeting added successfully" << endl;
		}
		catch (const string exceptionMsg)
		{
			cout << exceptionMsg << endl;
			delete meeting;
		}
	}
	void removeMeeting()
	{
		T startTime;
		cout << "Please enter the start time of the meeting you want to remove: " << endl;
		cin >> startTime;
		dayCal->removeMeeting(startTime);
	}
	void find()
	{
		T startTime;
		Meeting_t<T>* foundMeeting;

		cout << "Please enter the start time of the meeting you want to find: " << endl;
		cin >> startTime;
		foundMeeting = dayCal->findMeeting(startTime);
		if (foundMeeting)
		{
			cout << "Meeting found:" << endl;
			foundMeeting->printMeeting();
		}
		else
		{
			cout << "Meeting not found" << endl;
		}
	}
	void updatedMeetingLocation()
	{
		try{
			T startTime;
			string location;
			cout << "Please enter the start time of the meeting you want to update: " << endl;
			cin >> startTime;
			cout << "Please enter the new location: " << endl;
			cin.get();
			std::getline(std::cin, location);
			dayCal->addMeetingLocation(startTime, location);
		}
		catch (const string exceptionMsg)
		{
			cout << exceptionMsg << endl;
		}
	}
	void	print()
	{
		dayCal->printCalendar();
	}
public:
	DayCalendar_t<T>* dayCal;
};