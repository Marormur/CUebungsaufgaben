//
// Created by Marvin Temmen on 11.05.20.
//

#include <stdio.h>
#include <stdlib.h>
#include "../AllgemeineFunktionen.h"
#include "Schleifen.h"


void nullBisNeun() {
    clearScreen();
    puts("Zahlen 0-9:");
    puts("Vorwärts mit for-Schleife:");
    for (int i = 0; i < 10; i++){
        printf("%d", i);
        if (i != 9) {
            printf(", ");
        } else {
            puts("");
        }
    }
    puts("\nRückwärts mit for-Schleife:");
    for (int i = 9; i >= 0; i--) {
        printf("%d", i);
        if (i != 0) {
            printf(", ");
        } else {
            puts("");
        }
    }
    puts("\nVorwärts mit while-Schleife:");
    int zaehler = 0;
    while (zaehler < 10){
        printf("%d", zaehler);
        if (zaehler != 9) {
            printf(", ");
        } else {
            puts("");
        }

        zaehler++;
    }

    puts("\nRückwärts mit while-Schleife:");
    zaehler = 10;
    while (zaehler--) {
        printf("%d", zaehler);
        if (zaehler != 0) {
            printf(", ");
        } else {
            puts("\n");
        }
    }

    pressAnyKeyMessage();
}

// Aufgabe 1
void aBisZ() {
    clearScreen();
    puts("Buchstaben a-z:");
    puts("Vorwärts mit for-Schleife:");
    for (int i = 97; i < 123; i++){
        printf("%c", i);
        if (i != 122) {
            printf(", ");
        } else {
            puts("");
        }
    }
    puts("\nRückwärts mit for-Schleife:");
    for (int i = 122; i >= 97; i--) {
        printf("%c", i);
        if (i != 97) {
            printf(", ");
        } else {
            puts("");
        }
    }
    puts("\nVorwärts mit while-Schleife:");
    int zaehler = 97;
    while (zaehler < 123){
        printf("%c", zaehler);
        if (zaehler != 122) {
            printf(", ");
        } else {
            puts("");
        }

        zaehler++;
    }

    puts("\nRückwärts mit while-Schleife:");
    zaehler = 122;
    while (zaehler > 96) {
        printf("%c", zaehler);
        if (zaehler != 97) {
            printf(", ");
        } else {
            puts("\n");
        }

        zaehler--;
    }

    pressAnyKeyMessage();
}

// Aufgabe 2
void schleifenMenue() {
    while (1) {
        clearScreen();
        puts("Aufgaben zu Schleifen:");
        puts("1: 0 bis 9");
        puts("2: a bis z");
        puts("0: Zurück zum Hauptmenü");
        printf("\nTreffe eine Auswahl: ");
        int input = (int)strtol(getString(2), NULL, 10);
        switch (input) {
            case 0:
                return;
            case 1:
                nullBisNeun();
                break;
            case 2:
                aBisZ();
                break;
            default:
                // Nur zur Unterdrückung einer Warnung
                break;
        }
    }

}

