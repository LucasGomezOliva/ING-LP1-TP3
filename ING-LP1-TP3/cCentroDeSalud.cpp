#include "cCentroDeSalud.h"
cCentroDeSalud::cCentroDeSalud() {
	this->Nombre = "";
	this->Direccion = "";
	this->Partido = "";
	this->Provincia = "";
	this->Telefono = 0;
}
cCentroDeSalud::cCentroDeSalud(string Nombre,string Direccion,string Partido,string Provincia,long int Telefono) {
	this->Nombre = Nombre;
	this->Direccion = Direccion;
	this->Partido = Partido;
	this->Provincia = Provincia;
	this->Telefono = Telefono;
}
cCentroDeSalud::~cCentroDeSalud() {

}