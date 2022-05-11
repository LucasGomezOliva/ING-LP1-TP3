#pragma once
#include<string>
#include"cVehiculo.h"
using namespace std;
class cAmbulancia:public cVehiculo
{
private:
public:
	cAmbulancia();
	~cAmbulancia();
	void imprimir();
};

