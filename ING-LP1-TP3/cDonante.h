#pragma once
#include"cPaciente.h"
#include "cReceptor.h"
#include"cListaOrganos.h"
//#include "cListaTemplate.h"
//#include"cListaTemplate2.h"

using namespace std;
class cDonante:public cPaciente
{
protected:

	cFecha* FechaFalleciemiento = NULL;
	cFecha* FechaComienzoAbleacion = NULL;
	cListaOrganos* ListaDeOrganosDonante = NULL;
	
public:
	cDonante();
	cDonante(string Nombre, string NumeroTelefono, eTipoDeSangre Sangre, int DiaNacimiento, int MesNacimiento, int AnioNacimiento, int HoraNacimiento, int MinutosNacimiento,cCentroDeSalud* CentroDeSalud, int DiaFallecimient, int MesFallecimient, int AnioFallecimient, int HoraFallecimient, int MinutosFallecimient);
	~cDonante();
	//Sets
	void SetFallecimiento(int DiaFallecimient, int MesFallecimient, int AnioFallecimient, int HoraFallecimient, int MinutosFallecimient);
	void SetFechaComienzoAbleacion(int DiaComienzoAbleacion, int MesComienzoAbleacion, int AnioComienzoAbleacion, int HoraComienzoAbleacion, int MinutosComienzoAbleacion);
	//Gets
	cOrgano* GetOrgano(unsigned int NumeroDeOrgano) const ;
	unsigned int GetCantidadOrganos() const;
	//ToStrin e imprimr
	string ToStringDonante() const;
	void imprimir();
	//Sobrecarga de operadores
	friend ostream& operator<<(ostream& os, const cDonante* donante);

	cOrgano* QuitarOrgano(unsigned int NumeroDeOrgano);
	cOrgano* QuitarOrgano(eTipoDeOrgano TipoDeOrgano);

	bool operator==(const cDonante& Donante);
	bool operator==(cReceptor& Receptor);

};

