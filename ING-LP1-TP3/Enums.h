#pragma once
#include <string>
#include <iostream>
using namespace std;

enum class ePrioridad { Urgente = 0, Alta, Media, Baja };
enum class eSexo { Masculino = 0, Femenino };
enum class eTipoDeOrgano { Corazon = 0, Higado, Pancreas, Huesos, Rinion, Pulmones, Intestino, Piel, Corneas };
enum class eTipoDeSangre { AB_Positivo = 0, AB_Negativo, A_Positivo, A_Negativo, B_positivo, B_Negativo, O_Positivo, O_Negativo };
enum class eEstadoReceptor { Estable = 0, Inestable };


string PrioridadToString(ePrioridad prioridad);
string SexoToString(eSexo sexo);
string TipoDeOrganoToString(eTipoDeOrgano organo);
string TipoDeSangreToString(eTipoDeSangre sangre);
string EstadoReceptorToString(eEstadoReceptor estadoreceptor);
