#pragma once
#include <iostream>
#include "raylib.h"
#include "VectorGenerico.h"

class Dibujo
{
protected:
    Vector2 posicion;
    VectorGenerico<VectorGenerico<int>> grid;
    Rectangle rectangulo;
    Color colorGeneral;
public:
    Dibujo(Vector2 posicion, VectorGenerico<VectorGenerico<int>> grid, Color colorGeneral);
    ~Dibujo();

    Color& GetColor();
    Vector2& GetPosicion();

    void SetRectangulox(int width);
    void SetRectanguloy(int height);

    void Draw();
};
