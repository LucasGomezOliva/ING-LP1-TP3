#include "cVehiculo.h"
cVehiculo::cVehiculo() {

}

cVehiculo::~cVehiculo() {

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