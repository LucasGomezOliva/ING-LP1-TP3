#include "cINCUCAI.h"
cINCUCAI::cINCUCAI() {
	this->ListaDonantesINCUCAI = new cListaDonantes(100, false);
	this->ListaReceptoresINCUCAI = new cListaReceptores(100, false);
	this->ListaDeCentrosDeSaludINCUCAI = new cListaCentrosDeSalud(30, false);
}
cINCUCAI::~cINCUCAI() {
	delete ListaDonantesINCUCAI;
	delete ListaReceptoresINCUCAI;
	delete ListaDeCentrosDeSaludINCUCAI;
}

void cINCUCAI::CargaDeCentroDeSalud(cCentroDeSalud* CentroDeSalud) {
	*(ListaDeCentrosDeSaludINCUCAI) + CentroDeSalud;
}


cPaciente* cINCUCAI::RecibirPaciente(cPaciente* Paciente) {

	cDonante* DonanteAuxiliar = dynamic_cast<cDonante*> (Paciente);
	if (DonanteAuxiliar != NULL) {
		cout << "El paciente es un donante" << endl;
		*(ListaDonantesINCUCAI) + DonanteAuxiliar;
		// metodo buscar los posibles receptores -- devolver sublista por cada organo a donar

		for (unsigned int NumeroDeOrgano = 0; NumeroDeOrgano < DonanteAuxiliar->GetCantidadOrganos(); NumeroDeOrgano++) {
			cListaReceptores* ListaPosiblesReceptores = BuscarPosiblesReceptores(DonanteAuxiliar, NumeroDeOrgano);

			cPaciente* PacienteSeleccionado = SeleccionDeReceptor(ListaPosiblesReceptores, DonanteAuxiliar);
			/*
			for (unsigned int PosicionListaPosiblesReceptores = 0; PosicionListaPosiblesReceptores < ListaPosiblesReceptores->CA; PosicionListaPosiblesReceptores++) {
				if (ListaPosiblesReceptores->Array[PosicionListaPosiblesReceptores]->GetPrioridadReceptor() == ePrioridad::Urgente) {
					//Iniciar proceso de ableacion
					//return ListaPosiblesReceptores->Array[PosicionListaPosiblesReceptores];
					DonanteAuxiliar->QuitarOrgano(NumeroDeOrgano);
				}

				if (ListaPosiblesReceptores->Array[PosicionListaPosiblesReceptores]->GetPrioridadReceptor() == ePrioridad::Alta) {
					//Iniciar proceso de ableacion
					//return ListaPosiblesReceptores->Array[PosicionListaPosiblesReceptores];
					DonanteAuxiliar->QuitarOrgano(NumeroDeOrgano);
				}

				if (ListaPosiblesReceptores->Array[PosicionListaPosiblesReceptores]->GetPrioridadReceptor() == ePrioridad::Media) {
					//Iniciar proceso de ableacion
					//return ListaPosiblesReceptores->Array[PosicionListaPosiblesReceptores];
					DonanteAuxiliar->QuitarOrgano(NumeroDeOrgano);
				}

				if (ListaPosiblesReceptores->Array[PosicionListaPosiblesReceptores]->GetPrioridadReceptor() == ePrioridad::Baja) {
					//Iniciar proceso de ableacion
					//return ListaPosiblesReceptores->Array[PosicionListaPosiblesReceptores];
					DonanteAuxiliar->QuitarOrgano(NumeroDeOrgano);
				}
			}
			*/
			delete ListaPosiblesReceptores;

			return PacienteSeleccionado;
		}
	}

	cReceptor* ReceptorAuxiliar = dynamic_cast<cReceptor*> (Paciente);
	if (ReceptorAuxiliar != NULL) {
		cout << "El paciente es un receptor" << endl;
		*(ListaReceptoresINCUCAI) + ReceptorAuxiliar;
		//buscar coincidencia en la lista de donantes
		//devolver cPaciente que correspode al match
	}

}

cListaReceptores* cINCUCAI::BuscarPosiblesReceptores(cDonante*Donante,unsigned int NumeroDeOrgano) {
	//devolver sublista por cada organo a donar
	cListaReceptores* ListaPosiblesReceptores = new cListaReceptores(100, false);
	for (unsigned int i = 0; i < ListaReceptoresINCUCAI->CA; i++) {
		//if (ListaReceptoresINCUCAI->Array[i]->GetOrganoRecibir() == Donante->GetOrgano(NumeroDeOrgano) && ListaReceptoresINCUCAI->Array[i]->GetTipoDeSangre()==Donante->GetTipoDeSangre()) {
		if(*(Donante) == *(ListaReceptoresINCUCAI->Array[i])){
			ListaPosiblesReceptores->Agregar(ListaReceptoresINCUCAI->Array[i]);
			cout << "Receptor compatible encontrado para: "<<TipoDeOrganoToString(Donante->GetOrgano(NumeroDeOrgano)->getTipo()) << endl;
		}
	}
	return ListaPosiblesReceptores;
}

cPaciente* cINCUCAI::SeleccionDeReceptor(cListaReceptores* ListaPosiblesReceptores, cDonante* Donante) {
	for (unsigned int PosicionListaPosiblesReceptores = 0; PosicionListaPosiblesReceptores < ListaPosiblesReceptores->CA; PosicionListaPosiblesReceptores++) {
		if (ListaPosiblesReceptores->Array[PosicionListaPosiblesReceptores]->GetPrioridadReceptor() == ePrioridad::Urgente) {
			return ListaPosiblesReceptores->Array[PosicionListaPosiblesReceptores];
		}

		if (ListaPosiblesReceptores->Array[PosicionListaPosiblesReceptores]->GetPrioridadReceptor() == ePrioridad::Alta) {
			return ListaPosiblesReceptores->Array[PosicionListaPosiblesReceptores];
		}

		if (ListaPosiblesReceptores->Array[PosicionListaPosiblesReceptores]->GetPrioridadReceptor() == ePrioridad::Media) {
			return ListaPosiblesReceptores->Array[PosicionListaPosiblesReceptores];
		}

		if (ListaPosiblesReceptores->Array[PosicionListaPosiblesReceptores]->GetPrioridadReceptor() == ePrioridad::Baja) {
			return ListaPosiblesReceptores->Array[PosicionListaPosiblesReceptores];
		}
	}
}

void cINCUCAI::ProtocoloTransporteTransplante(cReceptor* ReceptorSelecionado, cDonante* DonanteSeleccionado) {
	DonanteSeleccionado->GetCentroDeSalud()->AsignarVehiculo(ReceptorSelecionado, DonanteSeleccionado);
}


string cINCUCAI::ToStringINCUCAI() const {
	return "\n ----INCUCAI----";
}
void cINCUCAI::imprimir() const {
	cout << ToStringINCUCAI() << endl;
}