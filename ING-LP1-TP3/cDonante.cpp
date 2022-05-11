#include "cDonante.h"

cDonante::cDonante():cPaciente() {
	/*
	//Corazon
	ListaOrganosDonante.Agregar(new cOrgano());
	//hígado
	ListaOrganosDonante.Agregar(new cOrgano());
	//páncreas
	ListaOrganosDonante.Agregar(new cOrgano());
	//huesos
	ListaOrganosDonante.Agregar(new cOrgano());
	//riñón
	ListaOrganosDonante.Agregar(new cOrgano());
	//pulmones
	ListaOrganosDonante.Agregar(new cOrgano());
	//intestino
	ListaOrganosDonante.Agregar(new cOrgano());
	//piel
	ListaOrganosDonante.Agregar(new cOrgano());
	//córneas
	ListaOrganosDonante.Agregar(new cOrgano());
	*/
}

cDonante::cDonante(string Nombre, string NumeroTelefono, eTipoDeSangre Sangre, int DiaNacimiento, int MesNacimiento, int AnioNacimiento, int HoraNacimiento, int MinutosNacimiento):cPaciente(Nombre, NumeroTelefono, Sangre, DiaNacimiento, MesNacimiento, AnioNacimiento, HoraNacimiento, MinutosNacimiento) {
	/*
	//Corazon
	ListaOrganosDonante.Agregar(new cOrgano());
	//hígado
	ListaOrganosDonante.Agregar(new cOrgano());
	//páncreas
	ListaOrganosDonante.Agregar(new cOrgano());
	//huesos
	ListaOrganosDonante.Agregar(new cOrgano());
	//riñón
	ListaOrganosDonante.Agregar(new cOrgano());
	//pulmones
	ListaOrganosDonante.Agregar(new cOrgano());
	//intestino
	ListaOrganosDonante.Agregar(new cOrgano());
	//piel
	ListaOrganosDonante.Agregar(new cOrgano());
	//córneas
	ListaOrganosDonante.Agregar(new cOrgano());
	*/
}

cDonante::~cDonante() {
	delete FechaFalleciemiento;
	delete FechaComienzoAbleacion;
}

void cDonante::SetFallecimiento(int DiaFallecimiento, int MesFallecimiento, int AnioFallecimiento, int HoraFallecimiento, int MinutosFallecimiento) {
	this->FechaFalleciemiento = new cFecha(DiaFallecimiento, MesFallecimiento, AnioFallecimiento, HoraFallecimiento, MinutosFallecimiento);
}

void cDonante::SetFechaComienzoAbleacion(int DiaComienzoAbleacion, int MesComienzoAbleacion, int AnioComienzoAbleacion, int HoraComienzoAbleacion, int MinutosComienzoAbleacion) {
	this->FechaFalleciemiento = new cFecha(DiaComienzoAbleacion, MesComienzoAbleacion, AnioComienzoAbleacion, HoraComienzoAbleacion, MinutosComienzoAbleacion);
}

string cDonante::ToStringDonante() const {
	return ToStringPaciente() +
		"\n Fecha de Fallecimiento: " + FechaFalleciemiento->to_stringFecha() +
		"\n Fecha de Comienzo de Ableacion:" + FechaComienzoAbleacion->to_stringFecha();
}

void cDonante::imprimir() {
	cout << ToStringDonante() << endl;
}

ostream& operator<<(ostream& os, const cDonante* donante) {
	os << donante->ToStringDonante();
	return os;
}