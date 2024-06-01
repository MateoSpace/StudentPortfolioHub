#pragma once

#include <exception>
#include <string>
#include <stdexcept>
#include "VectorGenerico.h"

using namespace std;

template<typename T>
class MatrizGenerica {
public:
    MatrizGenerica(int filas, int columnas);
    ~MatrizGenerica();

    void registrar(int fila, int columna, T elemento);
    T obtener(int fila, int columna);
    int getFilas();
    int getColumnas();

private:
    int filas;
    int columnas;
    VectorGenerico<VectorGenerico<T>> matriz;
};

template<typename T>
MatrizGenerica<T>::MatrizGenerica(int filas, int columnas) : filas(filas), columnas(columnas), matriz(filas) {
    for (int i = 0; i < filas; i++) {
        matriz.registrar(VectorGenerico<T>(columnas));
    }
}

template<typename T>
MatrizGenerica<T>::~MatrizGenerica() {
    // No es necesario liberar memoria explícitamente porque VectorGenerico se encarga de eso
}

template<typename T>
void MatrizGenerica<T>::registrar(int fila, int columna, T elemento) {
    if (fila < 0 || fila >= filas || columna < 0 || columna >= columnas) {
        throw out_of_range("Índice fuera de rango");
    }
    matriz[fila].registrar(elemento);
}

template<typename T>
T MatrizGenerica<T>::obtener(int fila, int columna) {
    if (fila < 0 || fila >= filas || columna < 0 || columna >= columnas) {
        throw out_of_range("Índice fuera de rango");
    }
    return matriz[fila][columna];
}

template<typename T>
int MatrizGenerica<T>::getFilas() {
    return filas;
}

template<typename T>
int MatrizGenerica<T>::getColumnas() {
    return columnas;
}


