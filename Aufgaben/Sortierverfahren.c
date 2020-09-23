//
// Created by Marvin Temmen on 23.09.20.
//
#include "../AllgemeineFunktionen.h"
#include <stdlib.h>
#include <stdio.h>

// Aufgabe 2
int tabelleForXSchleife() {
    int zahlen[6];
    int x,y,merker;
    int i = 0;

    zahlen[1] = 9;
    zahlen[2] = 10;
    zahlen[3] = 13;
    zahlen[4] = 7;
    zahlen[5] = 3;

    for (x = 1;  x <= 4; x++) {
        i++;
        for (y = x + 1; y <= 5; y++) {
            if (zahlen[x] > zahlen[y]) {
                merker = zahlen[x];
                zahlen[x] = zahlen[y];
                zahlen[y] = merker;
            }
            printf("X-Durchlauf: %d, y: %d, zahlen[y]: %d \n", i, y, zahlen[y]);
        }
        printf("X-Durchlauf: %d, x: %d, zahlen[x]: %d\n", i, x, zahlen[x]);
    }
    return (0);
}

void sortierVerfahrenMenue() {
    while (1) {
        clearScreen();
        puts("Aufgaben zu Sortierverfahren:");
        puts("1: Zahlenwerte der for x Schleife");

        puts("0: Zurück zum Hauptmenü");
        printf("\nTreffe eine Auswahl: ");
        int input = (int)strtol(getString(2), NULL, 10);
        switch (input) {
            case 0:
                return;
            case 1:
                tabelleForXSchleife();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            default:
                // Nur zur Unterdrückung einer Warnung
                break;
        }
    }

}