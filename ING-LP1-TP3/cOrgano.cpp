#include "cOrgano.h"
cOrgano::cOrgano() {

}
cOrgano::~cOrgano() {
	delete FechaAbleacion;
}

void cOrgano::setFechaAbleacion(int DiaAbleacion, int MesAbleacion, int AnioAbleacion, int HoraAbleacion, int MinutosAbleacion) {
	this->FechaAbleacion = new cFecha(DiaAbleacion, MesAbleacion, AnioAbleacion, HoraAbleacion, MinutosAbleacion);
}