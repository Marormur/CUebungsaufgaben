//
// Created by Marvin Temmen on 06.05.20.
//

#include "../AllgemeineFunktionen.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Aufgabe 1
void begruessung() {
    clearScreen();
    printf("Bitte geben Sie Ihren Nachnamen ein: ");
    char *nachname = getString(256);
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

    free(nachname);
    pressAnyKeyMessage();
}

// Aufgabe 2
void notenLookup() {
    clearScreen();
    printf("Geben Sie eine Note (1-6) ein: ");
    long note = strtol(getString(2), NULL , 10);
    switch (note) {
        case 1:
            printf("\nSehr gut\n\n");
            break;
        case 2:
            printf("\nGut\n\n");
            break;
        case 3:
            printf("\nBefriedigend\n\n");
            break;
        case 4:
            printf("\nAusreichend\n\n");
            break;
        case 5:
            printf("\nMangelhaft\n\n");
            break;
        case 6:
            printf("\nUngenügend\n\n");
            break;
        default:
            printf("\nDie Eingabe stellt keine Note dar!\n\n");
            break;
    }

    pressAnyKeyMessage();
}

// Aufgabe 3
void menue() {
    clearScreen();
    puts("(1) Daten laden");
    puts("(2) Daten ergänzen");
    puts("(3) Daten löschen");
    puts("(4) Daten auswerten");
    puts("(5) Daten speichern");
    puts("(0) ENDE");
    printf("Ihre Eingabe: ");
    long input = strtol(getString(256), NULL, 10);
    switch (input) {
        case 1:
            printf("\nSie haben \"Daten laden\" gewählt.\n");
            break;
        case 2:
            printf("\nSie haben \"Daten ergänzen\" gewählt.\n");
            break;
        case 3:
            printf("\nSie haben \"Daten löschen\" gewählt.\n");
            break;
        case 4:
            printf("\nSie haben \"Daten auswerten\" gewählt.\n");
            break;
        case 5:
            printf("\nSie haben \"Daten speichern\" gewählt.\n");
            break;
        case 0:
            printf("\nSie haben \"ENDE\" gewählt.\n");
            break;
        default:
            printf("\nUngültige Eingabe!\n");
            break;
    }

    pressAnyKeyMessage();
}

void alternativenMenue() {
    while (1) {
        clearScreen();
        puts("Aufgaben zu Alternativen:");
        puts("1: Begrüßung");
        puts("2: Schulnoten");
        puts("3: Menü");
        puts("0: Zurück zum Hauptmenü");
        printf("\nTreffe eine Auswahl: ");
        long input = strtol(getString(2), NULL, 10);
        switch (input) {
            case 0:
                return;
            case 1:
                begruessung();
                break;
            case 2:
                notenLookup();
                break;
            case 3:
                menue();
                break;
            default:
                // Nur zur Unterdrückung einer Warnung
                break;
        }
    }
}