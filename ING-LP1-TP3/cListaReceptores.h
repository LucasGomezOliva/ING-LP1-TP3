#pragma once
#include"cListaTemplate.h"
#include"cReceptor.h"

using namespace std;
class cINCUCAI;
class cListaReceptores:public cListaTemplate<cReceptor>
{
private:
public:
	friend class cINCUCAI;
	cListaReceptores();
	cListaReceptores(unsigned int TamanioLista, bool on_delete_erase);
	~cListaReceptores();
	cReceptor* QuitarReceptor(cOrgano* OrganoRecibir);
	cReceptor* BuscarReceptor(string NombreRecpetor);
	void InformarDatosReceptor(string Nombre);
};

