#pragma once
#include<iostream>
#include"cOrgano.h"
using namespace std;
class cVehiculo
{
private:
	cOrgano* Organo = NULL;
public:
	cVehiculo();
	~cVehiculo();
	void RecibirOrgano(cOrgano* Organo);
	cOrgano* EntregarOrgano();
	virtual void imprimir() = 0;
};

