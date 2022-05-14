#include "cListaOrganos.h"

cListaOrganos::cListaOrganos() : cListaTemplate<cOrgano> () {

}

cListaOrganos::cListaOrganos(unsigned int TamanioLista, bool on_delete_erase) : cListaTemplate<cOrgano>(TamanioLista,on_delete_erase) {

}

cListaOrganos::~cListaOrganos() {

}

string cListaOrganos::ListaOrganosToString() {
	string StringOrganos;
	StringOrganos = "\n Lista de organos:";
	for (unsigned int i = 0; i < CA; i++) {
		if (Array[i] != NULL) {
			StringOrganos = StringOrganos + "\n Organo: " + TipoDeOrganoToString(Array[i]->getTipo());
		}
	}
	return StringOrganos;
}

cOrgano* cListaOrganos::BuscarOrgano(eTipoDeOrgano Organo){
	for (unsigned int i = 0; i < CA; i++) {
		if (Array[i]->getTipo() == Organo)
			return Quitar(Array[i]);
	}
	return NULL;
}