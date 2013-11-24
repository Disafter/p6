#ifndef ParkedCar_H
#define ParkedCar_H
class ParkedCar
{
public: //*****SHOULD BE REVERTED TO PRIVATE AFTER TESTING
	int spotNumber;//REMOVE --> This belongs in the parking meter class, is here for testing ONLY.
	int paidTime;//REMOVE --> This belongs in the parking meter class, is here for testing ONLY.
	char make[16];
	char model[21];
	char color[11];
	char licenseNumber[7];
	//int parkingTime;//change to use more standard time variables
	int minutes;
	int hours;
	int metricTime;
public:
	ParkedCar();
	~ParkedCar();
};


#endif	

