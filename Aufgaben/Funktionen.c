//
// Created by marvi on 14.01.2021.
//

#include "Funktionen.h"

void funktionenMenue() {
    while (1) {
        clearScreen();
        puts("Aufgaben zu Funktionen:");
        puts("1: ");
        puts("2: ");
        puts("3: ");
        puts("4: ");

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
            default:
                // Nur zur Unterdrückung einer Warnung
                break;
        }
    }