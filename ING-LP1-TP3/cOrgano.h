#pragma once
#include "cFecha.h"
#include"Enums.h"
using namespace std;
class cOrgano
{
private:
	eTipoDeOrgano Organo;
	cFecha* FechaAbleacion = NULL;
public:
	cOrgano();
	cOrgano(eTipoDeOrgano Organo);
	virtual~cOrgano();
	eTipoDeOrgano getTipo() const { return Organo; };
	void setFechaAbleacion(int DiaAbleacion, int MesAbleacion, int AnioAbleacion, int HoraAbleacion, int MinutosAbleacion);
	cFecha* GetFechaAbleacion();
	bool operator==(const cOrgano& OtroOrgano);
	friend ostream& operator<<(ostream& os, const cOrgano* organo);
};

