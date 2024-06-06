#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include "VectorGenerico.h"

template<typename T>
class MatrizGenerica {
public:
    MatrizGenerica(int filas, int columnas);
    MatrizGenerica();
    ~MatrizGenerica() = default;

    VectorGenerico<T>& operator[](int fila);
    //VectorGenerico<T>& operator[](int fila) const;
    int getFilas() const;
    int getColumnas() const;

private:
    VectorGenerico<VectorGenerico<T>> matriz;
    int filas;
    int columnas;

    void validarFila(int fila) const;
};

template<typename T>
MatrizGenerica<T>::MatrizGenerica(int filas, int columnas)
    : filas(filas), columnas(columnas), matriz(filas) {
    //std::cout << "FFF " << filas << " Colum " << columnas << std::endl;

    if (filas <= 0 || columnas <= 0) {
        throw std::invalid_argument("El número de filas y columnas debe ser mayor que cero.");
    }
    for (int i = 0; i < filas; ++i) {
        matriz.registrar(VectorGenerico<T>(columnas));
    }
}

template<typename T>
inline MatrizGenerica<T>::MatrizGenerica()
{
    for (int i = 0; i < 8; ++i) {
        matriz.registrar(VectorGenerico<T>(10));
    }
}

template<typename T>
VectorGenerico<T>& MatrizGenerica<T>::operator[](int fila) {
    validarFila(fila);
    return matriz[fila];  // Asegúrate de que `matriz` devuelva una referencia
}
/*
template<typename T>
VectorGenerico<T>& MatrizGenerica<T>::operator[](int fila) const {
    validarFila(fila);
    return matriz[fila];  // Asegúrate de que `matriz` devuelva una referencia
}*/

template<typename T>
int MatrizGenerica<T>::getFilas() const {
    return filas;
}

template<typename T>
int MatrizGenerica<T>::getColumnas() const {
    return columnas;
}

template<typename T>
void MatrizGenerica<T>::validarFila(int fila) const {
    if (fila < 0 || fila >= filas) {
        throw std::out_of_range("Índice de fila fuera de rango");
    }
}
