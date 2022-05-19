#pragma once
#include"cListaTemplate.h"
#include"cDonante.h"
using namespace std;
class cListaDonantes:public cListaTemplate<cDonante>
{
private:

public:
	friend class cINCUCAI;
	cListaDonantes();
	cListaDonantes(unsigned int TamanioLista, bool on_delete_erase);
	~cListaDonantes();
};

