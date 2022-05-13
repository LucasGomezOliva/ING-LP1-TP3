#include "cListaOrganos.h"

cListaOrganos::cListaOrganos() : cListaTemplate<cOrgano> () {

}

cListaOrganos::cListaOrganos(int TamanioLista, bool on_delete_erase) : cListaTemplate<cOrgano>(TamanioLista,on_delete_erase) {

}

cListaOrganos::~cListaOrganos() {

}



cOrgano* cListaOrganos::BuscarOrgano(eTipoDeOrgano Organo){
	for (int i = 0; i < CA; i++) {
		if (Array[i]->getTipo() == Organo)
			return Quitar(Array[i]);
	}
	return NULL;
}