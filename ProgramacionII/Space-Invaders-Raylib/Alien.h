#pragma once
#include "Dibujo.h"
#include "VectorGenerico.h"

class Alien : public Dibujo
{
private:
    bool estaVivo;
    int vida;
    int tipoAlien;
public:
    Alien(Vector2 posicion, int tipoAlien, Color colorGeneral);
    Alien();
    ~Alien();

    int& getVida();
    int& getTipo();
    bool& getEstaVivo();
};


