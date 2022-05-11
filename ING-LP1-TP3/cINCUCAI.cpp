#include "cINCUCAI.h"
cINCUCAI::cINCUCAI() {

}
cINCUCAI::~cINCUCAI() {

}
bool cINCUCAI::RecibirPaciente(cPaciente* Paciente) {

	cDonante* DonanteAuxiliar = dynamic_cast<cDonante*> (Paciente);
	if (DonanteAuxiliar != NULL) {
		cout << "El paciente es un donante" << endl;
		//agregar a la lista de pacientes donantes
		// metodo buscar los posibles receptores -- devolver sublista por cada organo a donar
		BuscarPosiblesReceptores(DonanteAuxiliar);
		//
	}

	cReceptor* ReceptorAuxiliar = dynamic_cast<cReceptor*> (Paciente);
	if (ReceptorAuxiliar != NULL) {
		cout << "El paciente es un receptor" << endl;
		//agrega a la lista de receptores
		//buscar coincidencia en la lista de donantes
		//devolver cPaciente que correspode al match
	}

	return true;
}

void cINCUCAI::BuscarPosiblesReceptores(cDonante* Donante) {
	//devolver sublista por cada organo a donar
}