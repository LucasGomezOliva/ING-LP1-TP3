#pragma once
#include"cListaTemplate.h"
#include"cReceptor.h"
using namespace std;
class cListaReceptores:public cListaTemplate<cReceptor>
{
private:
public:
	cListaReceptores();
	cListaReceptores(int TamanioLista, bool on_delete_erase);
	~cListaReceptores();
};

