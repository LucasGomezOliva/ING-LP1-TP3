#pragma once
#include <string>
#include <iostream>
using namespace std;

enum class eEstadoReceptor { Estable, Inestable };

inline string EstadoReceptorToString(eEstadoReceptor estadoreceptor) {
	switch (estadoreceptor)
	{
	case eEstadoReceptor::Estable:
		return"Estable";
		break;
	case eEstadoReceptor::Inestable:
		return"Inestable";
		break;
	default:
		return "";
		break;
	}
}