#pragma once
#include <string>
#include <iostream>
using namespace std;

enum class eTipoDeSangre { AB_Positivo, AB_Negativo, A_Positivo, A_Negativo, B_positivo, B_Negativo, O_Positivo, O_Negativo};

inline string TipoDeSangreToString(eTipoDeSangre sangre) {
	switch (sangre)
	{
	case eTipoDeSangre::AB_Positivo:
		return"Tipo de sangre: AB + ";
		break;
	case eTipoDeSangre::AB_Negativo:
		return"Tipo de sangre: AB - ";
		break;
	case eTipoDeSangre::A_Positivo:
		return"Tipo de sangre: A + ";
		break;
	case eTipoDeSangre::A_Negativo:
		return"Tipo de sangre: A- ";
		break;
	case eTipoDeSangre::B_positivo:
		return"Tipo de sangre: B + ";
		break;
	case eTipoDeSangre::B_Negativo:
		return"Tipo de sangre: B - ";
		break;
	case eTipoDeSangre::O_Positivo:
		return"Tipo de sangre: O + ";
		break;
	case eTipoDeSangre::O_Negativo:
		return"Tipo de sangre: O - ";
		break;
	default:
		return "";
		break;
	}
}