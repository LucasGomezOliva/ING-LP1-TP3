#pragma once
#include <string>
#include <iostream>
using namespace std;

enum class eSexo { Masculino,Femenino };

inline string SexoToString(eSexo sexo) {
	switch (sexo)
	{
	case eSexo::Masculino:
		return"Masculino";
		break;
	case eSexo::Femenino:
		return"Femenino";
		break;
	default:
		return "";
		break;
	}
}