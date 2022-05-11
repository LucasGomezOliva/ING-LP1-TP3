#include "cPaciente.h"

cPaciente::cPaciente() {
	this->Nombre = "";
	this->NumeroTelefono = "";
	this->Sangre = eTipoDeSangre::O_Negativo;
}

cPaciente::cPaciente(string Nombre, string NumeroTelefono, eTipoDeSangre Sangre, int DiaNacimeinto, int MesNacimeinto, int AnioNacimeinto, int HoraNacimeinto, int MinutosNacimeinto) {
	this->Nombre = Nombre;
	this->FechaNacimeinto = new cFecha(DiaNacimeinto, MesNacimeinto, AnioNacimeinto, HoraNacimeinto, MinutosNacimeinto);
	this->NumeroTelefono = NumeroTelefono;
	this->Sangre = Sangre;
}

cPaciente::~cPaciente() {

}

void cPaciente::SetCentroDeSalud(cCentroDeSalud* CentroDeSalud) {
	this->CentroDeSalud = CentroDeSalud;
}

string cPaciente::ToStringPaciente() const {
	return
		"\n Nombre:" + Nombre +
		"\n Numero de Telefono: " + NumeroTelefono +
		"\n Fecha de nacimeiento: " + FechaNacimeinto->to_stringFecha() +
		"\n Tipo de sangre: " + TipoDeSangreToString(Sangre);
}