#pragma once
#include"cReceptor.h"
#include"cDonante.h"
using namespace std;
class cINCUCAI
{
private:
	//lista receptores
	//lista donantes
	//lista centros de salud
public:
	cINCUCAI();
	~cINCUCAI();
	bool RecibirPaciente(cPaciente* Paciente);
	void BuscarPosiblesReceptores(cDonante* Donante);
};

