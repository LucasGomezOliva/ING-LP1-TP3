#pragma once
#include"cListaTemplate.h"
#include"cOrgano.h"
using namespace std;
class cListaOrganos:public cListaTemplate<cOrgano>
{
private:

public:
	friend class cDonante;
	cListaOrganos();
	cListaOrganos(unsigned int TamanioLista, bool on_delete_erase);
	~cListaOrganos();
	cOrgano* BuscarOrgano(eTipoDeOrgano Organo);
	cOrgano* BuscarOrgano(unsigned int NumeroDeOrgano);
	string ListaOrganosToString();
};

