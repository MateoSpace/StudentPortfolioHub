#pragma once

#include <exception>
#include <string>

using namespace std;

// T es un tipo generico que puede una variable primitiva 
// o compleja (clases, punteros)
template<typename T>
class VectorGenerico
{
public:
	VectorGenerico();
	VectorGenerico(int cantidadMaxima);
	void registrar(T elemento);
	T operator[](int posicion);
	int getCantidadActual();
	
	void ordenar(bool (*comparador)(T a, T b));
	T buscar(T elementoBuscado, bool (*comparador)(T elemento, T buscado)); // ==
private:
	T* vector;
	int cantidadActual;
	int cantidadMaxima;
};

template<typename T>
VectorGenerico<T>::VectorGenerico(int cantidadMaxima)
{
	this->cantidadActual = 0;
	this->cantidadMaxima = cantidadMaxima;
	vector = new T[cantidadMaxima];///////////// error
}

template<typename T>
VectorGenerico<T>::VectorGenerico()
	: vector(nullptr), cantidadActual(0), cantidadMaxima(0)
{
}

template<typename T>
void VectorGenerico<T>::registrar(T elemento)
{
	if (cantidadActual < cantidadMaxima)
	{
		vector[cantidadActual] = elemento;
		cantidadActual++;
	}
	else
	{
		throw exception("Se llego al limite de elementos");
	}
}

template<typename T>
T VectorGenerico<T>::operator[](int posicion)
{
	if (posicion < cantidadMaxima)
	{
		return vector[posicion];
	}
	throw exception("No existe la posicion");
}

template<typename T>
inline int VectorGenerico<T>::getCantidadActual()
{
	return cantidadActual;
}

template<typename T>
inline void VectorGenerico<T>::ordenar(bool (*comparador)(T a, T b))
{
	for (int i = 0; i < cantidadActual; i++)
	{
		for (int j = 0; j < cantidadActual - 1; j++)
		{
			// bool comparador(T a, T b);
			// if (vector[j] > vector[j + 1])
			if (comparador(vector[j], vector[j + 1]))
			{
				swap(vector[j], vector[j + 1]);
			}
		}
	}
}

template<typename T>
T VectorGenerico<T>::buscar(T elementoBuscado, bool (*comparador)(T elemento, T buscado))
{
	for (int i = 0; i < cantidadActual; i++)
	{
		// bool comparador(T elementoDelVector, T buscado);
		// vector[i] = elementoDelVector
		// if (vector[i] == buscado)
		if (comparador(vector[i], elementoBuscado))
		{
			return vector[i];
		}
	}
	throw exception("No existe el elemento");
}
