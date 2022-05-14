#include "cDonante.h"

cDonante::cDonante():cPaciente() {
	this->ListaDeOrganosDonante = new cListaOrganos();
}

cDonante::cDonante(string Nombre, string NumeroTelefono, eTipoDeSangre Sangre, int DiaNacimiento, int MesNacimiento, int AnioNacimiento, int HoraNacimiento, int MinutosNacimiento, int DiaFallecimient, int MesFallecimient, int AnioFallecimient, int HoraFallecimient, int MinutosFallecimient):cPaciente(Nombre, NumeroTelefono, Sangre, DiaNacimiento, MesNacimiento, AnioNacimiento, HoraNacimiento, MinutosNacimiento) {
	SetFallecimiento(DiaFallecimient, MesFallecimient, AnioFallecimient, HoraFallecimient, MinutosFallecimient);
	this->ListaDeOrganosDonante = new cListaOrganos(9, false);
	*(ListaDeOrganosDonante) + new cOrgano(eTipoDeOrgano::Corazon);
	*(ListaDeOrganosDonante) + new cOrgano(eTipoDeOrgano::Higado);
	*(ListaDeOrganosDonante) + new cOrgano(eTipoDeOrgano::Pancreas);
	*(ListaDeOrganosDonante) + new cOrgano(eTipoDeOrgano::Huesos);
	*(ListaDeOrganosDonante) + new cOrgano(eTipoDeOrgano::Rinion);
	*(ListaDeOrganosDonante) + new cOrgano(eTipoDeOrgano::Pulmones);
	*(ListaDeOrganosDonante) + new cOrgano(eTipoDeOrgano::Intestino);
	*(ListaDeOrganosDonante) + new cOrgano(eTipoDeOrgano::Piel);
	*(ListaDeOrganosDonante) + new cOrgano(eTipoDeOrgano::Corneas);
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
	string DatosDonante;
	DatosDonante = ToStringPaciente();
	if (FechaFalleciemiento != NULL)
		DatosDonante = DatosDonante + "\n Fecha de Fallecimiento: " + FechaFalleciemiento->to_stringFecha();
	if(FechaComienzoAbleacion != NULL)
		DatosDonante = DatosDonante + "\n Fecha de Comienzo de Ableacion:" + FechaComienzoAbleacion->to_stringFecha();
	DatosDonante = DatosDonante + ListaDeOrganosDonante->ListaOrganosToString();
	return DatosDonante;
}

void cDonante::imprimir(){
	cout << ToStringDonante() << endl;
}

ostream& operator<<(ostream& os, const cDonante* donante) {
	os << donante->ToStringDonante();
	return os;
}