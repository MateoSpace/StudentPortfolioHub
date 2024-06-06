#include <iostream>
#include <raylib.h>
#include "MatrizEnemigos.h"
#include "Dibujo.h"
#include "Alien.h"
#include "Player.h"
#include <thread>
#include <atomic>
#include <chrono>

using namespace std;

void DibujarMargenes(int screenWidth, int screenHeight, int score, int highScore, int lives) {
    Color Dark_Green = Color{ 20, 160, 133, 255 };
    DrawLine(10, 600, screenWidth - 10, 600, { 19, 123, 36, 200 });
    DrawLine(10, 602, screenWidth - 10, 602, { 19, 123, 36, 200 });
    DrawRectangleLines(5, 5, screenWidth - 10, screenHeight - 10, { 19, 123, 36, 200 });
    DrawRectangleLines(7, 7, screenWidth - 14, screenHeight - 14, { 19, 123, 36, 200 });

    // Mostrar puntaje y vida
    DrawText(TextFormat("SCORE: %d", score), 20, 640, 20, LIGHTGRAY);
    DrawText(TextFormat("HIGH SCORE: %d", highScore), 250, 640, 20, LIGHTGRAY);
    DrawText(TextFormat("LIVES: %d", lives), 650, 640, 20, LIGHTGRAY);
}

MatrizEnemigos inicializarEnemigos() {
    Vector2 posicionInicial = { 20, 60 };
    Vector2 Dimenciones = { 8, 5 };
    MatrizEnemigos matrizEnemigos(Dimenciones.x, Dimenciones.y);
    matrizEnemigos.setPosicionGeneral(posicionInicial);
    Alien alien;
    // Configurar algunos Aliens en la matriz (ejemplo)
    for (int i = 0; i < Dimenciones.x; ++i) {
        for (int j = 0; j < Dimenciones.y; ++j) {
            Vector2 posicionAlien = { posicionInicial.x + j * 65, posicionInicial.y + i * 45 };
            if (j == 0) {
                alien = Alien(posicionAlien, 3, GREEN);
            }
            else {
                if (j < 3) {
                    alien = Alien(posicionAlien, 2, GREEN);
                }
                else {
                    alien = Alien(posicionAlien, 1, GREEN);
                }
            }
            matrizEnemigos.registrarAlien(i, j, alien);
        }
    }
    return matrizEnemigos;
}

