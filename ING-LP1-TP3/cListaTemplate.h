#pragma once
#include <exception>
#include <string>
#include <iostream>
using namespace std;
#define SIZE 100
template <class T, class U = string>
class cListaTemplate
{
	T** Array;
	int CA, TAM;
	bool on_delete_erase;
	bool allow_duplicates;

public:

	cListaTemplate(int TAM = SIZE, bool on_delete_erase = false) {
		this->TAM = TAM;
		CA = 0;
		Array = new T * [TAM];
		for (int i = 0; i < TAM; i++)
		{
			Array[i] = NULL;
		}
		this->on_delete_erase = on_delete_erase;
		allow_duplicates = false;
	}

	~cListaTemplate() {
		if (Array != NULL) {
			if (on_delete_erase) {
				for (int i = 0; i < CA; i++) {
					if (Array[i] != NULL)
						delete Array[i];
				}
			}
			delete[] Array;
		}
		Array = NULL;
	}

	void Agregar(T* objeto) {

		int pos = getPos(objeto);
		bool hay_lugar = CA < TAM;
		if (!hay_lugar)
			throw exception("No Hay Lugar");
		if (pos >= 0 && !allow_duplicates)
			throw exception("ya esta en la lista");

		Array[CA++] = objeto;
	}

	T* Quitar(T* objeto) {
		int pos = getPos(objeto);
		if (pos < 0)
			return NULL;
		T* aux = Array[pos];
		for (int i = pos; i < CA - 1; i++) {
			Array[i] = Array[i + 1];
		}
		CA--;
		Array[CA] = NULL;
		return aux;
	}

	T* Quitar(U clave) {
		int pos = getPos(clave);
		if (pos < 0)
			return NULL;
		T* aux = Array[pos];
		for (int i = pos; i < CA - 1; i++) {
			Array[i] = Array[i + 1];
		}
		CA--;
		Array[CA] = NULL;
		return aux;

	}

	int getPos(T* objeto) {
		for (int i = 0; i < CA; i++) {
			// sobrecarga de ==
			if (*objeto == *(Array[i]))
				return i;
		}
		return -1;
	}

	int getPos(U clave) {
		for (int i = 0; i < CA; i++) {
			// sobrecarga de == con string
			if ((*Array[i]) == clave)
				return i;
		}
		return -1;

	}

	void Listar() {
		for (int i = 0; i < CA; i++) {
			//sobrecarga <<
			cout << *Array[i] << endl;
		}

	}

	//sobrecarga de operadores

	void operator+(T* objeto) {
		Agregar(objeto);
	}

	void operator-(T* objeto) {
		Quitar(objeto);
	}

	T* operator[](unsigned int pos) {
		if (pos < CA)
			return Array[pos];
		else
			return NULL;
	}
};