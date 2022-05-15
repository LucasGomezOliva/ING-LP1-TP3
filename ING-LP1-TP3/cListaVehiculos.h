#pragma once
#include"cListaTemplate.h"
#include"cVehiculo.h"
using namespace std;
class cListaVehiculos:public cListaTemplate<cVehiculo>
{
private:
public:
	friend class cCentroDeSalud;
	cListaVehiculos();
	cListaVehiculos(unsigned int TamanioLista, bool on_delete_erase);
	~cListaVehiculos();
};

