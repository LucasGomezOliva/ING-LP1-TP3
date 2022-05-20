#include "cINCUCAI.h"
cINCUCAI::cINCUCAI() {
	this->ListaDonantesINCUCAI = new cListaDonantes(100, false);
	this->ListaReceptoresINCUCAI = new cListaReceptores(100, false);
	this->ListaDeCentrosDeSaludINCUCAI = new cListaCentrosDeSalud(30, false);
	this->CantidadDeDonaciones = 0;
}
cINCUCAI::~cINCUCAI() {
	delete ListaDonantesINCUCAI;
	delete ListaReceptoresINCUCAI;
	delete ListaDeCentrosDeSaludINCUCAI;
}

void cINCUCAI::CargaDeCentroDeSalud(cCentroDeSalud* CentroDeSalud) {
	*(ListaDeCentrosDeSaludINCUCAI) + CentroDeSalud;
}

void cINCUCAI::IngresarPaciente(cPaciente* Paciente) {
	cPaciente* PacienteAuxiliar = RecibirPaciente(Paciente);
	if (PacienteAuxiliar != NULL) {
		cReceptor* ReceptorAuxiliar = dynamic_cast<cReceptor*> (PacienteAuxiliar);
		if (ReceptorAuxiliar != NULL) {
			cDonante* DonanteAuxiliar = dynamic_cast<cDonante*> (Paciente);
			ProtocoloTransporteTransplante(ReceptorAuxiliar, DonanteAuxiliar);
		}	
		cDonante* DonanteAuxiliar = dynamic_cast<cDonante*> (PacienteAuxiliar);
		if (DonanteAuxiliar != NULL) {
			cReceptor* RecepetorAuxiliar = dynamic_cast<cReceptor*> (Paciente);
			ProtocoloTransporteTransplante(RecepetorAuxiliar, DonanteAuxiliar);
		}
	}

}

cPaciente* cINCUCAI::RecibirPaciente(cPaciente* Paciente) {

	cDonante* DonanteAuxiliar = dynamic_cast<cDonante*> (Paciente);
	if (DonanteAuxiliar != NULL) {
		*(ListaDonantesINCUCAI) + DonanteAuxiliar;
		for (unsigned int NumeroDeOrgano = 0; NumeroDeOrgano < DonanteAuxiliar->GetCantidadOrganos(); NumeroDeOrgano++) {
			cListaReceptores* ListaPosiblesReceptores = BuscarPosiblesReceptores(DonanteAuxiliar, NumeroDeOrgano);
			cPaciente* PacienteSeleccionado = SeleccionDeReceptor(ListaPosiblesReceptores, DonanteAuxiliar);
			delete ListaPosiblesReceptores;
			return PacienteSeleccionado;
		}
	}

	cReceptor* ReceptorAuxiliar = dynamic_cast<cReceptor*> (Paciente);
	if (ReceptorAuxiliar != NULL) {
		*(ListaReceptoresINCUCAI) + ReceptorAuxiliar;
		for (unsigned int PosicionListaDeDonantesINCUCAI = 0; PosicionListaDeDonantesINCUCAI < ListaDonantesINCUCAI->CA; PosicionListaDeDonantesINCUCAI++) {
			if (*((*ListaDonantesINCUCAI)[PosicionListaDeDonantesINCUCAI])==*(ReceptorAuxiliar)) {
				return (*ListaDonantesINCUCAI)[PosicionListaDeDonantesINCUCAI];
			}
		}
		return NULL;
	}

}

cListaReceptores* cINCUCAI::BuscarPosiblesReceptores(cDonante*Donante,unsigned int NumeroDeOrgano) {
	cListaReceptores* ListaPosiblesReceptores = new cListaReceptores(100, false);
	for (unsigned int i = 0; i < ListaReceptoresINCUCAI->CA; i++) {
		if (*(Donante) == *((*ListaReceptoresINCUCAI)[i])) {
			ListaPosiblesReceptores->Agregar((*ListaReceptoresINCUCAI)[i]);
		}
	}
	return ListaPosiblesReceptores;
}

cPaciente* cINCUCAI::SeleccionDeReceptor(cListaReceptores* ListaPosiblesReceptores, cDonante* Donante) {
	for (unsigned int PosicionListaPosiblesReceptores = 0; PosicionListaPosiblesReceptores < ListaPosiblesReceptores->CA; PosicionListaPosiblesReceptores++) {
		if ((*ListaPosiblesReceptores)[PosicionListaPosiblesReceptores]->GetPrioridadReceptor() == ePrioridad::Urgente) {
			return (*ListaPosiblesReceptores)[PosicionListaPosiblesReceptores];
		}
		if ((*ListaPosiblesReceptores)[PosicionListaPosiblesReceptores]->GetPrioridadReceptor() == ePrioridad::Alta) {
			return (*ListaPosiblesReceptores)[PosicionListaPosiblesReceptores];
		}
		if ((*ListaPosiblesReceptores)[PosicionListaPosiblesReceptores]->GetPrioridadReceptor() == ePrioridad::Media) {
			return (*ListaPosiblesReceptores)[PosicionListaPosiblesReceptores];
		}
		if ((*ListaPosiblesReceptores)[PosicionListaPosiblesReceptores]->GetPrioridadReceptor() == ePrioridad::Baja) {
			return (*ListaPosiblesReceptores)[PosicionListaPosiblesReceptores];
		}
	}
}

void cINCUCAI::ProtocoloTransporteTransplante(cReceptor* ReceptorSelecionado, cDonante* DonanteSeleccionado) {
	cVehiculo* VehiculoDeTransplante = DonanteSeleccionado->GetCentroDeSalud()->AsignarVehiculo(ReceptorSelecionado, DonanteSeleccionado);
	if (VehiculoDeTransplante != NULL) {
		this->CantidadDeDonaciones++;
		VehiculoDeTransplante->imprimir();
		if (VehiculoDeTransplante->GetOrgano()->GetFechaAbleacion()->CompararFechas(VehiculoDeTransplante->GetOrgano()->GetFechaAbleacion()) == true){
			if (ReceptorSelecionado->GetCentroDeSalud()->RealizarTransplante(ReceptorSelecionado, VehiculoDeTransplante) == false) {
				ReceptorSelecionado->SetEstado(eEstadoReceptor::Inestable);
				ReceptorSelecionado->SetPrioridad(ePrioridad::Urgente);
			}
			else {
				*(ListaReceptoresINCUCAI) - ReceptorSelecionado;
			}
		}
	}
}

void cINCUCAI::BuscarReceptorinformarDatos(string NombreReceptor) {
	ListaReceptoresINCUCAI->InformarDatosReceptor(NombreReceptor);
}

string cINCUCAI::ToStringINCUCAI() const {
	return "\n ----INCUCAI---\nCantidad de Donaciones realizadas:\t" + to_string(CantidadDeDonaciones);
}
void cINCUCAI::imprimir() const {
	ImprimirListas();
	cout << ToStringINCUCAI() << endl;
}

void cINCUCAI::ImprimirListas() const{
	cout << "\n Lista de Receptores" << endl;
	cout << ListaReceptoresINCUCAI << endl;
	cout << "\n Lista de Donantes" << endl;
	cout << ListaDonantesINCUCAI;
	cout << "\n Lista de Centros de Salud" << endl;
	cout << ListaDeCentrosDeSaludINCUCAI;
}

ostream& operator<<(ostream& os, const cINCUCAI* incucai) {
	os << incucai->ToStringINCUCAI();
	return os;
}