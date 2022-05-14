#include "cListaReceptores.h"
cListaReceptores::cListaReceptores() : cListaTemplate<cReceptor>() {

}

cListaReceptores::cListaReceptores(int TamanioLista, bool on_delete_erase) : cListaTemplate<cReceptor>(TamanioLista, on_delete_erase) {

}

cListaReceptores::~cListaReceptores() {

}

