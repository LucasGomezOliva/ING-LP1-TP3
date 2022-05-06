#pragma once
#include<string>
#include "cFecha.h"
#include"TipoDeSangre.h"
#include"Sexo.h"
using namespace std;
class cPaciente
{
protected:
	string Nombre;
	cFecha* FechaNacimeinto = NULL;
	Sexo SexoPaciente;
	string NumeroTelefono;
	TipoDeSangre Sangre;
	//Puntero centro de salud

public:
	cPaciente();
	cPaciente(string Nombre, string NumeroTelefono,TipoDeSangre Sangre, cFecha* FechaNaciemiento);
	virtual ~cPaciente();
};

