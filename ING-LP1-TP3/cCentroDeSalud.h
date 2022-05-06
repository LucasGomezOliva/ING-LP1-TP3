#pragma once
#include<string>

using namespace std;
class cCentroDeSalud
{
private:
	string Nombre;
	string Direccion;
	string Partido;
	string Provincia;
	long int Telefono;
	//lista de vehiculos
public:
	cCentroDeSalud();
	cCentroDeSalud(string Nombre, string Direccion, string Partido, string Provincia, long int Telefono);
	~cCentroDeSalud();
};

