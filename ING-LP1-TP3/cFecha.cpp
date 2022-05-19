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
	fecha.tm_mon = mes - 1;
	fecha.tm_year = anio - 1900;
	fecha.tm_wday = 0;
	fecha.tm_yday = 0;
	fecha.tm_isdst = 0;
}

cFecha::~cFecha() {

}

bool cFecha::CompararFechas(cFecha* fecha) { ///comparar 2 fechas para la diferencia de 20h
	int timedif = 0;
	time_t FechaActual = 0;
	time(&FechaActual);
	time_t fecha1 = mktime(&(fecha->fecha));
	timedif = difftime(FechaActual, fecha1);
	if (timedif < 72000)
		return true;
	else
		return false;
}

string cFecha::to_stringFecha() const {
	return "\tFecha: " + to_string(fecha.tm_mday) + "/" + to_string(fecha.tm_mon + 1) + "/" + to_string(fecha.tm_year + 1900) +
		"\t Hora:" + to_string(fecha.tm_hour) + ":" + to_string(fecha.tm_min);
}

void cFecha::imprimir() const {
	cout << to_stringFecha() << endl;
}