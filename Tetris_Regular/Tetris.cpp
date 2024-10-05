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
    double prop = 0.7;

    const int WIDTH = 807 * prop;
    const int HEIGHT = 840 * prop;

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
        DrawTextEx(font, "Score", { 394, 14 }, 44, 5.6, WHITE); // font, stringa, posizione, grandezza, spacing, colore
        DrawTextEx(font, "Next", { 394, 245 }, 44, 12.6, WHITE);

        if (gioco.gameOver) {
            DrawTextEx(font, "GAME OVER", { 394, 595 }, 24, 2, WHITE);
        }

        char testoPunteggio[10];
        snprintf(testoPunteggio, sizeof(testoPunteggio), "%d", gioco.punteggio);
        // Vector2 grandezzaTesto = MeasureTextEx(font, testoPunteggio, 38, 2);    // calcola la grandezza del testo in un vettore contenente larghezza e altezza

        DrawRectangleRounded({ 381, 56, 168, 56 }, 0.3, 4, bluChiaro);      // posizione e grandezza, float dell'angolo smussato, segmenti, colore
        DrawTextEx(font, testoPunteggio, { 395, 63 }, 44, 5.6, WHITE);        // effettivo punteggio
        DrawRectangleRounded({ 381, 287, 168, 168 }, 0.3, 4, bluChiaro);     
        
        gioco.Disegna();
        EndDrawing();
    }

    CloseWindow();
}