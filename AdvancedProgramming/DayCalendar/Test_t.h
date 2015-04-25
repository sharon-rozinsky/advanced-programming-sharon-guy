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
		dayCal = new DayCalendar_t(name);
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
		}
	}
	void removeMeeting(Meeting_t<T>* meeting)
	{
		dayCal->removeMeeting(meeting);
	}
	void	find(Meeting_t<T>* meeting)
	{
		Meeting_t<T>* foundMeeting;
		foundMeeting = dayCal->findMeeting(meeting);
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
	void	print()
	{
		dayCal->printCalendar();
	}
public:
	DayCalendar_t<T>* dayCal;
};