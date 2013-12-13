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

	int getSpotNumber(){
		return spotNumber;}
	int getPaidTime(){
		return paidTime;}
	void setSpotNumber(int s){
		spotNumber = s;}
	void setPaidTime(int p){
		paidTime = p;}

};

#endif	
