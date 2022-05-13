#pragma once
#include<string>
#include "cFecha.h"
#include"cCentroDeSalud.h"
#include"cOrgano.h"
#include"Enums.h"
using namespace std;
class cPaciente
{
protected:
	string Nombre;
	cFecha* FechaNacimeinto = NULL;
	eSexo SexoPaciente;
	string NumeroTelefono;
	eTipoDeSangre Sangre;
	cCentroDeSalud* CentroDeSalud = NULL;
public:
	cPaciente();
	cPaciente(string Nombre, string NumeroTelefono, eTipoDeSangre Sangre, int DiaNacimeinto, int MesNacimeinto, int AnioNacimeinto, int HoraNacimeinto, int MinutosNacimeinto);
	virtual ~cPaciente();
	void SetCentroDeSalud(cCentroDeSalud* CentroDeSalud);
	string ToStringPaciente()const;
	virtual void imprimir() = 0 ;
};

