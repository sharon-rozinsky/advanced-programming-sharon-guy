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
		dayCal->addMeeting(meeting);
	}
	void removeMeeting(Meeting_t<T>* meeting)
	{
		dayCal->removeMeeting(meeting);
	}
	void	find(Meeting_t<T>* meeting)
	{
		dayCal->findMeeting(meeting);
	}
	void	print()
	{
		dayCal->printCalendar();
	}
public:
	DayCalendar_t<T>* dayCal;
};