#pragma once
#include "Lista.h"
#include "raylib.h"


class Dibujo
{
private:
    Vector2 posicion;
    Matrix grid;
    Rectangle  rectangulo;
    Color colorGeneral;
public:
    Dibujo(Vector2 position, Matrix grid, Color colorGeneral);
    ~Dibujo();
    Color& GetColor();
    Vector2& GetPosicion();

    void Draw();
};

