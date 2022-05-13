#pragma once
#include"cPaciente.h"
#include"cListaOrganos.h"
//#include "cListaTemplate.h"

using namespace std;
class cDonante:public cPaciente
{
public:
	cFecha* FechaFalleciemiento = NULL;
	cFecha* FechaComienzoAbleacion = NULL;
	//Lista de organos -- Revisar --
	cListaOrganos* ListaDeOrganosDonante = NULL;

private:
	cDonante();
	cDonante(string Nombre, string NumeroTelefono, eTipoDeSangre Sangre, int DiaNacimiento, int MesNacimiento, int AnioNacimiento, int HoraNacimiento, int MinutosNacimiento);
	~cDonante();
	//Gets y sets
	void SetFallecimiento(int DiaFallecimient, int MesFallecimient, int AnioFallecimient, int HoraFallecimient, int MinutosFallecimient);
	void SetFechaComienzoAbleacion(int DiaComienzoAbleacion, int MesComienzoAbleacion, int AnioComienzoAbleacion, int HoraComienzoAbleacion, int MinutosComienzoAbleacion);
	//ToStrin e imprimr
	string ToStringDonante() const;
	void imprimir();
	//Sobrecarga de operadores
	friend ostream& operator<<(ostream& os, const cDonante* donante);

};

