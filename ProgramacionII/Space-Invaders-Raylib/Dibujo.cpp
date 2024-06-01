#include "Dibujo.h"
#include <iostream> // Necesario para cout

Dibujo::Dibujo(Vector2 posicion, VectorGenerico<VectorGenerico<int>> grid, Color colorGeneral)
    : posicion(posicion), grid(grid), colorGeneral(colorGeneral)
{
    rectangulo.width = 3;
    rectangulo.height = 3;
}

Dibujo::~Dibujo()
{
}

Color& Dibujo::GetColor()
{
    return colorGeneral;
}

Vector2& Dibujo::GetPosicion()
{
    return posicion;
}

void Dibujo::SetRectangulox(int width)
{
    rectangulo.width = float(width);
}

void Dibujo::SetRectanguloy(int height)
{
    rectangulo.height = float(height);
}

void Dibujo::Draw()
{
    Vector2 auxPosicion = posicion;
    for (int filas = 0; filas < grid.getCantidadActual(); ++filas) {
        for (int columnas = 0; columnas < grid[filas].getCantidadActual(); ++columnas) {
            //std::cout << filas << "+" << columnas << "---" << grid[filas][columnas] << std::endl;
            if (grid[filas][columnas] == 1) {
                rectangulo.x = auxPosicion.x + columnas * rectangulo.width;
                rectangulo.y = auxPosicion.y + filas * rectangulo.height;
                DrawRectangleRec(rectangulo, colorGeneral);
            }
        }
    }
}
