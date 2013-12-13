#ifndef ParkedCar_H
#define ParkedCar_H
class ParkedCar
{
private:
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
	int getMinutes(){
		return minutes;
	}
	int getHours(){
		return minutes;
	}
	int getMetricTime(){
		return (hours*60)+minutes;
	}

	char* setMake()
};


#endif	

