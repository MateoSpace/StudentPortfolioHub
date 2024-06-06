#include "Alien.h"
#include <iostream>

Alien::Alien(Vector2 posicion, int tipoAlien, Color colorGeneral)
    : Dibujo(posicion, 8, 10, colorGeneral), tipoAlien(tipoAlien), estaVivo(true)
{
    MatrizGenerica<int> MatrizPrueba(8, 10);

    const int Patron1[8][10] = {
        {0,0,0,1,1,1,1,0,0,0},
        {0,1,1,1,1,1,1,1,1,0},
        {1,1,1,1,1,1,1,1,1,1},
        {1,0,0,1,1,1,1,0,0,1},
        {1,1,1,1,1,1,1,1,1,1},
        {0,0,1,0,0,0,0,1,0,0},
        {0,1,0,1,1,1,1,0,1,0},
        {1,0,0,0,0,0,0,0,0,1}
    };

    const int Patron2[8][10] = {
        {0,0,1,0,0,0,0,1,0,0},
        {0,0,0,1,1,1,1,0,0,0},
        {0,0,1,1,1,1,1,1,0,0},
        {0,1,1,0,1,1,0,1,1,0},
        {1,1,1,1,1,1,1,1,1,1},
        {1,0,1,1,1,1,1,1,0,1},
        {0,0,0,1,0,0,1,0,0,0},
        {0,0,1,0,0,0,0,1,0,0}
    };

    const int Patron3[8][10] = {
        {0,0,0,0,1,0,0,0,0,0},
        {0,0,0,1,1,1,0,0,0,0},
        {0,0,1,1,1,1,1,0,0,0},
        {0,1,0,0,1,0,0,1,0,0},
        {1,1,1,1,1,1,1,1,1,0},
        {0,0,1,1,1,1,1,0,0,0},
        {0,1,0,0,1,0,0,1,0,0},
        {1,0,0,1,0,1,0,0,1,0}
    };

    const int Patron4[8][10] = {
        {0,0,1,0,0,0,0,1,0,0},
        {0,0,0,1,1,1,1,0,0,0},
        {0,0,1,1,1,1,1,1,0,0},
        {0,1,1,0,1,1,0,1,1,0},
        {1,1,1,1,1,1,1,1,1,1},
        {1,0,1,1,1,1,1,1,0,1},
        {0,0,0,1,0,0,1,0,0,0},
        {0,0,1,0,0,0,0,1,0,0}
    };

    const int(*patron)[10] = nullptr;

    switch (tipoAlien) {
    case 1: patron = Patron1; break;
    case 2: patron = Patron2; break;
    case 3: patron = Patron3; break;
    case 4: patron = Patron4; break;
    default: throw std::invalid_argument("Tipo de alien no válido");
    }

    for (int i = 0; i < 8; ++i) {
        MatrizPrueba[i].registrar(10);
        for (int j = 0; j < 10; ++j) {
            MatrizPrueba[i][j] = patron[i][j];
        }
    }

    this->grid = MatrizPrueba;
}

Alien::Alien()
    : Dibujo({ 0,0 }, 8, 10, WHITE), tipoAlien(1), estaVivo(true)
{
}

int Alien::getTipo() const {
    return tipoAlien;
}

bool Alien::isVivo() const {
    return estaVivo;
}

void Alien::setVivo(bool estado) {
    estaVivo = estado;
}

