#pragma once
#include "cFecha.h"
using namespace std;

class cOrgano
{
private:
	// corazón, hígado, páncreas, huesos, riñón, pulmones, intestino, piel y córneas
	string Organo;
	cFecha* FechaAbleacion = NULL;
public:
	cOrgano();
	virtual~cOrgano();
	void setFechaAbleacion(int DiaAbleacion, int MesAbleacion, int AnioAbleacion, int HoraAbleacion, int MinutosAbleacion);
	/*
	bool operator==(const cOrgano& OtroOrgano) {
		if (Organo == OtroOrgano.getTipoOrgano()){
		return True;
		}
		return false;
	}
	
	friend ostream& operator<<(ostream& os, const cOrgano* organo) {
		os << organo->ToStringOrgano();
		return os;
	}
	*/
};

