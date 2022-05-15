#pragma once
#include"cListaDonantes.h"
#include"cListaReceptores.h"
#include"cListaCentrosDeSalud.h"
using namespace std;
class cINCUCAI
{
private:
	cListaReceptores* ListaReceptoresINCUCAI = NULL;
	cListaDonantes* ListaDonantesINCUCAI = NULL;
	cListaCentrosDeSalud* ListaDeCentrosDeSaludINCUCAI = NULL;
public:
	cINCUCAI();
	~cINCUCAI();
	void CargaDeCentroDeSalud(cCentroDeSalud* CentroDeSalud);
	bool RecibirPaciente(cPaciente* Paciente);

	cPaciente* SeleccionDeReceptor(cDonante*Donante);

	cListaReceptores* BuscarPosiblesReceptores(cDonante* Donante, unsigned int NumeroDeOrgano);
	string ToStringINCUCAI() const;
	void imprimir() const;
};

