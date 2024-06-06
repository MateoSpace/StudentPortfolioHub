#pragma once

#include "Dibujo.h"
#include "Alien.h"
#include "MatrizGenerica.h"

class MatrizEnemigos {
public:
    MatrizEnemigos(int filas, int columnas);
    ~MatrizEnemigos() = default;

    void registrarAlien(int fila, int columna, const Alien& alien);
    Alien& obtenerAlien(int fila, int columna);

    Vector2 getPosicionDerecha() ;
    Vector2 getPosicionIzquierda() ;
    Vector2 getPosicionAbajo() ;
    Vector2 getPosicionArriba() ;
    Vector2 getPosicionGeneral() ;
    Vector2 getFilasColumnas();

    VectorGenerico<Vector2>&  getProyectiles(); ///// entrega los proyectiles 

    void setPosicionGeneral(Vector2 nuevaPosicion);
    void Draw();

    bool colicion(Vector2 balas); //// en cual se verifica si alguna bala colisiona con hitbox de algún alien, cambiando el "estavivo" (atributo del alien) a false, y devuelve true

    void DisparoRandom(); ////// se agra un proyectil al vector de proyectiles con origen random de un alien 

    void moverProyectiles(Vector2 desplacmiento); /// mueve el proyectil, según el desplazamiento dado

    void DrawProyectiles(); //dibuja los proyectiles con     DrawRectangle(proyectiles[i].x,proyectiles[i].y, 5,15, GREEN);

    void moverMatriz(Vector2 desplazamiento);

private:
    MatrizGenerica<Alien> matriz;
    VectorGenerico<Vector2> proyectiles;
    Vector2 posicionGeneral;
};
