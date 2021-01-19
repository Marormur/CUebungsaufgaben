//
// Created by Marvin Temmen on 24.09.20.
//

#include "Structs.h"
#include "../AllgemeineFunktionen.h"
#include <stdio.h>
#include <stdlib.h>

void structsMenue() {
    while (1) {
        clearScreen();
        puts("Aufgaben zu Structs:");
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
}