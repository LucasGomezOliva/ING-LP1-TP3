#pragma once
#include"cPaciente.h"
//#include"ePrioridad.h"
//#include"eEstadoReceptor.h"
#include"Enums.h"
using namespace std;
class cReceptor :public cPaciente
{
public:
	cOrgano* OrganoRecibir = NULL;
	cFecha* FechaListaEspera = NULL;
	ePrioridad PrioridadReceptor;
	string Patologia;
	eEstadoReceptor Estado;
private:
	cReceptor();
	cReceptor(string Nombre, string NumeroTelefono, eTipoDeSangre Sangre, int DiaNacimiento, int MesNacimiento, int AnioNacimiento, int HoraNacimiento, int MinutosNacimiento, int DiaListaEspera, int MesListaEspera, int AnioListaEspera, int HoraListaEspera, int MinutosListaEspera, ePrioridad Prioridad, string Patologia, eEstadoReceptor Estado);
	~cReceptor();
	//gets y sets
	void SetEstado(eEstadoReceptor NuevoEstado);
	void SetPrioridad(ePrioridad NuevaPrioridad);
	//ToString e imprimir
	string ToStringReceptor() const;
	void imprimir();
	//Sobrecarga de operadores
	friend ostream& operator<<(ostream& os, const cReceptor* receptor);
};