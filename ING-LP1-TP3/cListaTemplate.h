#pragma once
#include <exception>
#include <string>
#include <iostream>
using namespace std;
#define SIZE 100
template <class T>
class cListaTemplate
{
protected:
	T** Array;
	unsigned int CA, TAM;
	bool on_delete_erase;
	bool allow_duplicates;

public:
	cListaTemplate(unsigned int TAM = SIZE, bool on_delete_erase = false);
	~cListaTemplate();
	void Agregar(T* objeto);
	T* Quitar(T* objeto);
	int getPos(T* objeto);
	void Listar();
	void operator+(T* objeto);
	void operator-(T* objeto);
	T* operator[](unsigned int pos);
};

template <class T>
inline cListaTemplate <T>::cListaTemplate(unsigned int TAM, bool on_delete_erase) {
	this->TAM = TAM;
	CA = 0;
	Array = new T * [TAM];
	for (unsigned int i = 0; i < TAM; i++){
		Array[i] = NULL;
	}
	this->on_delete_erase = on_delete_erase;
	this->allow_duplicates = false;
}

template <class T>
inline cListaTemplate <T>::~cListaTemplate() {
	if (Array != NULL) {
		if (on_delete_erase) {
			for (unsigned int i = 0; i < CA; i++) {
				if (Array[i] != NULL)
					delete Array[i];
			}
		}
		delete[] Array;
	}
	Array = NULL;
}

template <class T>
inline void cListaTemplate <T>::Agregar(T* objeto) {

	int pos = getPos(objeto);
	bool hay_lugar = CA < TAM;
	if (!hay_lugar)
		throw exception("No Hay Lugar");
	if (pos >= 0 && !allow_duplicates)
		throw exception("ya esta en la lista");
	Array[CA++] = objeto;
}

template <class T>
inline T*cListaTemplate <T>::Quitar(T* objeto) {
	int pos = getPos(objeto);
	if (pos < 0)
		return NULL;
	T* aux = Array[pos];
	for (unsigned int i = pos; i < CA - 1; i++) {
		Array[i] = Array[i + 1];
	}
	CA--;
	Array[CA] = NULL;
	return aux;
}

template <class T>
inline int cListaTemplate <T>::getPos(T* objeto) {
	for (unsigned int i = 0; i < CA; i++) {
		// sobrecarga de ==
		if (*objeto == *(Array[i]))
			return i;
	}
	return -1;
}

template <class T>
inline void cListaTemplate <T>::Listar() {
	for (unsigned int i = 0; i < CA; i++) {
		//sobrecarga <<
		cout << *Array[i] << endl;
	}
}

	//sobrecarga de operadores
template <class T>
inline void cListaTemplate <T>::operator+(T* objeto) {
	Agregar(objeto);
}

template <class T>
void cListaTemplate <T>::operator-(T* objeto) {
	Quitar(objeto);
}

template <class T>
inline T* cListaTemplate <T>::operator[](unsigned int pos) {
	if (pos < CA)
		return Array[pos];
	else
		return NULL;
}
