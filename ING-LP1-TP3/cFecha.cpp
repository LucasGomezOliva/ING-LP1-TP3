#include "cFecha.h"
cFecha::cFecha() {
	fecha.tm_hour = 0;
	fecha.tm_min = 0;
	fecha.tm_sec = 0;
	fecha.tm_mday = 0;
	fecha.tm_mon = 0;
	fecha.tm_year = 0;
	fecha.tm_wday = 0;
	fecha.tm_yday = 0;
	fecha.tm_isdst = 0;
}

cFecha::cFecha(int dia, int mes, int anio, int hora, int minutos) {
	fecha.tm_hour = hora;
	fecha.tm_min = minutos;
	fecha.tm_sec = 0;
	fecha.tm_mday = dia;
	fecha.tm_mon = mes;
	fecha.tm_year = anio;
	fecha.tm_wday = 0;
	fecha.tm_yday = 0;
	fecha.tm_isdst = 0;
}

cFecha::~cFecha() {

}

string cFecha::to_stringFecha() {
	return "\tFecha: " + to_string(fecha.tm_wday) + "/" + to_string(fecha.tm_mon) + "/" + to_string(fecha.tm_year) +
		"\t Hora:" + to_string(fecha.tm_hour) + ":" + to_string(fecha.tm_min);
}
void cFecha::imprimir() {
	cout << to_stringFecha() << endl;
}