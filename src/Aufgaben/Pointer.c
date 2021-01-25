#include <stdio.h>
#include <stdlib.h>
#include "../AllgemeineFunktionen.h"
#include "Schleifen.h"

int anzahlPointer() {
    printf("Es werden 4 Pointer erzeugt. Sie können auf die Wagen / Lokomotive zeigen."); // ToDo: Prüfen ob die Angaben richtig sind
    return (0);
}

void pointerMenue() {
    while (1) {
        clearScreen();
        puts("Aufgaben zu Pointer:");
        puts("0: Zur�ck zum Hauptmen�");
        puts("1: Wie viele Pointer und worauf zeigen diese?");
        printf("\nTreffe eine Auswahl: ");
        int input = (int)strtol(getString(2), NULL, 10);
        switch (input) {
        case 0:
            return;
        case 1:
            anzahlPointer();
            break;
        default:
            // Nur zur Unterdr�ckung einer Warnung
            break;
        }
    }
}
