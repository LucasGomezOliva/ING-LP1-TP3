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
	int getDia() { return fecha.tm_mday; }
	int getMes() { return fecha.tm_mon; }
	int getAnio() { return fecha.tm_year; }
	int getHora() { return fecha.tm_hour; }
	int getMinutos() { return fecha.tm_min; }
	string to_stringFecha();
	void imprimir();
};

