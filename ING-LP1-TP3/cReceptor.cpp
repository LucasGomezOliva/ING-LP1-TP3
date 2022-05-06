#include"cReceptor.h"
cReceptor::cReceptor() {
	this->PrioridadReceptor = Prioridad::Baja;
	this->Patologia = "";
	this->Estado = EstadoReceptor::Estable;
}

cReceptor::cReceptor(cFecha* FechaListaEspera, Prioridad Prioridad, string Patologia, EstadoReceptor Estado):cPaciente(Nombre, NumeroTelefono, Sangre, FechaNacimeinto) {
	this->FechaListaEspera = FechaListaEspera;
	this->PrioridadReceptor = Prioridad;
	this->Patologia = Patologia;
	this->Estado = Estado;
}

cReceptor::~cReceptor() {

}