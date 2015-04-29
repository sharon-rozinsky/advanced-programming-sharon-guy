#include <string>
#include <vector>
#include "Meeting_t.h"

using namespace std;

#ifndef EXTENDED_MEETING_T_H_
#define EXTENDED_MEETING_T_H_

template <class T>
class ExtendedMeeting_t : public Meeting_t<T>{
public:
	// Ctor's
	ExtendedMeeting_t();
	ExtendedMeeting_t(const string _subject,const T _startTime,const T _endTime, const string _location) : Meeting_t(_subject, _startTime, _endTime), location(_location) {};
	virtual ~ExtendedMeeting_t(){}

	// Accessors
	void setLocation(const string _location)
	{
		location = _location;
	}
	string getLocation() const
	{
		return location;
	}

	// Class Methods
	virtual void printMeeting()
	{
		cout << subject << ": " << startTime << " - " << endTime << "; Meeting location: " << location << endl;
	}

	// Operators

private:
	string location;
};

#endif /* EXTENDED_MEETING_T_H_ */
