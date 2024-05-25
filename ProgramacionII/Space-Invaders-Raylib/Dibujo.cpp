#include "Dibujo.h"

Dibujo::Dibujo(Vector2 position,  grid, Color colorGeneral)
{

    rectangulo.width = 3;
    rectangulo.height = 3;

    this-> grid = grid;
    this->colorGeneral = colorGeneral;
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

void Dibujo::Draw()
{
    this->position = position;

    for (unsigned int row = 0; row < grid.size(); ++row) {
        for (unsigned int column = 0; column < grid[0].size(); ++column) {
            if (grid[row][column] == 1) {
                rectangulo.x = position.x + column * 3;
                rectangulo.y = position.y + row * 3;
                Block block = Block({ pos_x, pos_y });
                blocks.push_back(block);
                DrawRectangleRec(rectangulo, colorGeneral);

            }
        }
    }
}
