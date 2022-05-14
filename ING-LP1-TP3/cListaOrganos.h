#pragma once
#include"cListaTemplate.h"
#include"cOrgano.h"
using namespace std;
class cListaOrganos:public cListaTemplate<cOrgano>
{
private:

public:
	cListaOrganos();
	cListaOrganos(unsigned int TamanioLista, bool on_delete_erase);
	~cListaOrganos();
	cOrgano* BuscarOrgano(eTipoDeOrgano Organo);
	string ListaOrganosToString();
};

