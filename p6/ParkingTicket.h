#ifndef ParkingTicket_H
#define ParkingTicket_H

class ParkingTicket
{
	private: 
		char make[16];
		char model[21];
		char color[11];
		char licenseNumber[7];
		float fine;
		char officerName[11];
		int officerBadgeNumber;

public:
	ParkingTicket();
	~ParkingTicket();
	void PrintTicket();//not yet defined

	char* getMake(){
		return make;
	}
	char* getModel(){
		return model;
	}
	char* getColor(){
		return color;
	}
	char* getLicenseNumber(){
		return licenseNumber;
	}
	float getFine(){
		return fine;
	}
	char* getOfficerName(){
		return officerName;
	}
	int getOfficerBadgeNumber(){
		return officerBadgeNumber;
	}
};

#endif	
