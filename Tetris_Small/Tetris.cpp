#include <raylib.h>
#include "gioco.h"
#include "colori.h"
#include <iostream>

double ultimoTempoUpdate = 0;

bool eventoChiamato(double millisecondi) {
   
    double tempoCorrente = GetTime();
    if (tempoCorrente - ultimoTempoUpdate >= millisecondi) {
        
        ultimoTempoUpdate = tempoCorrente;  // funzione per verificare se sono passati 200 millisecondi
        return true;
    }
    return false;
}

int main() {

    Color Blu_scuro = {44, 44, 127, 255};
    Gioco gioco = Gioco();

    const int WIDTH = 807;
    const int HEIGHT = 1040;

    Font font = LoadFontEx("monogram.ttf", 64, 0, 0);
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
        DrawTextEx(font, "Score", { 565, 20 }, 64, 8, WHITE); // font, stringa, posizione, grandezza, spacing, colore
        DrawTextEx(font, "Next", { 565, 350 }, 64, 18, WHITE);

        if (gioco.gameOver) {
            DrawTextEx(font, "GAME OVER", { 565, 850 }, 35, 2, WHITE);
        }

        char testoPunteggio[10];
        snprintf(testoPunteggio, sizeof(testoPunteggio), "%d", gioco.punteggio);
        // Vector2 grandezzaTesto = MeasureTextEx(font, testoPunteggio, 38, 2);    // calcola la grandezza del testo in un vettore contenente larghezza e altezza

        DrawRectangleRounded({ 545, 80, 240, 80 }, 0.3, 6, bluChiaro);      // posizione e grandezza, float dell'angolo smussato, segmenti, colore
        DrawTextEx(font, testoPunteggio, { 565, 90}, 64, 8, WHITE);        // effettivo punteggio
        DrawRectangleRounded({ 545, 410, 240, 240 }, 0.3, 6, bluChiaro);     
        
        gioco.Disegna();
        EndDrawing();
    }

    CloseWindow();
}