#pragma once
#include"cListaTemplate.h"
#include"cCentroDeSalud.h"
class cListaCentrosDeSalud:public cListaTemplate<cCentroDeSalud>
{
private:
public:
	cListaCentrosDeSalud();
	cListaCentrosDeSalud(int TamanioLista, bool on_delete_erase);
	~cListaCentrosDeSalud();
};

