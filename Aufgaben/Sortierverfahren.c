//
// Created by Marvin Temmen on 23.09.20.
//
#include "../AllgemeineFunktionen.h"
#include <stdlib.h>
#include <stdio.h>

void sortierVerfahrenMenue() {
    while (1) {
        clearScreen();
        puts("Aufgaben zu Sortierverfahren:");
        puts("1: 1 bis 10");

        puts("0: Zurück zum Hauptmenü");
        printf("\nTreffe eine Auswahl: ");
        int input = (int)strtol(getString(2), NULL, 10);
        switch (input) {
            case 0:
                return;
            case 1:
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