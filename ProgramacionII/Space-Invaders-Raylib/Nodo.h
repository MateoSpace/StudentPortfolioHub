#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <class T>
class Nodo
{
private:
	T* dato;
	Nodo<T>* sig;
public:
	Nodo(T* dato);
	~Nodo();

	T* getDato();
	Nodo<T>* getSig();

	void setDato(T* dato);
	void setSig(Nodo<T>* sig);

	void crearSig(T* dato);
};


template<class T>
Nodo<T>::Nodo(T* dato)
{
	this->dato = dato;
	sig = NULL;
}

template<class T>
Nodo<T>::~Nodo()
{
}

template<class T>
T* Nodo<T>::getDato()
{
	return dato;
}

template<class T>
Nodo<T>* Nodo<T>::getSig()
{
	return sig;
}

template<class T>
void Nodo<T>::setDato(T* dato)
{
	this->dato = dato;
}

template<class T>
void Nodo<T>::setSig(Nodo<T>* sig)
{
	this->sig = sig;
}

template<class T>
void Nodo<T>::crearSig(T* dato)
{
	sig = new Nodo<T>(dato);
}
