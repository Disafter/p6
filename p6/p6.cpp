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

void enterCar();

int _tmain(int argc, _TCHAR* argv[])
{

	ifstream inputFile("Parking.txt");
	
	for(int i=0;i<2;i++){
	inputFile>>operation;
	if(operation[0]=='e' && operation[1]=='n'){
		//enterCar();
		inputFile>>spotTemp;
		cout<<"A car enters spot #"<<spotTemp<<"."<<endl;
		Meters[spotTemp].spotNumber = spotTemp;
		inputFile>>Meters[spotTemp].car.hours;
		inputFile.ignore(1,':');
		inputFile>>Meters[spotTemp].car.minutes;
		Meters[spotTemp].car.metricTime = (Meters[spotTemp].car.hours * 60) + Meters[spotTemp].car.minutes;
		inputFile>>Meters[spotTemp].car.make;
		inputFile>>Meters[spotTemp].car.model;
		inputFile>>Meters[spotTemp].car.licenseNumber;
		inputFile>>Meters[spotTemp].paidTime;
	}
	else if(operation[0]=='e' && operation[1]=='x'){
		inputFile>>spotTemp;
		cout<<"The car in spot #"<<spotTemp<<" exits."<<endl;
		inputFile>>exitHour;
		inputFile.ignore(1,':');
		inputFile>>exitMinute;
		exitMetricTime = (exitHour*60) + exitMinute;
		if(exitMetricTime < Meters[spotTemp].car.metricTime){
			exitMetricTime += (60*24);
		}
		timeUsed =exitMetricTime -  Meters[spotTemp].car.metricTime;
		if(timeUsed > Meters[spotTemp].paidTime){
			cout<<"The car in spot #"<<spotTemp<<" incurred a fine while leaving."<<endl;
			cout<<"It paid for "<<Meters[spotTemp].paidTime<<" minutes and stayed for "<<timeUsed<<" minutes."<<endl;
		}
	}
	}

	/*cout<<"SPOT NUMBER: "<<carObject.spotNumber<<endl<<"TIME: "<<carObject.hours<<":"<<carObject.minutes<<endl;
	cout<<"METRIC TIME: "<<carObject.metricTime<<endl;
	cout<<"MAKE: "<<carObject.make<<endl<<"MODEL: "<<carObject.model<<endl;
	cout<<"LICENSE NUMBER: "<<carObject.licenseNumber<<endl<<"PAID TIME: "<<carObject.paidTime<<endl;
	*/








	system("pause");
	return 0;
}

void enterCar(){
	ifstream inputFile("Parking.txt");
	cout<<"A car enters the parking lot."<<endl;
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



/*
Get First Word of File, compare and determine what operation needs to be performed
If "Enter" { create a parked car object and fill it with the rest of the data from the line }
If "Exit"{
check to see if the car exceeded it's payed time, and if so generate a parking ticket object
Then destroy the parked car object that exited
}
If "In" {
create a police officer object and fill it with the rest of the data from the line
}
If "Out" {
destroy the police officer object that clocked out
}
*/