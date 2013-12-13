// p6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "PoliceOfficer.h"
#include "ParkingTicket.h"
using std::ifstream; 
using namespace std;

PoliceOfficer officerOnDuty;
ParkingMeter Meters[10];
char operation[6];
int spotTemp;
int exitHour;
int exitMinute;
int exitMetricTime;
int timeUsed;
int fine;
char tempString[20];
int tempInt;

//void enterCar();

int _tmain(int argc, _TCHAR* argv[])
{

	ifstream inputFile("Parking.dat");
	ofstream outputFile("tickets.txt");

	while(!inputFile.eof()){
		inputFile>>operation;
		if(operation[0]=='e' && operation[1]=='n'){
			inputFile>>spotTemp;
			Meters[spotTemp].spotNumber = spotTemp;
			inputFile>>tempInt;
			Meters[spotTemp].car.setHours(tempInt);
			inputFile.ignore(1,':');
			inputFile>>tempInt;
			Meters[spotTemp].car.setMinutes(tempInt);
			inputFile>>tempString;
			Meters[spotTemp].car.setMake(tempString);
			inputFile>>tempString;
			Meters[spotTemp].car.setModel(tempString);
			inputFile>>tempString;
			Meters[spotTemp].car.setColor(tempString);
			inputFile>>tempString;
			Meters[spotTemp].car.setLicenseNumber(tempString);
			inputFile>>tempInt;
			Meters[spotTemp].setPaidTime(tempInt);
		}
		else if(operation[0]=='e' && operation[1]=='x'){
			inputFile>>spotTemp;
			inputFile>>exitHour;
			inputFile.ignore(1,':');
			inputFile>>exitMinute;
			exitMetricTime = (exitHour*60) + exitMinute;
			if(exitMetricTime < Meters[spotTemp].car.getMetricTime()){
				exitMetricTime += (60*24);
			}
			timeUsed = exitMetricTime -  Meters[spotTemp].car.getMetricTime();
			if(timeUsed > Meters[spotTemp].getPaidTime()){
				outputFile<<"Make: "<<Meters[spotTemp].car.getMake()<<endl;
				outputFile<<"Model: "<<Meters[spotTemp].car.getModel()<<endl;
				outputFile<<"Color: "<<Meters[spotTemp].car.getColor()<<endl;
				outputFile<<"License Number: "<<Meters[spotTemp].car.getLicenseNumber()<<endl;
				outputFile<<"Fine: ";

				fine = (timeUsed - Meters[spotTemp].paidTime) / 60;
				fine = 25 + (10 * fine);
				outputFile<<fine<<endl;

				outputFile<<"Officer: "<<officerOnDuty.getOfficerName()<<endl;
				outputFile<<"Badge Number: "<<officerOnDuty.getOfficerBadgeNumber()<<endl<<endl;
			}
		}
		else if(operation[0] == 'i'){
			inputFile>>tempString;
			officerOnDuty.setOfficerName(tempString);
			inputFile>>tempInt;
			officerOnDuty.setOfficerBadgeNumber(tempInt);
			inputFile>>tempInt;
			officerOnDuty.setClockInHour(tempInt);
			inputFile.ignore(1,':');
			inputFile>>tempInt;
			officerOnDuty.setClockInMinute(tempInt);
		}
	}









	return 0;
}

/*

void enterCar(){
ifstream inputFile("Parking.txt");
inputFile>>spotTemp;
Meters[spotTemp].spotNumber = spotTemp;
inputFile>>Meters[spotTemp].car.hours;
inputFile.ignore(1,':');
inputFile>>Meters[spotTemp].car.minutes;
Meters[spotTemp].car.metricTime = (Meters[spotTemp].car.hours * 60) + Meters[spotTemp].car.minutes;
inputFile>>Meters[spotTemp].car.make;
inputFile>>Meters[spotTemp].car.model;
inputFile>>Meters[spotTemp].car.licenseNumber;
inputFile>>Meters[spotTemp].paidTime;
inputFile.close();

}*/