#include"cReceptor.h"
cReceptor::cReceptor():cPaciente() {
	this->PrioridadReceptor = ePrioridad::Baja;
	this->Patologia = "";
	this->Estado = eEstadoReceptor::Estable;
}

cReceptor::cReceptor(string Nombre, string NumeroTelefono, eTipoDeSangre Sangre, int DiaNacimiento, int MesNacimiento, int AnioNacimiento, int HoraNacimiento, int MinutosNacimiento,int DiaListaEspera, int MesListaEspera, int AnioListaEspera, int HoraListaEspera, int MinutosListaEspera, ePrioridad Prioridad, string Patologia, eEstadoReceptor Estado):cPaciente(Nombre, NumeroTelefono, Sangre, DiaNacimiento, MesNacimiento, AnioNacimiento, HoraNacimiento, MinutosNacimiento) {
	this->FechaListaEspera = new cFecha(DiaListaEspera, MesListaEspera, AnioListaEspera, HoraListaEspera, MinutosListaEspera);
	this->PrioridadReceptor = Prioridad;
	this->Patologia = Patologia;
	this->Estado = Estado;
}

cReceptor::~cReceptor() {
	delete FechaListaEspera;
}

void cReceptor::SetEstado(eEstadoReceptor NuevoEstado) {
	this->Estado = NuevoEstado;
}

void cReceptor::SetPrioridad(ePrioridad NuevaPrioridad) {
	this->PrioridadReceptor = NuevaPrioridad;
}

string cReceptor::ToStringReceptor() const {
	return ToStringPaciente() +
		"\n Prioridad: " + PrioridadToString(PrioridadReceptor) + 
		"\n Fecha Lista de Espera: " + FechaListaEspera->to_stringFecha() +
		"\n Patologia: " + Patologia +
		"\n Estado receptor : " + EstadoReceptorToString(Estado);
}

void cReceptor::imprimir() {
	cout << ToStringReceptor() << endl;
}

ostream& operator<<(ostream& os, const cReceptor* receptor) {
	os << receptor->ToStringReceptor();
	return os;
}