#include "cListaCentrosDeSalud.h"
cListaCentrosDeSalud::cListaCentrosDeSalud() {

}
cListaCentrosDeSalud::cListaCentrosDeSalud(unsigned int TamanioLista, bool on_delete_erase):cListaTemplate<cCentroDeSalud>(TamanioLista, on_delete_erase) {

}
cListaCentrosDeSalud::~cListaCentrosDeSalud() {

}

ostream& operator<<(ostream& os, const cListaCentrosDeSalud* ListaCentroDeSalud) {
	string Auxiliar;
	for (unsigned int i = 0; i < ListaCentroDeSalud->CA; i++) {
		if (ListaCentroDeSalud->Array[i] != NULL) {
			Auxiliar = Auxiliar + ListaCentroDeSalud->Array[i]->ToStringCentroDeSalud() + "\n";
		}
	}
	os << Auxiliar;
	return os;
}