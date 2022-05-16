#pragma once
#include<string>
#include"cVehiculo.h"
using namespace std;
class cAvion :public cVehiculo
{
private:
public:
	cAvion();
	cAvion(string IDVehiculo);
	~cAvion();
	void imprimir();
};

