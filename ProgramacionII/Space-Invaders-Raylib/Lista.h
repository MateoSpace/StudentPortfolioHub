#pragma once
#include "Nodo.h"

template<class T>
class Lista
{
private:
	Nodo<T>* primerNodo;
	Nodo<T>* ultimoNodo;

public:
	Lista();
	~Lista();

	bool vacio();
	void registrar(T* dato);
	string toJson(string(*toJson)(T*));
	T* buscar(T* dato);
	void ordenar(bool(funcComp)(T*, T*));
};

template<class T>
Lista<T>::Lista()
{
	primerNodo = NULL;
	ultimoNodo = NULL;
}

template<class T>
Lista<T>::~Lista()
{
	Nodo<T>* current = primerNodo;
	Nodo<T>* siguiente;

	while (current != nullptr) {
		siguiente = current->siguiente;
		delete current;
		current = siguiente;
	}

	primerNodo = nullptr;
	ultimoNodo = nullptr;
}

template<class T>
bool Lista<T>::vacio()
{
	return primerNodo == NULL;
}

template<class T>
void Lista<T>::registrar(T* dato)
{
	if (primerNodo == NULL)
	{
		primerNodo = new Nodo<T>(dato);
	}
	else
	{
		Nodo<T>* tmp = primerNodo;
		while (tmp->getSig() != NULL)
		{
			tmp = tmp->getSig();
		}
		tmp->crearSig(dato);
	}
}

template<class T>
string Lista<T>::toJson(string(*toJson)(T*))
{
	stringstream ss;
	ss << "[";
	Nodo<T>* tmp = primerNodo;
	while (tmp != NULL)
	{
		ss << (*toJson)(tmp->getDato());

		if (tmp->getSig() != NULL)
		{
			ss << ",";
		}
		tmp = tmp->getSig();
	}
	ss << "]";
	return ss.str();
}

template<class T>
T* Lista<T>::buscar(T* dato)
{
	Nodo<T>* tmp = primerNodo;
	while (tmp != NULL)
	{
		if (*(tmp->getDato()) == *dato) {
			return tmp->getDato();
		}
		tmp = tmp->getSig();
	}
	return NULL;
}

template<class T>
void Lista<T>::ordenar(bool(funcComp)(T*, T*))
{
	if (!primerNodo)
	{
		return;
	}
	Nodo<T>* current = primerNodo;
	while (current)
	{
		Nodo<T>* minNode = current;
		Nodo<T>* siguiente = current->getSig();

		while (siguiente) {
			if (funcComp(siguiente->getDato(), minNode->getDato())) {
				minNode = siguiente;
			}
			siguiente = siguiente->getSig();
		}
		if (current != minNode) {
			T* temp = current->getDato();
			current->setDato(minNode->getDato());
			minNode->setDato(temp);
		}
		current = current->getSig();
	}
}
