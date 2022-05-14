#include"Enums.h"

string PrioridadToString(ePrioridad prioridad) {
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

string SexoToString(eSexo sexo) {
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

string TipoDeOrganoToString(eTipoDeOrgano organo) {
	switch (organo)
	{
	case eTipoDeOrgano::Corazon:
		return"Corazon";
		break;
	case eTipoDeOrgano::Higado:
		return"Higado";
		break;
	case eTipoDeOrgano::Pancreas:
		return"Pancreas";
		break;
	case eTipoDeOrgano::Huesos:
		return"Huesos";
		break;
	case eTipoDeOrgano::Rinion:
		return"Riñon";
		break;
	case eTipoDeOrgano::Pulmones:
		return"Pulmones";
		break;
	case eTipoDeOrgano::Intestino:
		return"Intestino";
		break;
	case eTipoDeOrgano::Piel:
		return"Piel";
		break;
	case eTipoDeOrgano::Corneas:
		return"Corneas";
		break;
	default:
		return "";
		break;
	}
}

string TipoDeSangreToString(eTipoDeSangre sangre) {
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

string EstadoReceptorToString(eEstadoReceptor estadoreceptor) {
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