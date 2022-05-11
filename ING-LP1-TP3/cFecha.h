#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <string>
using namespace std;
class cFecha
{
private:
	tm fecha;
public:
	cFecha();
	cFecha(int dia, int mes, int anio, int hora, int minutos);
	~cFecha();
	bool CompararFechas(cFecha* fecha);
	//Gets y sets
	int getDia() const { return fecha.tm_mday; }
	int getMes() const { return fecha.tm_mon; }
	int getAnio() const { return fecha.tm_year; }
	int getHora() const { return fecha.tm_hour; }
	int getMinutos() const { return fecha.tm_min; }
	//ToStrin e imprimr
	string to_stringFecha() const ;
	void imprimir() const ;
};

