#include "cAvion.h"
cAvion::cAvion():cVehiculo() {

}

cAvion::cAvion(string IDVehiculo) : cVehiculo(IDVehiculo) {

}

cAvion::~cAvion() {

}

void cAvion::imprimir() {
	cout << "zhooooooom" << endl;
}