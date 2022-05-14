#pragma once
#include<string>
#include<iostream>
#include"cListaVehiculos.h"

using namespace std;
class cCentroDeSalud
{
private:
	string Nombre;
	string Direccion;
	string Partido;
	string Provincia;
	long int Telefono;
	cListaVehiculos* ListaDeVehiculosDisponibles = NULL;
public:
	cCentroDeSalud();
	cCentroDeSalud(string Nombre, string Direccion, string Partido, string Provincia, long int Telefono);
	~cCentroDeSalud();
	void AsignarVehiculo();
	void RealizarAblacion();
	void RealizarTransplante();
	string ToStringCentroDeSalud() const;
	void imprimir() const;
	//Sobrecarga de operadores
	friend ostream& operator<<(ostream& os, const cCentroDeSalud* CentroDeSalud);
};

