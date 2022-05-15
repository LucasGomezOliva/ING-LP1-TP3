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
	cPaciente* RecibirPaciente(cPaciente* Paciente);
	cPaciente* SeleccionDeReceptor(cListaReceptores*ListaPosiblesReceptores,cDonante*Donante);
	cListaReceptores* BuscarPosiblesReceptores(cDonante* Donante, unsigned int NumeroDeOrgano);
	void ProtocoloTransporteTransplante(cReceptor* ReceptorSelecionado, cDonante* DonanteSeleccionado);
	string ToStringINCUCAI() const;
	void imprimir() const;
};

