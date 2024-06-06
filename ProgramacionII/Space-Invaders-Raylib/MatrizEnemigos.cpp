#include "MatrizEnemigos.h"
#include <stdexcept>

MatrizEnemigos::MatrizEnemigos(int filas, int columnas)
    : matriz(filas, columnas), posicionGeneral({ 0, 0 }),proyectiles(150) {
}

void MatrizEnemigos::registrarAlien(int fila, int columna, const Alien& alien) {
    if (fila < 0 || fila >= matriz.getFilas() || columna < 0 || columna >= matriz.getColumnas()) {
        throw std::out_of_range("Índice de fila o columna fuera de rango");
    }
    matriz[fila][columna] = alien;
}

Alien& MatrizEnemigos::obtenerAlien(int fila, int columna) {
    if (fila < 0 || fila >= matriz.getFilas() || columna < 0 || columna >= matriz.getColumnas()) {
        throw std::out_of_range("Índice de fila o columna fuera de rango");
    }
    return matriz[fila][columna];
}

Vector2 MatrizEnemigos::getPosicionDerecha()  {
    Vector2 posicionDerecha = { -1, -1 };
    for (int i = 0; i < matriz.getFilas(); ++i) {
        for (int j = 0; j < matriz.getColumnas(); ++j) {
            if (matriz[i][j].isVivo()) {
                if (posicionDerecha.x == -1 || matriz[i][j].GetPosicion().x > posicionDerecha.x) {
                    posicionDerecha = matriz[i][j].GetPosicion();
                }
            }
        }
    }
    //std::cout << " --x- " << posicionDerecha.x << " --y- " << posicionDerecha.y << std::endl;
    return posicionDerecha;
}

Vector2 MatrizEnemigos::getPosicionIzquierda()  {
    Vector2 posicionIzquierda = { -1, -1 };
    for (int i = 0; i < matriz.getFilas(); ++i) {
        for (int j = 0; j < matriz.getColumnas(); ++j) {
            if (matriz[i][j].isVivo()) {
                if (posicionIzquierda.x == -1 || matriz[i][j].GetPosicion().x < posicionIzquierda.x) {
                    posicionIzquierda = matriz[i][j].GetPosicion();
                }
            }
        }
    }
    return posicionIzquierda;
}

Vector2 MatrizEnemigos::getPosicionAbajo()  {
    Vector2 posicionAbajo = { -1, -1 };
    for (int i = 0; i < matriz.getFilas(); ++i) {
        for (int j = 0; j < matriz.getColumnas(); ++j) {
            if (matriz[i][j].isVivo()) {
                if (posicionAbajo.y == -1 || matriz[i][j].GetPosicion().y > posicionAbajo.y) {
                    posicionAbajo = matriz[i][j].GetPosicion();
                }
            }
        }
    }
    return posicionAbajo;
}

Vector2 MatrizEnemigos::getPosicionArriba()  {
    Vector2 posicionArriba = { -1, -1 };
    for (int i = 0; i < matriz.getFilas(); ++i) {
        for (int j = 0; j < matriz.getColumnas(); ++j) {
            if (matriz[i][j].isVivo()) {
                if (posicionArriba.y == -1 || matriz[i][j].GetPosicion().y < posicionArriba.y) {
                    posicionArriba = matriz[i][j].GetPosicion();
                }
            }
        }
    }
    return posicionArriba;
}

Vector2 MatrizEnemigos::getPosicionGeneral() 
{
    return posicionGeneral;
}

Vector2 MatrizEnemigos::getFilasColumnas()
{
    return { float(matriz.getFilas()),float(matriz.getColumnas()) };
}

VectorGenerico<Vector2>& MatrizEnemigos::getProyectiles()
{
    return proyectiles;
}

void MatrizEnemigos::setPosicionGeneral(Vector2 nuevaPosicion) {
    //std::cout << "X : " << nuevaPosicion.x << " Y : " <<  nuevaPosicion.y << std::endl;

    this-> posicionGeneral = nuevaPosicion;
}

void MatrizEnemigos::Draw()
{
    for (int i = 0; i < matriz.getFilas(); ++i) {
        for (int j = 0; j < matriz.getColumnas(); ++j) {
            if (matriz[i][j].isVivo())
            {
                matriz[i][j].Draw();
            }
        }
    }
}

bool MatrizEnemigos::colicion(Vector2 bala)
{
    for (int i = 0; i < matriz.getFilas(); ++i) {
        for (int j = 0; j < matriz.getColumnas(); ++j) {
            Alien& alien = matriz[i][j];
            if (alien.isVivo()) {
                Rectangle hitbox = { alien.GetPosicion().x, alien.GetPosicion().y, 8*3, 10*3 };
                if (CheckCollisionPointRec(bala, hitbox)) {
                    alien.setVivo(false); 
                    return true;
                }
            }
        }
    }
    return false;
}

void MatrizEnemigos::DisparoRandom()
{
    int filas = matriz.getFilas();
    int columnas = matriz.getColumnas();

    while (true) {
        int fila = rand() % filas;
        int columna = rand() % columnas;

        if (matriz[fila][columna].isVivo()) {
            Vector2 origen = matriz[fila][columna].GetPosicion();
            proyectiles.registrar({ origen.x+5, origen.y + 10 }); // El proyectil sale desde abajo del alien
            break;
        }
    }
}

void MatrizEnemigos::moverProyectiles(Vector2 desplacmiento)
{
    for (int i = 0; i < proyectiles.getCantidadActual(); ++i) {
        proyectiles[i].x += desplacmiento.x;
        proyectiles[i].y += desplacmiento.y;
    }
}

void MatrizEnemigos::DrawProyectiles()
{
    for (int i = 0; i < proyectiles.getCantidadActual(); ++i) {
        DrawRectangle(proyectiles[i].x, proyectiles[i].y, 5, 15, GREEN);
    }
}

void MatrizEnemigos::moverMatriz(Vector2 desplazamiento) {
    //std::cout << "X : " << posicionGeneral.x + desplazamiento.x << " Y : " << posicionGeneral.y + desplazamiento.y << std::endl;
    for (int i = 0; i < matriz.getFilas(); ++i) {
        for (int j = 0; j < matriz.getColumnas(); ++j) {
            Vector2 nuevaPosicion = { (posicionGeneral.x + ((matriz[i][j].GetGrid().getFilas() + 35) * i)) ,
                                 (posicionGeneral.y + ((matriz[i][j].GetGrid().getColumnas() + 25) * j)) };
            matriz[i][j].GetPosicion() = nuevaPosicion;
        }
    }
    
    setPosicionGeneral({ posicionGeneral.x + desplazamiento.x ,posicionGeneral.y + desplazamiento.y });
}
