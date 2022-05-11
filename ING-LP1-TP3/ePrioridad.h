#pragma once
#include <string>
#include <iostream>
using namespace std;

enum class ePrioridad { Urgente, Alta, Media, Baja };

inline string PrioridadToString(ePrioridad prioridad) {
	switch (prioridad)
	{
	case ePrioridad::Urgente:
		return"Urgente";
		break;
	case ePrioridad::Alta:
		return"Alta";
		break;
	case ePrioridad::Media:
		return"Media";
		break;
	case ePrioridad::Baja:
		return"Baja";
		break;
	default:
		return "";
		break;
	}
}