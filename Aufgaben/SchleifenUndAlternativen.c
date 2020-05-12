//
// Created by Marvin Temmen on 12.05.20.
//

#include <stdio.h>
#include <stdlib.h>
#include "SchleifenUndAlternativen.h"
#include "../AllgemeineFunktionen.h"

// Aufgabe 1
void zahlenkette() {
    clearScreen();
    printf("Bitte eine Zahl eingeben: ");
    long zahl = strtol(getString(256), NULL, 10);
    printf("\nAusgabe: ");
    for (long i = 1; i <= zahl; ++i) {
        printf("%ld, ", i);
    }

    for (long j = zahl-1; j > 0; j--) {
        printf("%ld",j);
        if(j != 1) {
            printf(", ");
        }
    }

    puts("\n");
    pressAnyKeyMessage();
}

void schleifenUndAlternativenMenue() {
    while (1) {
        clearScreen();
        puts("Aufgaben zu Schleifen und Alternativen:");
        puts("1: Zahlenkette");
        puts("2: ");
        puts("3: ");
        puts("4: ");
        puts("5: ");
        puts("6: ");
        puts("0: Zurück zum Hauptmenü");
        printf("\nTreffe eine Auswahl: ");
        int input = (int)strtol(getString(2), NULL, 10);
        switch (input) {
            case 0:
                return;
            case 1:
                zahlenkette();
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
            default:
                // Nur zur Unterdrückung einer Warnung
                break;
        }
    }
}