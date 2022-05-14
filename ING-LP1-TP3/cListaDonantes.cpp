#include "cListaDonantes.h"
cListaDonantes::cListaDonantes() {

}
cListaDonantes::cListaDonantes(unsigned int TamanioLista, bool on_delete_erase) : cListaTemplate<cDonante>(TamanioLista, on_delete_erase) {

}
cListaDonantes::~cListaDonantes() {

}