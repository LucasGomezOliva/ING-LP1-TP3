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
	bool RecibirPaciente(cPaciente* Paciente);
	void BuscarPosiblesReceptores(cDonante* Donante);
	string ToStringINCUCAI() const;
	void imprimir() const;
};

