#include "cListaVehiculos.h"
cListaVehiculos::cListaVehiculos() : cListaTemplate<cVehiculo>() {

}
cListaVehiculos::cListaVehiculos(unsigned int TamanioLista, bool on_delete_erase) : cListaTemplate<cVehiculo>(TamanioLista, on_delete_erase) {

}
cListaVehiculos::~cListaVehiculos() {

}