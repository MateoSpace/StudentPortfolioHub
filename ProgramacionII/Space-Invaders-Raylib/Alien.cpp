#include "Alien.h"
#include <iostream>

Alien::Alien(Vector2 posicion, int tipoAlien, Color colorGeneral)
    : Dibujo(posicion, VectorGenerico<VectorGenerico<int>>(8), colorGeneral), tipoAlien(tipoAlien), estaVivo(true), vida(100)
{
    VectorGenerico<VectorGenerico<int>> MatrizPrueba(8);

    switch (tipoAlien)
    {
    case 1:
    {
        int Patron[8][10] = {
            {0,0,0,1,1,1,1,0,0,0},
            {0,1,1,1,1,1,1,1,1,0},
            {1,1,1,1,1,1,1,1,1,1},
            {1,0,0,1,1,1,1,0,0,1},
            {1,1,1,1,1,1,1,1,1,1},
            {0,0,1,0,0,0,0,1,0,0},
            {0,1,0,1,1,1,1,0,1,0},
            {1,0,0,0,0,0,0,0,0,1}
        };
        for (int i = 0; i < 8; i++) {
            VectorGenerico<int> listaInterna(10);
            for (int j = 0; j < 10; j++) {
                listaInterna.registrar(Patron[i][j]);
            }
            MatrizPrueba.registrar(listaInterna);
        }
        break;
    }
    case 2:
    {
        int Patron[8][10] = {
            {0,0,1,0,0,0,0,1,0,0},
            {0,0,0,1,1,1,1,0,0,0},
            {0,0,1,1,1,1,1,1,0,0},
            {0,1,1,0,1,1,0,1,1,0},
            {1,1,1,1,1,1,1,1,1,1},
            {1,0,1,1,1,1,1,1,0,1},
            {0,0,0,1,0,0,1,0,0,0},
            {0,0,1,0,0,0,0,1,0,0}
        };
        for (int i = 0; i < 8; i++) {
            VectorGenerico<int> listaInterna(10);
            for (int j = 0; j < 10; j++) {
                listaInterna.registrar(Patron[i][j]);
            }
            MatrizPrueba.registrar(listaInterna);
        }
        break;
    }
    case 3:
    {
        int Patron[8][10] = {
            {0,0,0,0,1,0,0,0,0,0},
            {0,0,0,1,1,1,0,0,0,0},
            {0,0,1,1,1,1,1,0,0,0},
            {0,1,0,0,1,0,0,1,0,0},
            {1,1,1,1,1,1,1,1,1,0},
            {0,0,1,1,1,1,1,0,0,0},
            {0,1,0,0,1,0,0,1,0,0},
            {1,0,0,1,0,1,0,0,1,0} };
        for (int i = 0; i < 8; i++) {
            VectorGenerico<int> listaInterna(10);
            for (int j = 0; j < 10; j++) {
                listaInterna.registrar(Patron[i][j]);
            }
            MatrizPrueba.registrar(listaInterna);
        }
        break;
    }
    case 4:
    {
        int Patron[8][10] = {
            {0,0,1,0,0,0,0,1,0,0},
            {0,0,0,1,1,1,1,0,0,0},
            {0,0,1,1,1,1,1,1,0,0},
            {0,1,1,0,1,1,0,1,1,0},
            {1,1,1,1,1,1,1,1,1,1},
            {1,0,1,1,1,1,1,1,0,1},
            {0,0,0,1,0,0,1,0,0,0},
            {0,0,1,0,0,0,0,1,0,0}
        };
        for (int i = 0; i < 8; i++) {
            VectorGenerico<int> listaInterna(10);
            for (int j = 0; j < 10; j++) {
                listaInterna.registrar(Patron[i][j]);
            }
            MatrizPrueba.registrar(listaInterna);
        }
        break;
    }
    default:
        break;
    }

    this->grid = MatrizPrueba;
}

Alien::Alien() : Dibujo({ 0,0 }, VectorGenerico<VectorGenerico<int>>(8), WHITE), tipoAlien(1), estaVivo(true), vida(2)
{
}

Alien::~Alien()
{
}

int& Alien::getVida()
{
    return vida;
}

int& Alien::getTipo()
{
    return tipoAlien;
}

bool& Alien::getEstaVivo()
{
    return estaVivo;
}
