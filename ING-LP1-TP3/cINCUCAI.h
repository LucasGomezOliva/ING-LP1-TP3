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
	int CantidadDeDonaciones;
public:
	cINCUCAI();
	~cINCUCAI();
	void CargaDeCentroDeSalud(cCentroDeSalud* CentroDeSalud);
	void IngresarPaciente(cPaciente* Paciente);
	cPaciente* RecibirPaciente(cPaciente* Paciente);
	cPaciente* SeleccionDeReceptor(cListaReceptores*ListaPosiblesReceptores,cDonante*Donante);
	cListaReceptores* BuscarPosiblesReceptores(cDonante* Donante, unsigned int NumeroDeOrgano);
	void ProtocoloTransporteTransplante(cReceptor* ReceptorSelecionado, cDonante* DonanteSeleccionado);
	void BuscarReceptorinformarDatos(string NombreReceptor);
	string ToStringINCUCAI() const;
	void ImprimirListas() const;
	void imprimir() const;
	friend ostream& operator<<(ostream& os, const cINCUCAI* incucai);
};

