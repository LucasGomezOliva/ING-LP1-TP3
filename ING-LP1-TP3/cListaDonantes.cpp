#include "cListaDonantes.h"
cListaDonantes::cListaDonantes() {

}
cListaDonantes::cListaDonantes(unsigned int TamanioLista, bool on_delete_erase) : cListaTemplate<cDonante>(TamanioLista, on_delete_erase) {

}
cListaDonantes::~cListaDonantes() {

}

ostream& operator<<(ostream& os, const cListaDonantes* ListaDonantes) {
	string Auxiliar;
	for (unsigned int i = 0; i < ListaDonantes->CA; i++) {
		if (ListaDonantes->Array[i] != NULL) {
			Auxiliar = Auxiliar + ListaDonantes->Array[i]->ToStringDonante() + "\n";
		}
	}
	os << Auxiliar;
	return os;
}