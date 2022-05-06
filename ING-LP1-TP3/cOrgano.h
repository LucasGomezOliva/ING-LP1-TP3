#pragma once
#include "cFecha.h"
using namespace std;

class cOrgano
{
private:
	cFecha* Ableacion = NULL;
public:
	cOrgano();
	virtual~cOrgano();
};

