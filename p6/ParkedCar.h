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

	void setMake(char* mk){
		for(int i=0;i<=16;i++)
		{make[i] = mk[i];}
	}

	void setModel(char* md){
		for(int i=0;i<=21;i++)
		{model[i] = md[i];}
	}

	void setColor(char* c){
		for(int i=0;i<=11;i++)
		{color[i] = c[i];}
	}

	void setLicenseNumber(char* l){
		for(int i=0;i<=7;i++)
		{licenseNumber[i] = l[i];}
	}

	void setMinutes(int m){
		minutes = m;
	}
	void setHours(int h){
		minutes = h;
	}

};


#endif	

