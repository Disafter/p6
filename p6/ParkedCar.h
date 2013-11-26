#ifndef ParkedCar_H
#define ParkedCar_H
class ParkedCar
{
public: //*****SHOULD BE REVERTED TO PRIVATE AFTER TESTING
	
	char make[16];
	char model[21];
	char color[11];
	char licenseNumber[7];
	int minutes;
	int hours;
	int metricTime;
public:
	ParkedCar();
	~ParkedCar();
};


#endif	

