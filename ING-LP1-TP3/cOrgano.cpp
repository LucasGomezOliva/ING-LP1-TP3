#include "cOrgano.h"
cOrgano::cOrgano() {
	this->Organo = eTipoDeOrgano::Corazon;
}

cOrgano::cOrgano(eTipoDeOrgano Organo) {
	this->Organo = Organo;
}

cOrgano::~cOrgano() {
	delete FechaAbleacion;
}

void cOrgano::setFechaAbleacion(int DiaAbleacion, int MesAbleacion, int AnioAbleacion, int HoraAbleacion, int MinutosAbleacion) {
	this->FechaAbleacion = new cFecha(DiaAbleacion, MesAbleacion, AnioAbleacion, HoraAbleacion, MinutosAbleacion);
}

bool cOrgano::operator==(const cOrgano& OtroOrgano) {
	if (Organo == OtroOrgano.getTipo()) {
		return true;
	}
	return false;
}

ostream& operator<<(ostream& os, const cOrgano* organo) {
	os << TipoDeOrganoToString(organo->getTipo());
	return os;
}