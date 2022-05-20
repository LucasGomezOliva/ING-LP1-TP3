#include "cVehiculo.h"
cVehiculo::cVehiculo() {
	this->IDVehiculo = "";
}

cVehiculo::cVehiculo(string IDVehiculo) {
	this->IDVehiculo = IDVehiculo;
}

cVehiculo::~cVehiculo() {

}

cOrgano* cVehiculo::GetOrgano() {
	return Organo;
}

void cVehiculo::RecibirOrgano(cOrgano* Organo) {
	this->Organo = Organo;
}

cOrgano* cVehiculo::EntregarOrgano() {
	cOrgano* OrganoAuxiliar;
	OrganoAuxiliar = Organo;
	this->Organo = NULL;
	return OrganoAuxiliar;
}

bool cVehiculo::operator==(const cVehiculo& OtroVehiculo) {
	if (IDVehiculo == OtroVehiculo.IDVehiculo)
		return true;
	return false;
}