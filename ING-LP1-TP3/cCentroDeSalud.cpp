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

void cCentroDeSalud::AsignarVehiculo(cReceptor* ReceptorSelecionado, cDonante* DonanteSeleccionado) {
	//Asignar vehiculo 
	//si misma provincia y mismo partido envia -- ambulancia
	//si misma provincia y distinto partido -- helicoptero
	//si distinta provincia -- avion
	if (Provincia == ReceptorSelecionado->GetCentroDeSalud()->GetProvincia() && Partido == ReceptorSelecionado->GetCentroDeSalud()->GetPartido()) {
		//enviar ambulacia
		for (unsigned int PosicionListaDeVehiculosDisponibles = 0; PosicionListaDeVehiculosDisponibles < ListaDeVehiculosDisponibles->CA; PosicionListaDeVehiculosDisponibles++) {
			cAmbulancia* AmbulanciaAuxiliar = dynamic_cast<cAmbulancia*> (ListaDeVehiculosDisponibles->Array[PosicionListaDeVehiculosDisponibles]);
			if (AmbulanciaAuxiliar != NULL) {
				cout << "Ambulancia disponilbe" << endl;
				AmbulanciaAuxiliar->RecibirOrgano(RealizarAblacion(DonanteSeleccionado, ReceptorSelecionado->GetOrganoRecibir()->getTipo()));
				//return AmbulanciaAuxiliar;
			}
		}
	}

	if (Provincia == ReceptorSelecionado->GetCentroDeSalud()->GetProvincia() && Partido != ReceptorSelecionado->GetCentroDeSalud()->GetPartido()) {
		//enviar Helicoptero
		for (unsigned int PosicionListaDeVehiculosDisponibles = 0; PosicionListaDeVehiculosDisponibles < ListaDeVehiculosDisponibles->CA; PosicionListaDeVehiculosDisponibles++) {
			cHelicoptero* HelicopteroAuxiliar = dynamic_cast<cHelicoptero*> (ListaDeVehiculosDisponibles->Array[PosicionListaDeVehiculosDisponibles]);
			if (HelicopteroAuxiliar != NULL) {
				cout << "Helicoptero disponilbe" << endl;
				HelicopteroAuxiliar->RecibirOrgano(RealizarAblacion(DonanteSeleccionado, ReceptorSelecionado->GetOrganoRecibir()->getTipo()));
				//return HelicopteroAuxiliar;
			}
		}
	}

	if (Provincia != ReceptorSelecionado->GetCentroDeSalud()->GetProvincia() && Partido != ReceptorSelecionado->GetCentroDeSalud()->GetPartido()) {
		//enviar Avion
		for (unsigned int PosicionListaDeVehiculosDisponibles = 0; PosicionListaDeVehiculosDisponibles < ListaDeVehiculosDisponibles->CA; PosicionListaDeVehiculosDisponibles++) {
			cAvion* AvionAuxiliar = dynamic_cast<cAvion*> (ListaDeVehiculosDisponibles->Array[PosicionListaDeVehiculosDisponibles]);
			if (AvionAuxiliar != NULL) {
				cout << "Avion disponilbe" << endl;
				AvionAuxiliar->RecibirOrgano(RealizarAblacion(DonanteSeleccionado, ReceptorSelecionado->GetOrganoRecibir()->getTipo()));
				//return AvionAuxiliar;
			}
		}
	}
}

cOrgano* cCentroDeSalud::RealizarAblacion(cDonante*Donante,eTipoDeOrgano TipoDeOrganoParaExtraer) {
	//setear fecha de ableacion en el donante
	//setear fecha de ableacion en el organo extraido
	//quitar el organo de la lista de organos del donante
	Donante->SetFechaComienzoAbleacion(1, 1, 1, 1, 1);
	cOrgano* OrganoExtraido = Donante->QuitarOrgano(TipoDeOrganoParaExtraer);
	OrganoExtraido->setFechaAbleacion(1, 1, 1, 1, 1);
	return OrganoExtraido;
}

void cCentroDeSalud::RealizarTransplante() {
	//verificar que no pasaron mas de 20hs de la ableacion del organo
	//realizar transplante
	//random equiprobable
	//si transplante exitoso se remuebe el paciente de la lista de pacientes receptores
	//si transplante NO exitoso se setea la prioridad a urgente y su estado cambia a inestable
}

string cCentroDeSalud::GetPartido()const {
	return Partido;
}
string cCentroDeSalud::GetProvincia() const {
	return Provincia;
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