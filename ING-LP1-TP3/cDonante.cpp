#include "cDonante.h"

cDonante::cDonante():cPaciente() {
	this->ListaDeOrganosDonante = new cListaOrganos();
}

cDonante::cDonante(string Nombre, string NumeroTelefono, eTipoDeSangre Sangre, int DiaNacimiento, int MesNacimiento, int AnioNacimiento, int HoraNacimiento, int MinutosNacimiento):cPaciente(Nombre, NumeroTelefono, Sangre, DiaNacimiento, MesNacimiento, AnioNacimiento, HoraNacimiento, MinutosNacimiento) {
	this->ListaDeOrganosDonante = new cListaOrganos(9, false);
	//this->ListaDeOrganosDonante + new cOrgano();
	*(ListaDeOrganosDonante) + new cOrgano(eTipoDeOrgano::Corazon);
	*(ListaDeOrganosDonante)+new cOrgano(eTipoDeOrgano::Corneas);

}

cDonante::~cDonante() {
	delete FechaFalleciemiento;
	delete FechaComienzoAbleacion;
	delete ListaDeOrganosDonante;
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