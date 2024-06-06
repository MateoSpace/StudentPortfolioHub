#pragma once
#include "Dibujo.h"
#include "MatrizGenerica.h"

class Alien : public Dibujo
{
private:
    bool estaVivo;
    int tipoAlien;
public:
    Alien(Vector2 posicion, int tipoAlien, Color colorGeneral);
    Alien();
    ~Alien() = default;

    int getTipo() const;
    bool isVivo() const;
    void setVivo(bool estado);
};
