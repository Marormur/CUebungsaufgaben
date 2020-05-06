//
// Created by Marvin Temmen on 06.05.20.
//

#include "../AllgemeineFunktionen.h"
#include <stdlib.h>
#include <stdio.h>

void begruessung() {
    clearScreen();
    printf("Bitte geben Sie Ihren Nachnamen ein: ");
    char* nachname = getString(256);
    printf("Bitte geben Sie Ihr Geschlecht (m/w) ein: ");

    // Hier muss ich 2 Zeichen abfragen, da sonst "\n" genommen wird
    char geschlecht = getString(2)[0]; // Index 0, weil ich kein Interesse an "\n" habe
    if (geschlecht > 96) { // Wenn ein kleiner Buchstabe eingegeben wurde
        geschlecht -= 32; // Dann soll daraus ein großer gemacht werden
    }

    // TODO nachname ist immer NULL
    switch (geschlecht) {
        case 'M':
            printf("\nGuten Tag, Herr %s\n", nachname);
            break;
        case 'W':
            printf("\nGuten Tag, Frau %s\n", nachname);
            break;
        default:
            puts("Ungültiges Geschlecht!");
            return;
    }
}

void alternativenMenue() {
    while (1) {
        clearScreen();
        puts("Aufgaben zu Alternativen:");
        puts("1: Begrüßung");
        puts("0: Zurück zum Hauptmenü");
        printf("\nTreffe eine Auswahl: ");
        long input = strtol(getString(2), NULL, 10);
        switch (input) {
            case 0:
                return;
            case 1:
                begruessung();
                break;
            default:
                // Nur zur Unterdrückung einer Warnung
                break;
        }
    }
}