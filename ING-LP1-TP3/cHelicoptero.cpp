#include "cHelicoptero.h"
cHelicoptero::cHelicoptero() {

}

cHelicoptero::cHelicoptero(string IDVehiculo):cVehiculo(IDVehiculo) {

}

cHelicoptero::~cHelicoptero() {

}

void cHelicoptero::imprimir() {
	cout << "taca-taca-taca" << endl;
}