#include "cINCUCAI.h"
cINCUCAI::cINCUCAI() {
	this->ListaDonantesINCUCAI = new cListaDonantes(100, false);
	this->ListaReceptoresINCUCAI = new cListaReceptores(100, false);
	this->ListaDeCentrosDeSaludINCUCAI = new cListaCentrosDeSalud(30, false);
	this->CantidadDeDonacionesPorProvincia = 0;
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
	//Revisa que el metodo Recibir paciente encontro o no un match
	if (PacienteAuxiliar != NULL) {
		//Reviso si el Paciente que devolvio la funcion es un receptror o un donante
		cReceptor* ReceptorAuxiliar = dynamic_cast<cReceptor*> (PacienteAuxiliar);
		//Si es un receptor inicia el protocolo de Transporte Transplante
		if (ReceptorAuxiliar != NULL) {
			cDonante* DonanteAuxiliar = dynamic_cast<cDonante*> (Paciente);
			ProtocoloTransporteTransplante(ReceptorAuxiliar, DonanteAuxiliar);
		}
		//add revisar------------------
		//Si es un donante inicio el protocolo de Transporte Transplante
		
		cDonante* DonanteAuxiliar = dynamic_cast<cDonante*> (PacienteAuxiliar);
		if (DonanteAuxiliar != NULL) {
			cReceptor* RecepetorAuxiliar = dynamic_cast<cReceptor*> (Paciente);
			ProtocoloTransporteTransplante(RecepetorAuxiliar, DonanteAuxiliar);
		}
		
		//add revisar------------------
	}

}

cPaciente* cINCUCAI::RecibirPaciente(cPaciente* Paciente) {

	cDonante* DonanteAuxiliar = dynamic_cast<cDonante*> (Paciente);
	if (DonanteAuxiliar != NULL) {
		cout << "El paciente es un donante" << endl;
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
		cout << "El paciente es un receptor" << endl;
		*(ListaReceptoresINCUCAI) + ReceptorAuxiliar;

		//add revisar -- buscar coincidencia en la lista de donantes--
		for (unsigned int PosicionListaDeDonantesINCUCAI = 0; PosicionListaDeDonantesINCUCAI < ListaDonantesINCUCAI->CA; PosicionListaDeDonantesINCUCAI++) {
			if (*((*ListaDonantesINCUCAI)[PosicionListaDeDonantesINCUCAI])==*(ReceptorAuxiliar)) {
				return (*ListaDonantesINCUCAI)[PosicionListaDeDonantesINCUCAI];
			}
		}
		//add revisar -- devolver cPaciente que correspode al match--
		return NULL;
	}

}

cListaReceptores* cINCUCAI::BuscarPosiblesReceptores(cDonante*Donante,unsigned int NumeroDeOrgano) {
	cListaReceptores* ListaPosiblesReceptores = new cListaReceptores(100, false);
	for (unsigned int i = 0; i < ListaReceptoresINCUCAI->CA; i++) {
		if (*(Donante) == *((*ListaReceptoresINCUCAI)[i])) {
			ListaPosiblesReceptores->Agregar((*ListaReceptoresINCUCAI)[i]);
			cout << "Receptor compatible encontrado para: "<<TipoDeOrganoToString(Donante->GetOrgano(NumeroDeOrgano)->getTipo()) << endl;
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
	cout << "Inicio de protocolo de transplante" << endl;
	cVehiculo* VehiculoDeTransplante = DonanteSeleccionado->GetCentroDeSalud()->AsignarVehiculo(ReceptorSelecionado, DonanteSeleccionado);
	if (VehiculoDeTransplante != NULL) {
		this->CantidadDeDonacionesPorProvincia++;
		VehiculoDeTransplante->imprimir();
		if (VehiculoDeTransplante->GetOrgano()->GetFechaAbleacion()->CompararFechas(VehiculoDeTransplante->GetOrgano()->GetFechaAbleacion()) == true){
			if (ReceptorSelecionado->GetCentroDeSalud()->RealizarTransplante(ReceptorSelecionado, VehiculoDeTransplante) == false) {
				ReceptorSelecionado->SetEstado(eEstadoReceptor::Inestable);
				ReceptorSelecionado->SetPrioridad(ePrioridad::Urgente);
			}
			else {
				*(ListaReceptoresINCUCAI)-ReceptorSelecionado;
				cout << "Receptor eliminado de la lista del INCUCAI" << endl;
			}
		}
	}
}

void cINCUCAI::BuscarReceptorinformarDatos(string NombreReceptor) {
	ListaReceptoresINCUCAI->InformarDatosReceptor(NombreReceptor);
}

string cINCUCAI::ToStringINCUCAI() const {
	return "\n ----INCUCAI---\nCantidad de Donaciones en provincia:\t" + to_string(CantidadDeDonacionesPorProvincia);
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