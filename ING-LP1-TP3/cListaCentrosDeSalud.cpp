#include "cListaCentrosDeSalud.h"
cListaCentrosDeSalud::cListaCentrosDeSalud() {

}
cListaCentrosDeSalud::cListaCentrosDeSalud(unsigned int TamanioLista, bool on_delete_erase):cListaTemplate<cCentroDeSalud>(TamanioLista, on_delete_erase) {

}
cListaCentrosDeSalud::~cListaCentrosDeSalud() {

}