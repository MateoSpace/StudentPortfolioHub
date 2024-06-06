#pragma once

#include <iostream>
#include "raylib.h"
#include "MatrizGenerica.h"

class Dibujo {
protected:
    Vector2 posicion;
    MatrizGenerica<int> grid;
    Rectangle rectangulo;
    Color colorGeneral;
public:
    Dibujo(Vector2 posicion, int filas, int columnas, Color colorGeneral);
    Dibujo();
    ~Dibujo();

    Color& GetColor();
    Vector2& GetPosicion();
    MatrizGenerica<int>& GetGrid();

    void SetRectangulox(int width);
    void SetRectanguloy(int height);

    void Draw();
};
