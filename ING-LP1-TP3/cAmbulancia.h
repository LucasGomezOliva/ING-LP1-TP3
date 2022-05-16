#pragma once
#include<string>
#include"cVehiculo.h"
using namespace std;
class cAmbulancia:public cVehiculo
{
private:
public:
	//cVehiculo(string IDVehiculo)
	cAmbulancia();
	cAmbulancia(string IDVehiculo);
	~cAmbulancia();
	void imprimir();
};

