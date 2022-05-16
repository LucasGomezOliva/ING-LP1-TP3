#pragma once
#include"cVehiculo.h"
using namespace std;
class cHelicoptero:public cVehiculo
{
private:
public:
	cHelicoptero();
	cHelicoptero(string IDVehiculo);
	~cHelicoptero();
	void imprimir();
};

