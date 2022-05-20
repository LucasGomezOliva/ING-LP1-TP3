#pragma once
#include<iostream>
#include"cOrgano.h"
using namespace std;
class cVehiculo
{
private:
	string IDVehiculo;
	cOrgano* Organo = NULL;
public:
	cVehiculo();
	cVehiculo(string IDVehiculo);
	~cVehiculo();
	cOrgano* GetOrgano();
	void RecibirOrgano(cOrgano* Organo);
	cOrgano* EntregarOrgano();
	virtual void imprimir() = 0;
	bool operator==(const cVehiculo& OtroVehiculo);
};

