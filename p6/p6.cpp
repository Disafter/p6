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
char tempString[

void enterCar();

int _tmain(int argc, _TCHAR* argv[])
{

	ifstream inputFile("Parking.txt");
	ofstream outputFile("Parking.dat");

	while(!inputFile.eof()){
		inputFile>>operation;
		if(operation[0]=='e' && operation[1]=='n'){
			inputFile>>spotTemp;
			Meters[spotTemp].spotNumber = spotTemp;
			//inputFile<<Meters[spotTemp].car.getHours();
			inputFile.ignore(1,':');
			inputFile>>Meters[spotTemp].car.getMinutes();
			Meters[spotTemp].car.getMetricTime = (Meters[spotTemp].car.getHours() * 60) + Meters[spotTemp].car.getMinutes();
			inputFile>>Meters[spotTemp].car.getMake();
			inputFile>>Meters[spotTemp].car.getModel();
			inputFile>>Meters[spotTemp].car.getColor();
			inputFile>>Meters[spotTemp].car.getLicenseNumber();
			inputFile>>Meters[spotTemp].getPaidTime();
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
				outputFile<<"Model: "<<Meters[spotTemp].car.getModel<<endl;
				outputFile<<"Color: "<<Meters[spotTemp].car.getColor<<endl;
				outputFile<<"License Number: "<<Meters[spotTemp].car.getLicenseNumber<<endl;
				outputFile<<"Fine: ";

				fine = (timeUsed - Meters[spotTemp].paidTime) / 60;
				fine = 25 + (10 * fine);
				outputFile<<fine<<endl;

				outputFile<<"Officer: "<<officerOnDuty.getOfficerName()<<endl;
				outputFile<<"Badge Number: "<<officerOnDuty.getOfficerBadgeNumber()<<endl<<endl;
			}
		}
		else if(operation[0] == 'i'){
			inputFile>>officerOnDuty.getOfficerName();
			inputFile>>officerOnDuty.getOfficerBadgeNumber();
			inputFile>>officerOnDuty.getClockInHour();
			inputFile.ignore(1,':');
			inputFile>>officerOnDuty.getClockInMinute;
		}
	}









	//system("pause");
	return 0;
}

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

}