void procesarColisiones(MatrizEnemigos& enemigos, Player& player, std::atomic<bool>& finished, int& score, int& lives) {
    while (!finished) {
        // Procesar colisiones de proyectiles del jugador con enemigos
        for (int i = 0; i < player.getProyectiles().getCantidadActual(); ++i) {
            Vector2 proyectilJugador = player.getProyectiles()[i];

            // Verificar colisión del proyectil del jugador con los enemigos
            for (int fila = 0; fila < enemigos.getFilasColumnas().x; ++fila) {
                for (int col = 0; col < enemigos.getFilasColumnas().y; ++col) {
                    if (enemigos.colicion(proyectilJugador)) {
                        player.getProyectiles().eliminar(i);
                        i--;  // Ajustar el índice después de eliminar un proyectil
                        //player.getProyectiles().eliminar(i);
                        score += 100;
                        break;
                    }
                }
            }

            // Verificar si el proyectil del jugador sale de los márgenes
            if (proyectilJugador.y < 5 || proyectilJugador.y > GetScreenHeight() ||
                proyectilJugador.x < 5 || proyectilJugador.x > GetScreenWidth()) {
                player.getProyectiles().eliminar(i);
                i--;  // Ajustar el índice después de eliminar un proyectil
            }
        }

        // Procesar colisiones de proyectiles de los enemigos con el jugador
        for (int i = 0; i < enemigos.getProyectiles().getCantidadActual(); ++i) {
            Vector2 proyectilEnemigo = enemigos.getProyectiles()[i];

            // Verificar colisión del proyectil del enemigo con el jugador
            if (player.colision(proyectilEnemigo)) {
                enemigos.getProyectiles().eliminar(i);
                lives--;
                i--;  // Ajustar el índice después de eliminar un proyectil
            }

            // Verificar si el proyectil del enemigo sale de los márgenes
            if (proyectilEnemigo.y < 0 || proyectilEnemigo.y > GetScreenHeight() - 100 ||
                proyectilEnemigo.x < 0 || proyectilEnemigo.x > GetScreenWidth()) {
                enemigos.getProyectiles().eliminar(i);
                i--;  // Ajustar el índice después de eliminar un proyectil
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Pausa corta para evitar consumo excesivo de CPU
    }
}

void procesadoEnenemigos(MatrizEnemigos& Enemigos, float speed_x, int screenWidth, int screenHeight, atomic<bool>& finished) {
    auto lastShotTime = chrono::steady_clock::now();
    while (!finished) {
        //cout << "speed_x " << speed_x << "screenWidth " << screenWidth << " Isqui " << Enemigos.getPosicionIzquierda().x << endl;
        if (Enemigos.getPosicionDerecha().x > screenWidth - 40 || Enemigos.getPosicionIzquierda().x < 12) {
            speed_x *= -1;
            Enemigos.setPosicionGeneral({ Enemigos.getPosicionGeneral().x + speed_x * 2 ,Enemigos.getPosicionGeneral().y + 25 });
        }
        if (Enemigos.getPosicionAbajo().y > 535) {
            speed_x = 0;
        }
        Enemigos.moverMatriz({ speed_x ,0 });

        // Ejecutar DisparoRandom cada 2 segundos
        auto currentTime = chrono::steady_clock::now();
        auto elapsed = chrono::duration_cast<chrono::seconds>(currentTime - lastShotTime).count();
        if (elapsed >= 2) {
            Enemigos.DisparoRandom();
            lastShotTime = currentTime;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(600));
    }
}

void manejarPlayer(Player& player, atomic<bool>& finished) {
    while (!finished) {
        if (IsKeyDown(KEY_LEFT)) {
            player.moverPlayer({ -5, 0 });
        }
        if (IsKeyDown(KEY_RIGHT)) {
            player.moverPlayer({ 5, 0 });
        }
        if (IsKeyDown(KEY_SPACE)) {
            player.Disparo();
            std::this_thread::sleep_for(std::chrono::milliseconds(300));  // Pausa corta para evitar múltiples disparos rápidos
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(16));  // Control de velocidad del bucle
    }
}

int main() {
    const int screenWidth = 800;
    const int screenHeight = 700;
    InitWindow(screenWidth, screenHeight, "SPACE INVADERS (RAYLIB)");
    SetTargetFPS(60);

    // Inicializar el jugador
    Player player({ screenWidth / 2.0f, 530 }, 1, GREEN);

    MatrizEnemigos Enemigos = inicializarEnemigos();
    float speed_x = 20;
    atomic<bool> finished(false);
    std::thread t1(procesadoEnenemigos, std::ref(Enemigos), speed_x, screenWidth, screenHeight, std::ref(finished));

    int score = 0;         // Puntaje actual del jugador
    int highScore = 1200;  // Puntaje máximo (puedes cargarlo de un archivo o una variable global)
    int lives = player.getVidas(); // Vidas del jugador

    // Hilo para procesar colisiones
    std::thread t2(procesarColisiones, std::ref(Enemigos), std::ref(player), std::ref(finished), std::ref(score), std::ref(lives));

    // Hilo para manejar al jugador
    std::thread t3(manejarPlayer, std::ref(player), std::ref(finished));

    bool gameOver = false;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground({ 16, 16, 16 });

        if (lives <= 0) {
            gameOver = true;
            finished = true;
            DrawText("GAME OVER", screenWidth / 2 - 100, screenHeight / 2 - 50, 40, RED);
        }
        else {
            // Dibujar los márgenes y la información del jugador
            DibujarMargenes(screenWidth, screenHeight, score, highScore, lives);

            Enemigos.moverProyectiles({ 0, 4 });
            Enemigos.DrawProyectiles();
            Enemigos.Draw();

            if (score >= highScore) {
                highScore = score;
            }

            // Mover y dibujar proyectiles del jugador
            player.moverProyectiles({ 0, -5 });
            player.DrawProyectiles();

            // Dibujar al jugador
            player.Draw();
        }

        EndDrawing();
    }

    if (gameOver) {
        t1.join();
        t2.join();
        t3.join();
    }
    else {
        finished = true;
        t1.join();
        t2.join();
        t3.join();
    }

    CloseWindow();
    return 0;
}
