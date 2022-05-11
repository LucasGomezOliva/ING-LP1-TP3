#pragma once
#include"cReceptor.h"
#include"cDonante.h"
using namespace std;
class cINCUCAI
{
public:
	//lista receptores
	//lista donantes
	//lista centros de salud
private:
	cINCUCAI();
	~cINCUCAI();
	bool RecibirPaciente(cPaciente* Paciente);
	void BuscarPosiblesReceptores(cDonante* Donante);
};

