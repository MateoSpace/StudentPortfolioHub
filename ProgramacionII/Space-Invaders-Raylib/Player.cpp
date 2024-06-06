#include "Player.h"

Player::Player(Vector2 posicion, int tipoAlien, Color colorGeneral)
    : Dibujo(posicion, 13, 9, colorGeneral), estaVivo(true), vidas(4), tipoAlien(tipoAlien), proyectiles(100) {
    MatrizGenerica<int> MatrizPrueba(9, 13);
    const int Patron1[9][13] = {
    {0,0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,0,0,0,0,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1},
    };
    const int(*patron)[13] = nullptr;
    patron = Patron1;
    for (int i = 0; i < 9; ++i) {
        MatrizPrueba[i].registrar(8);
        for (int j = 0; j < 10; ++j) {
            MatrizPrueba[i][j] = patron[i][j];
        }
    }
    this->grid = MatrizPrueba;
}

Player::Player()
    : Dibujo(), estaVivo(true), vidas(3), tipoAlien(0), proyectiles(100) {
}

int& Player::getVidas() {
    return vidas;
}

int Player::getTipo() const {
    return tipoAlien;
}

bool Player::isVivo() const {
    return estaVivo;
}

void Player::setVivo(bool estado) {
    estaVivo = estado;
}

VectorGenerico<Vector2>& Player::getProyectiles()
{
    return proyectiles;
}

bool Player::colision(Vector2 proyectil) {
    Rectangle hitbox = { int(posicion.x),int(posicion.y),int(grid.getColumnas() * 3),int(grid.getFilas() * 3) };
    if (CheckCollisionPointRec(proyectil, hitbox)) {
        this -> vidas--;
        if (vidas <= 0) {
            estaVivo = false;
        }
        return true;
    }
    return false;
}

void Player::Disparo() {
    Vector2 nuevoProyectil = { posicion.x, posicion.y };
    proyectiles.registrar(nuevoProyectil);
}

void Player::moverProyectiles(Vector2 desplazamiento) {
    for (int i = 0; i < proyectiles.getCantidadActual(); ++i) {
        proyectiles[i].x += desplazamiento.x;
        proyectiles[i].y += desplazamiento.y;

        // Si el proyectil sale de la pantalla, eliminarlo
        if (proyectiles[i].y < 0 || proyectiles[i].y > GetScreenHeight() ||
            proyectiles[i].x < 0 || proyectiles[i].x > GetScreenWidth()) {
            proyectiles.eliminar(i);
            i--;  // Ajustar el índice después de eliminar un proyectil
        }
    }
}

void Player::moverPlayer(Vector2 desplazamiento) {
    posicion.x += desplazamiento.x;
    posicion.y += desplazamiento.y;
    rectangulo.x = posicion.x;
    rectangulo.y = posicion.y;
}

void Player::DrawProyectiles() {
    for (int i = 0; i < proyectiles.getCantidadActual(); ++i) {
        DrawRectangle(int(proyectiles[i].x), int(proyectiles[i].y), 5, 15, GREEN);
    }
}