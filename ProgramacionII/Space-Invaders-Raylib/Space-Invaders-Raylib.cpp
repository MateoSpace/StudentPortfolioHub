#include <iostream>
#include <raylib.h>
#include "MenuCilico.h"
#include "MenuNoCiclico.h"
#include "Dibujo.h"
#include "Alien.h"

using namespace std;

int main() {

    Color Dark_Green = Color{ 20, 160, 133, 255 };

    const int screenWidth = 800;
    const int screenHeight = 700;
    int ball_x = 100;
    int ball_y = 100;
    int ball_speed_x = 5;
    int ball_speed_y = 5;
    int ball_radius = 15;

    cout << "Hello World" << endl;
    VectorGenerico<VectorGenerico<int>> MatrizPrueba(8);

    for (int i = 0; i < 8; i++) {
        VectorGenerico<int> listaInterna(5);
        for (int j = 0; j < 5; j++) {
            if (i >= j)
            {
                listaInterna.registrar(1);
            }
            else
            {
                listaInterna.registrar(0);
            }
        }
        MatrizPrueba.registrar(listaInterna);
    }
    
    for (int i = 0; i < MatrizPrueba.getCantidadActual(); i++) {
        for (int j = 0; j < MatrizPrueba[i].getCantidadActual(); j++) {
            cout << MatrizPrueba[i][j] << " ";
        }
        cout << endl;
    }

    Dibujo dibujoPrueba({ 60,40 }, MatrizPrueba, WHITE);

    Alien alien1({ 350,350 }, 2, YELLOW);


    InitWindow(screenWidth, screenHeight, "SPACE INVADERS (RAYLIB)");
    SetTargetFPS(60);

    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground({ 16, 16, 16});

        dibujoPrueba.Draw();
        alien1.Draw();

        ball_x += ball_speed_x;
        ball_y += ball_speed_y;

        if (ball_x + ball_radius >= screenWidth || ball_x - ball_radius <= 0)
        {
            ball_speed_x *= -1;
        }

        if (ball_y + ball_radius >= screenHeight-100 || ball_y - ball_radius <= 0)
        {
            ball_speed_y *= -1;
        }
        
        DrawCircle(ball_x, ball_y, float(ball_radius), WHITE);

        DrawLine(10, 600, screenWidth - 10, 600, { 19, 123, 36, 200 });
        DrawLine(10, 602, screenWidth - 10, 602, { 19, 123, 36, 200 });
        DrawRectangleLines(5, 5, screenWidth - 10, screenHeight - 10, { 19, 123, 36, 200 });
        DrawRectangleLines(7, 7, screenWidth - 14, screenHeight - 14, { 19, 123, 36, 200 });
        DrawText("SCORE : ", 20, 640, 20, LIGHTGRAY);
        DrawText("HIGH SCORE :", 250, 640, 20, LIGHTGRAY);

        //DrawLineEx({ 25, 730 }, { 775, 730 }, 3, YELLOW);
        //DrawText("EL MENU DEL JUEGO", int(screenHeight / 2.5), int(screenWidth / 2.5), 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}