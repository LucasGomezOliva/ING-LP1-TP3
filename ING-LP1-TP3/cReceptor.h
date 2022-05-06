#include"cPaciente.h"
#include"Prioridad.h"
#include"EstadoReceptor.h"
using namespace std;
class cReceptor :public cPaciente
{
public:
	//organo a recibir
	cFecha* FechaListaEspera = NULL;
	Prioridad PrioridadReceptor;
	string Patologia;
	EstadoReceptor Estado;
private:
	cReceptor();
	cReceptor(cFecha* FechaListaEspera, Prioridad prioridad, string Patologia, EstadoReceptor Estado);
	~cReceptor();
};