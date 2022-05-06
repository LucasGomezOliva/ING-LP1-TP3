#include "cPaciente.h"

cPaciente::cPaciente() {
	this->Nombre = "";
	this->NumeroTelefono = "";
	this->Sangre = TipoDeSangre::O_Negativo;
}

cPaciente::cPaciente(string Nombre, string NumeroTelefono, TipoDeSangre Sangre,cFecha* FechaNaciemiento) {
	this->Nombre = Nombre;
	this->FechaNacimeinto = FechaNaciemiento;
	this->NumeroTelefono = NumeroTelefono;
	this->Sangre = Sangre;
}

cPaciente::~cPaciente() {

}