#include <stdio.h>
#include <stdlib.h>
#include "../AllgemeineFunktionen.h"
#include "Schleifen.h"

void pointerMenue() {
    while (1) {
        clearScreen();
        puts("Aufgaben zu Pointer:");
        puts("0: Zur�ck zum Hauptmen�");
        printf("\nTreffe eine Auswahl: ");
        int input = (int)strtol(getString(2), NULL, 10);
        switch (input) {
        case 0:
            return;
        default:
            // Nur zur Unterdr�ckung einer Warnung
            break;
        }
    }
}
