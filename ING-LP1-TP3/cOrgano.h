#pragma once
#include "cFecha.h"
using namespace std;

class cOrgano
{
private:
	// coraz�n, h�gado, p�ncreas, huesos, ri��n, pulmones, intestino, piel y c�rneas
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

