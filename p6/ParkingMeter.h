#ifndef ParkingMeter_H
#define ParkingMeter_H
#include "ParkedCar.h"
class ParkingMeter
{
	
public: //REVERT TO PRIVATE AFTER TESTING
	ParkedCar car;
	int spotNumber;
	int paidTime;
	
public:
	ParkingMeter();
	~ParkingMeter();
};

#endif	
