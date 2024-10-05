#include "raylib.h"
#include "gioco.h"
#include "colori.h"
#include <iostream>

double ultimoTempoUpdate = 0;

bool eventoChiamato(double millisecondi) {
    double tempoCorrente = GetTime();
    if (tempoCorrente - ultimoTempoUpdate >= millisecondi) {
        ultimoTempoUpdate = tempoCorrente;  
        return true;
    }
    return false;
}

int main() {
    Color Blu_scuro = {44, 44, 127, 255};
    Gioco gioco = Gioco();

    const float scaleFactor = 0.7f; // Scaling factor
    const int WIDTH = static_cast<int>(807 * scaleFactor); // Resized width
    const int HEIGHT = static_cast<int>(1040 * scaleFactor); // Reiszed height

    Font font = LoadFontEx("monogram.ttf", static_cast<int>(64 * scaleFactor), 0, 0); // Resized font
    SetTargetFPS(60);
    InitWindow(WIDTH, HEIGHT, "Tetris");

    while (!WindowShouldClose()) {
        UpdateMusicStream(gioco.musica);
        gioco.gestisciInput();

        if (eventoChiamato(0.3)) {
            gioco.muoviBloccoSotto();
        }
        
        BeginDrawing();
        ClearBackground(Blu_scuro);

        // Testo ridimensionato
        DrawTextEx(font, "Score", { static_cast<float>(565 * scaleFactor), static_cast<float>(20 * scaleFactor) }, static_cast<float>(64 * scaleFactor), 8 * scaleFactor, WHITE);
        DrawTextEx(font, "Next", { static_cast<float>(565 * scaleFactor), static_cast<float>(350 * scaleFactor) }, static_cast<float>(64 * scaleFactor), 18 * scaleFactor, WHITE);

        if (gioco.gameOver) {
            DrawTextEx(font, "GAME OVER", { static_cast<float>(565 * scaleFactor), static_cast<float>(850 * scaleFactor) }, static_cast<float>(35 * scaleFactor), 2 * scaleFactor, WHITE);
        }

        char testoPunteggio[10];
        sprintf(testoPunteggio, "%d", gioco.punteggio);

        DrawRectangleRounded({ 545 * scaleFactor, 80 * scaleFactor, 240 * scaleFactor, 80 * scaleFactor }, 0.3, 6, bluChiaro);
        DrawTextEx(font, testoPunteggio, { static_cast<float>(565 * scaleFactor), static_cast<float>(90 * scaleFactor)}, static_cast<float>(64 * scaleFactor), 8 * scaleFactor, WHITE);
        DrawRectangleRounded({ 545 * scaleFactor, 410 * scaleFactor, 240 * scaleFactor, 240 * scaleFactor }, 0.3, 6, bluChiaro);     
        
        gioco.Disegna();
        EndDrawing();
    }

    CloseWindow();
}
