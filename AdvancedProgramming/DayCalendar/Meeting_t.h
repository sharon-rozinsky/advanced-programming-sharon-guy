#include <string>
#include <vector>

using namespace std;

#ifndef MEETING_T_H_
#define MEETING_T_H_

template <class T>
class Meeting_t {
public:
	// Ctor's
	Meeting_t();
	Meeting_t(const string _subject,const T _startTime,const T _endTime) : subject(_subject), startTime(_startTime), endTime(_endTime){};

	// Accessors
	void setsubject(const string _subject)
	{
		subject = _subject;
	}
	string getsubject() const
	{
		return subject;
	}
	void setStartTime(const T _startTime)
	{
		startTime = _startTime;
	}
	T getStartTime() const
	{
		return startTime;
	}
	void setEndTime(const T _endTime)
	{
		endTime = _endTime;
	}
	T getEndTime() const
	{
		return endTime;
	}

	// Class Methods
	virtual void printMeeting()
	{
		cout << subject << ": " << startTime << " - " << endTime << endl;
	}

	// Operators
	bool operator < (const Meeting_t<T>& other) const
	{
		return (startTime < other.getStartTime());
	}
	bool operator <= (const Meeting_t<T>& other) const
	{
		return (startTime <= other.getStartTime());
	}
	bool operator > (const Meeting_t<T>& other) const
	{
		return (startTime > other.getStartTime());
	}
	bool operator >= (const Meeting_t<T>& other) const
	{
		return (startTime >= other.getStartTime());
	}

protected:
	string	subject;
	T		startTime;
	T		endTime;
};

#endif /* MEETING_T_H_ */
