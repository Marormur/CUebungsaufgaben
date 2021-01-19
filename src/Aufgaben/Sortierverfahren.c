//
// Created by Marvin Temmen on 23.09.20.
//
#include "../AllgemeineFunktionen.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
    printf("%d, %d, %d, %d, %d \n",
           zahlen[1], zahlen[2], zahlen[3], zahlen[4], zahlen[5]);
    return (0);
}

// Aufgabe 6
int sortieren10Werte() {
    int zahlen[11];
    int x,y,merker;
    int i = 0;

    zahlen[1] = 9;
    zahlen[2] = 10;
    zahlen[3] = 13;
    zahlen[4] = 7;
    zahlen[5] = 1;
    zahlen[6] = 18;
    zahlen[7] = 23;
    zahlen[8] = 16;
    zahlen[9] = 5;
    zahlen[10] = 21;

    for (x = 1;  x <= 9; x++) {
        i++;
        for (y = x + 1; y <= 10; y++) {
            if (zahlen[x] > zahlen[y]) {
                merker = zahlen[x];
                zahlen[x] = zahlen[y];
                zahlen[y] = merker;
            }
            // für übersichtlichere Ausgabe auskommentiert (nicht in Aufgabe)
            // printf("X-Durchlauf: %d, y: %d, zahlen[y]: %d \n", i, y, zahlen[y]);
        }
        // für übersichtlichere Ausgabe auskommentiert (nicht in Aufgabe)
        // printf("X-Durchlauf: %d, x: %d, zahlen[x]: %d\n", i, x, zahlen[x]);
    }
    printf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d \n",
            zahlen[1], zahlen[2], zahlen[3], zahlen[4], zahlen[5], zahlen[6],zahlen[7], zahlen[8], zahlen[9], zahlen[10]);
    return (0);
}

// Aufgabe 8
void wortlisteSortieren() {
    // ToDo
}

void sortierVerfahrenMenue() {
    while (1) {
        clearScreen();
        puts("Aufgaben zu Sortierverfahren:");
        puts("1: Zahlenwerte der for x Schleife");
        puts("2: 10 Werte sortiert");
        puts("2: W\x94rter sortieren");

        puts("0: Zur\x81 \bck zum Hauptmen\x81");
        printf("\nTreffe eine Auswahl: ");
        int input = (int)strtol(getString(2), NULL, 10);
        switch (input) {
            case 0:
                return;
            case 1:
                tabelleForXSchleife();
                break;
            case 2:
                sortieren10Werte();
                break;
            case 3:
                wortlisteSortieren();
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