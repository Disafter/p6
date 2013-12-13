#ifndef PoliceOfficer_H
#define PoliceOfficer_H

class PoliceOfficer
{
public://TESTING ONLY, REVERT TO PRIVATE
	char officerName[11];
	int officerBadgeNumber;
	int clockInHour;
	int clockInMinute;

public:
	PoliceOfficer();
	~PoliceOfficer();
	void CheckMeter();//not yet defined

	char* getOfficerName(){
		return officerName;
	}
	int getOfficerBadgeNumber(){
		return officerBadgeNumber;
	}
	int getClockInHour(){
		return clockInHour;
	}
	int getClockInMinute(){
		return clockInMinute;
	}
};

#endif

