#include "Dibujo.h"
#include <iostream> // Necesario para cout

Dibujo::Dibujo(Vector2 posicion, int filas, int columnas, Color colorGeneral)
    : posicion(posicion), grid(filas, columnas), colorGeneral(colorGeneral) {
    rectangulo.width = 3;
    rectangulo.height = 3;
}

Dibujo::Dibujo()    : posicion({0,0}), grid(8, 10), colorGeneral(WHITE) {
    rectangulo.width = 3;
    rectangulo.height = 3;
}

Dibujo::~Dibujo()
{
}

Color& Dibujo::GetColor() {
    return colorGeneral;
}

Vector2& Dibujo::GetPosicion() {
    return posicion;
}

MatrizGenerica<int>& Dibujo::GetGrid()
{
    return grid;
}

void Dibujo::SetRectangulox(int width) {
    rectangulo.width = static_cast<float>(width);
}

void Dibujo::SetRectanguloy(int height) {
    rectangulo.height = static_cast<float>(height);
}

void Dibujo::Draw() {
    //std::cout << "Filas *" << grid.getFilas() << std::endl;
    //std::cout << "Columnas *" << grid.getColumnas() << std::endl;
    Vector2 auxPosicion = posicion;
    for (int filas = 0; filas < grid.getFilas(); ++filas) {
        for (int columnas = 0; columnas < grid.getColumnas(); ++columnas) {
            if (grid[filas][columnas] == 1) {
                this->rectangulo.x = static_cast<float>(auxPosicion.x + columnas * rectangulo.width);
                this->rectangulo.y = static_cast<float>(auxPosicion.y + filas * rectangulo.height);
                DrawRectangleRec(rectangulo, colorGeneral);
            }
        }
    }
    //DrawRectangle(10, 40, 10, 10, colorGeneral);
}
