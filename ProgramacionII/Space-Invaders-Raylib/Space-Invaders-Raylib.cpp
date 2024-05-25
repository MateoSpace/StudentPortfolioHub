#include <iostream>
#include <raylib.h>

using namespace std;

int main() {

    Color Dark_Green = Color{ 20, 160, 133, 255 };

    const int screenWidth = 800;
    const int screenHeight = 700;
    int ball_x = 100;
    int ball_y = 100;
    int ball_speed_x = 1;
    int ball_speed_y = 1;
    int ball_radius = 15;

    cout << "Hello World" << endl;

    InitWindow(screenWidth, screenHeight, "SPACE INVADERS (RAYLIB)");
    SetTargetFPS(60);

    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(Dark_Green);
        ball_x += ball_speed_x;
        ball_y += ball_speed_y;

        if (ball_x + ball_radius >= screenWidth || ball_x - ball_radius <= 0)
        {
            ball_speed_x *= -1;
        }

        if (ball_y + ball_radius >= screenHeight || ball_y - ball_radius <= 0)
        {
            ball_speed_y *= -1;
        }

        DrawCircle(ball_x, ball_y, ball_radius, WHITE);
        DrawText("EL MENU DEL JUEGO", int(screenHeight / 2.5), int(screenWidth / 2.5), 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}