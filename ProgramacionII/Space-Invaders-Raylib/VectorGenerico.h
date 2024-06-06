#pragma once

#include <exception>
#include <stdexcept>
#include <string>
#include <algorithm>

template<typename T>
class VectorGenerico {
public:
    VectorGenerico();
    explicit VectorGenerico(int cantidadMaxima);
    ~VectorGenerico();

    void registrar(T elemento);
    T& operator[](int posicion);  // Devuelve una referencia
    //T& operator[](int posicion) const;  // Devuelve una referencia constante
    int getCantidadActual() const;

    void eliminar(int posicion);

    void ordenar(bool (*comparador)(T a, T b));
    T buscar(T elementoBuscado, bool (*comparador)(T elemento, T buscado)) const;

private:
    T* vector;
    int cantidadActual;
    int cantidadMaxima;

    void validarPosicion(int posicion) const;
};

template<typename T>
VectorGenerico<T>::VectorGenerico()
    : vector(nullptr), cantidadActual(0), cantidadMaxima(0) {
}

template<typename T>
VectorGenerico<T>::VectorGenerico(int cantidadMaxima)
    : cantidadActual(0), cantidadMaxima(cantidadMaxima) {
    if (cantidadMaxima <= 0) {
        throw std::invalid_argument("La cantidad máxima debe ser mayor que cero.");
    }
    vector = new T[cantidadMaxima];
}

template<typename T>
VectorGenerico<T>::~VectorGenerico() {
    //delete[] vector;
}

template<typename T>
void VectorGenerico<T>::registrar(T elemento) {
    if (cantidadActual >= cantidadMaxima) {
        throw std::out_of_range("No se puede registrar más elementos, vector lleno.");
    }
    vector[cantidadActual++] = elemento;
}

template<typename T>
T& VectorGenerico<T>::operator[](int posicion) {  // Devuelve una referencia
    //validarPosicion(posicion);
    return vector[posicion];
}
/*
template<typename T>
T& VectorGenerico<T>::operator[](int posicion) const {  // Devuelve una referencia constante
    //validarPosicion(posicion);
    return vector[posicion];
}*/

template<typename T>
int VectorGenerico<T>::getCantidadActual() const {
    return cantidadActual;
}

template<typename T>
void VectorGenerico<T>::eliminar(int posicion) {
    validarPosicion(posicion);

    for (int i = posicion; i < cantidadActual - 1; ++i) {
        vector[i] = vector[i + 1];
    }
    cantidadActual--;
}


template<typename T>
void VectorGenerico<T>::ordenar(bool (*comparador)(T a, T b)) {
    for (int i = 0; i < cantidadActual - 1; ++i) {
        for (int j = 0; j < cantidadActual - 1 - i; ++j) {
            if (comparador(vector[j + 1], vector[j])) {
                std::swap(vector[j], vector[j + 1]);
            }
        }
    }
}

template<typename T>
T VectorGenerico<T>::buscar(T elementoBuscado, bool (*comparador)(T elemento, T buscado)) const {
    for (int i = 0; i < cantidadActual; ++i) {
        if (comparador(vector[i], elementoBuscado)) {
            return vector[i];
        }
    }
    throw std::runtime_error("No existe el elemento buscado.");
}

template<typename T>
void VectorGenerico<T>::validarPosicion(int posicion) const {
    if (posicion < 0 || posicion >= cantidadActual) {
        throw std::out_of_range("Posición fuera de rango.");
    }
}
