#pragma once
#include"cPaciente.h"
using namespace std;
class cDonante :public cPaciente
{
public:
	cFecha* Falleciemiento = NULL;
	cFecha* ComienzoAbleacion = NULL;
	//lista de organos
private:
	cDonante();
	~cDonante();
};

