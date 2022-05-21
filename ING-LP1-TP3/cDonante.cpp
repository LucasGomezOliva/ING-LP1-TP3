#include "cDonante.h"

cDonante::cDonante():cPaciente() {
	this->ListaDeOrganosDonante = new cListaOrganos();
}

cDonante::cDonante(string Nombre, string NumeroTelefono, eTipoDeSangre Sangre, int DiaNacimiento, int MesNacimiento, int AnioNacimiento, int HoraNacimiento, int MinutosNacimiento, cCentroDeSalud* CentroDeSalud, int DiaFallecimient, int MesFallecimient, int AnioFallecimient, int HoraFallecimient, int MinutosFallecimient):cPaciente(Nombre, NumeroTelefono, Sangre, DiaNacimiento, MesNacimiento, AnioNacimiento, HoraNacimiento, MinutosNacimiento, CentroDeSalud) {
	SetFallecimiento(DiaFallecimient, MesFallecimient, AnioFallecimient, HoraFallecimient, MinutosFallecimient);
	this->ListaDeOrganosDonante = new cListaOrganos(9, true);
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


cOrgano* cDonante::QuitarOrgano(unsigned int NumeroDeOrgano) {
	return ListaDeOrganosDonante->Quitar(ListaDeOrganosDonante->BuscarOrgano(NumeroDeOrgano));
}

cOrgano* cDonante::QuitarOrgano(eTipoDeOrgano TipoDeOrgano) {
	return ListaDeOrganosDonante->BuscarOrgano(TipoDeOrgano);
}


void cDonante::SetFallecimiento(int DiaFallecimiento, int MesFallecimiento, int AnioFallecimiento, int HoraFallecimiento, int MinutosFallecimiento) {
	this->FechaFalleciemiento = new cFecha(DiaFallecimiento, MesFallecimiento, AnioFallecimiento, HoraFallecimiento, MinutosFallecimiento);
}

void cDonante::SetFechaComienzoAbleacion(int DiaComienzoAbleacion, int MesComienzoAbleacion, int AnioComienzoAbleacion, int HoraComienzoAbleacion, int MinutosComienzoAbleacion) {
	this->FechaComienzoAbleacion = new cFecha(DiaComienzoAbleacion, MesComienzoAbleacion, AnioComienzoAbleacion, HoraComienzoAbleacion, MinutosComienzoAbleacion);
}

cOrgano* cDonante::GetOrgano(unsigned int NumeroDeOrgano) const {
	
	return ListaDeOrganosDonante->BuscarOrgano(NumeroDeOrgano);
}

unsigned cDonante::GetCantidadOrganos() const {
	return ListaDeOrganosDonante->CA;
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

bool cDonante::operator==(cReceptor& Receptor) {
	for (unsigned int PosicionListaOrganos = 0; PosicionListaOrganos < ListaDeOrganosDonante->CA; PosicionListaOrganos++) {
		if ((Receptor.GetTipoDeSangre() == Sangre) && (Receptor.GetOrganoRecibir()->getTipo() == ListaDeOrganosDonante->BuscarOrgano(PosicionListaOrganos)->getTipo())) {
			return true;
		}
	}
	return false;
}

bool cDonante::operator==(const cDonante& Donante) {
	if (Nombre == Donante.GetNombre())
		return true;
	return false;
}