#pragma once
#include "Dibujo.h"

class Player : public Dibujo {
private:
    bool estaVivo;
    int vidas;
    int tipoAlien;
    VectorGenerico<Vector2> proyectiles;  // Almacena los proyectiles

public:
    Player(Vector2 posicion, int tipoAlien, Color colorGeneral);
    Player();
    ~Player() = default;

    int& getVidas();
    int getTipo() const;
    bool isVivo() const;
    void setVivo(bool estado);
    VectorGenerico<Vector2>& getProyectiles();

    bool colision(Vector2 proyectil); // Verifica si alguna bala colisiona con el hitbox
    void Disparo(); // Agrega un proyectil al vector de proyectiles con origen en la posición actual
    void moverProyectiles(Vector2 desplazamiento); // Mueve los proyectiles según el desplazamiento dado
    void moverPlayer(Vector2 desplazamiento); // Mueve al jugador según el desplazamiento dado
    void DrawProyectiles(); // Dibuja los proyectiles
};