#include "cCentroDeSalud.h"
cCentroDeSalud::cCentroDeSalud() {
	this->Nombre = "";
	this->Direccion = "";
	this->Partido = "";
	this->Provincia = "";
	this->Telefono = 0;
	this->ListaDeVehiculosDisponibles = new cListaVehiculos(10, true);
}
cCentroDeSalud::cCentroDeSalud(string Nombre,string Direccion,string Partido,string Provincia,long int Telefono) {
	this->Nombre = Nombre;
	this->Direccion = Direccion;
	this->Partido = Partido;
	this->Provincia = Provincia;
	this->Telefono = Telefono;
	this->ListaDeVehiculosDisponibles = new cListaVehiculos(10, true);

	*(ListaDeVehiculosDisponibles) + new cAmbulancia("1");
	*(ListaDeVehiculosDisponibles) + new cHelicoptero("2");
	*(ListaDeVehiculosDisponibles) + new cAvion("3");
}
cCentroDeSalud::~cCentroDeSalud() {
	delete ListaDeVehiculosDisponibles;
}

cVehiculo* cCentroDeSalud::AsignarVehiculo(cReceptor* ReceptorSelecionado, cDonante* DonanteSeleccionado) {
	if (Provincia == ReceptorSelecionado->GetCentroDeSalud()->GetProvincia() && Partido == ReceptorSelecionado->GetCentroDeSalud()->GetPartido()) {
		for (unsigned int PosicionListaDeVehiculosDisponibles = 0; PosicionListaDeVehiculosDisponibles < ListaDeVehiculosDisponibles->CA; PosicionListaDeVehiculosDisponibles++) {
			cAmbulancia* AmbulanciaAuxiliar = dynamic_cast<cAmbulancia*> (ListaDeVehiculosDisponibles->Array[PosicionListaDeVehiculosDisponibles]);
			if (AmbulanciaAuxiliar != NULL) {
				AmbulanciaAuxiliar->RecibirOrgano(RealizarAblacion(DonanteSeleccionado, ReceptorSelecionado->GetOrganoRecibir()->getTipo()));
				return AmbulanciaAuxiliar;
			}
		}
	}
	if (Provincia == ReceptorSelecionado->GetCentroDeSalud()->GetProvincia() && Partido != ReceptorSelecionado->GetCentroDeSalud()->GetPartido()) {
		for (unsigned int PosicionListaDeVehiculosDisponibles = 0; PosicionListaDeVehiculosDisponibles < ListaDeVehiculosDisponibles->CA; PosicionListaDeVehiculosDisponibles++) {
			cHelicoptero* HelicopteroAuxiliar = dynamic_cast<cHelicoptero*> (ListaDeVehiculosDisponibles->Array[PosicionListaDeVehiculosDisponibles]);
			if (HelicopteroAuxiliar != NULL) {
				HelicopteroAuxiliar->RecibirOrgano(RealizarAblacion(DonanteSeleccionado, ReceptorSelecionado->GetOrganoRecibir()->getTipo()));
				return HelicopteroAuxiliar;
			}
		}
	}
	if (Provincia != ReceptorSelecionado->GetCentroDeSalud()->GetProvincia() && Partido != ReceptorSelecionado->GetCentroDeSalud()->GetPartido()) {
		for (unsigned int PosicionListaDeVehiculosDisponibles = 0; PosicionListaDeVehiculosDisponibles < ListaDeVehiculosDisponibles->CA; PosicionListaDeVehiculosDisponibles++) {
			cAvion* AvionAuxiliar = dynamic_cast<cAvion*> (ListaDeVehiculosDisponibles->Array[PosicionListaDeVehiculosDisponibles]);
			if (AvionAuxiliar != NULL) {
				AvionAuxiliar->RecibirOrgano(RealizarAblacion(DonanteSeleccionado, ReceptorSelecionado->GetOrganoRecibir()->getTipo()));
				return AvionAuxiliar;
			}
		}
	}
	return NULL;
}

cOrgano* cCentroDeSalud::RealizarAblacion(cDonante*Donante,eTipoDeOrgano TipoDeOrganoParaExtraer) {
	Donante->SetFechaComienzoAbleacion(20, 5, 2022, 10, 20);
	cOrgano* OrganoExtraido = Donante->QuitarOrgano(TipoDeOrganoParaExtraer);
	OrganoExtraido->setFechaAbleacion(20, 5, 2022, 10, 20);
	return OrganoExtraido;
}

bool cCentroDeSalud::RealizarTransplante(cReceptor* ReceptorSeleccionado, cVehiculo* VehiculoDeTransplante) {
	cOrgano* OrganoParaTranpslante = VehiculoDeTransplante->EntregarOrgano();
	if (OrganoParaTranpslante->GetFechaAbleacion()->CompararFechas(OrganoParaTranpslante->GetFechaAbleacion()) == true) {
		ReceptorSeleccionado->SetOrganoNuevo(OrganoParaTranpslante);
		srand((unsigned)time(NULL));
		if ((rand() % 2) == 1) {
			return false;
		}
		return true;
	}
	return false;
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