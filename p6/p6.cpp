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

int _tmain(int argc, _TCHAR* argv[])
{

	ifstream inputFile("Parking.txt");
	

	/*if(operation[0]=='e' && operation[1]=='n'){
	ParkedCar carObject = enterCar();
	cout<<"SPOT NUMBER: "<<carObject.spotNumber<<endl<<"HOURS: "<<carObject.hours<<endl;
	cout<<"MINUTES: "<<carObject.minutes<<endl<<"MAKE: "<<carObject.make<<endl<<"MODEL: "<<carObject.model<<endl;
	cout<<"LICENSE NUMBER: "<<carObject.licenseNumber<<endl<<"PAID TIME: "<<carObject.paidTime<<endl;
	}*/
	/*ParkedCar carObject;
	inputFile>>operation;
	inputFile>>carObject.spotNumber;
	inputFile>>carObject.hours;
	inputFile.ignore(1,':');
	inputFile>>carObject.minutes;
	inputFile>>carObject.make;
	inputFile>>carObject.model;
	inputFile>>carObject.licenseNumber;
	inputFile>>carObject.paidTime;*/

	//carObject.metricTime = (carObject.hours * 60) + carObject.minutes;

	/*cout<<"SPOT NUMBER: "<<carObject.spotNumber<<endl<<"TIME: "<<carObject.hours<<":"<<carObject.minutes<<endl;
	cout<<"METRIC TIME: "<<carObject.metricTime<<endl;
	cout<<"MAKE: "<<carObject.make<<endl<<"MODEL: "<<carObject.model<<endl;
	cout<<"LICENSE NUMBER: "<<carObject.licenseNumber<<endl<<"PAID TIME: "<<carObject.paidTime<<endl;
	*/
	







	system("pause");
	return 0;
}

/*ParkedCar enterCar(){
ParkedCar newCar;
ifstream inputFile("Parking.txt");
inputFile>>newCar.spotNumber;
inputFile>>newCar.hours;
inputFile.ignore(1,':');
inputFile>>newCar.minutes;
inputFile>>newCar.make;
inputFile>>newCar.model;
inputFile>>newCar.licenseNumber;
inputFile>>newCar.paidTime;
inputFile.close;
return newCar;

}
*/


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