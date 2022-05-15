#include "cCentroDeSalud.h"
cCentroDeSalud::cCentroDeSalud() {
	this->Nombre = "";
	this->Direccion = "";
	this->Partido = "";
	this->Provincia = "";
	this->Telefono = 0;
	this->ListaDeVehiculosDisponibles = new cListaVehiculos(10, false);
}
cCentroDeSalud::cCentroDeSalud(string Nombre,string Direccion,string Partido,string Provincia,long int Telefono) {
	this->Nombre = Nombre;
	this->Direccion = Direccion;
	this->Partido = Partido;
	this->Provincia = Provincia;
	this->Telefono = Telefono;
	this->ListaDeVehiculosDisponibles = new cListaVehiculos(10, false);
}
cCentroDeSalud::~cCentroDeSalud() {
	delete ListaDeVehiculosDisponibles;
}

void cCentroDeSalud::AsignarVehiculo() {
	//Asignar vehiculo 
	//si misma provincia y mismo partido envia -- ambulancia
	//si misma provincia y distinto partido -- helicoptero
	//si distinta provincia -- avion
}

void cCentroDeSalud::RealizarAblacion() {
	//setear fecha de ableacion en el donante
	//setear fecha de ableacion en el organo extraido
	//quitar el organo de la lista de organos del donante
}

void cCentroDeSalud::RealizarTransplante() {
	//verificar que no pasaron mas de 20hs de la ableacion del organo
	//realizar transplante
	//random equiprobable
	//si transplante exitoso se remuebe el paciente de la lista de pacientes receptores
	//si transplante NO exitoso se setea la prioridad a urgente y su estado cambia a inestable
}

string cCentroDeSalud::ToStringCentroDeSalud() const {
	return 
		"\n Nombre: " + Nombre +
		"\n Direccion: " + Direccion +
		"\n Partido: " + Partido +
		"\n Provincia: " + Provincia +
		"\n Telefono: " + to_string(Telefono);
}

void cCentroDeSalud::imprimir() const {
	cout << ToStringCentroDeSalud() << endl;
}

ostream& operator<<(ostream& os, const cCentroDeSalud* CentroDeSalud) {
	os << CentroDeSalud->ToStringCentroDeSalud();
	return os;
}

bool cCentroDeSalud::operator==(const cCentroDeSalud& OtroCentroDeSalud) {
	if (Nombre == OtroCentroDeSalud.Nombre)
		return true;
	return false;
}