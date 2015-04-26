#include <string>
#include <vector>
#include <algorithm>
#include "Meeting_t.h"

using namespace std;

#ifndef DAYCALENDAR_T_H_
#define DAYCALENDAR_T_H_

template <class T>
class DayCalendar_t {
public:
	// Ctor's
	DayCalendar_t();
	DayCalendar_t(const string name) : name(name){}
	~DayCalendar_t()
	{
		Meeting_t<T>* meeting;
		typename std::vector<Meeting_t<T>*>::iterator iterator;
		for (iterator = meetings.begin(); iterator < meetings.end(); iterator++)
		{
			meeting = *iterator;
			delete meeting;
		}
	}

	// Accessors
	void setName(const string name)
	{
		this->name = name;
	}
	string getName() const
	{
		return name;
	}

	// Class Methods
	void printCalendar()
	{
		Meeting_t<T>* meeting;
		typename std::vector<Meeting_t<T>*>::iterator iterator;

		cout << "Calendar: " << name << endl;
		cout << "--------------------" << endl;
		for (iterator = meetings.begin(); iterator < meetings.end(); iterator++)
		{
			meeting = *iterator;
			meeting->printMeeting();
		}
		cout << endl;
	}
	void addMeeting(Meeting_t<T>* meeting)
	{
		if (isOverlapping(*meeting))
		{
			string tmp = "The meeting overlaps another meeting, please set a different time";
			throw(tmp);
		}
		else
		{
			meetings.push_back(meeting);
			sort(meetings.begin(), meetings.end(), PointerCompare());
		}
	}
	void removeMeeting(T startTime)
	{
		bool deleteMeeting = false;
		typename std::vector<Meeting_t<T>*>::iterator iterator, meetingToDelete;

		for (iterator = meetings.begin(); iterator < meetings.end(); iterator++)
		{
			Meeting_t<T>* meeting = *iterator;
			if (meeting->getStartTime() == startTime)
			{
				deleteMeeting = true;
				meetingToDelete = iterator;
			}
		}

		if (deleteMeeting)
		{
			meetings.erase(meetingToDelete);
		}
	}
	Meeting_t<T>* findMeeting(T startTime)
	{
		for (int i = 0; i < meetings.size(); i++)
		{
			Meeting_t<T>* meeting = meetings.at(i);
			if (meeting->getStartTime() == startTime)
				return meeting;
		}
		// TODO: replace with throw exception
		return NULL;
	}
	void addMeetingLocation(T startTime, string meetingLocation)
	{
		Meeting_t<T>* meeting = findMeeting(startTime);
		ExtendedMeeting_t<T>* meetingWithLocation;
		if (meeting != NULL)
		{
			meetingWithLocation = new ExtendedMeeting_t<T>(meeting->getsubject(), meeting->getStartTime(), meeting->getEndTime(), meetingLocation);
			removeMeeting(startTime);
			addMeeting(meetingWithLocation);
		}
		else
		{
			string tmp = "No meeting found for the specified start time";
			throw(tmp);
		}
	}

	// Operators
	struct PointerCompare {
		bool operator()(const Meeting_t<T>* l, const Meeting_t<T>* r) {
			return *l < *r;
		}
	};

private:
	string name; //Owner or company name
	vector<Meeting_t<T>*> meetings;
	
	bool isOverlapping(const Meeting_t<T> meeting)
	{
		typename std::vector<Meeting_t<T>*>::iterator iterator;

		for (iterator = meetings.begin(); iterator < meetings.end(); iterator++)
		{
			Meeting_t<T>* curMeeting = *iterator;
			if ((meeting.getStartTime() >= curMeeting->getStartTime() && meeting.getStartTime() < curMeeting->getEndTime()) ||
				(meeting.getEndTime() > curMeeting->getStartTime() && meeting.getEndTime() <= curMeeting->getEndTime()) ||
				(meeting.getStartTime() < curMeeting->getStartTime() && meeting.getEndTime() > curMeeting->getEndTime()))
				return true;
		}
		return false;
	}
};


#endif /* DAYCALENDAR_T_H_ */
