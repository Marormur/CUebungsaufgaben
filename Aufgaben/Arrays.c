//
// Created by Marvin Temmen on 09.06.20.
//

#include "Arrays.h"
#include "../AllgemeineFunktionen.h"
#include <stdlib.h>
#include <stdio.h>

void arraysMenue() {
    while (1) {
        clearScreen();
        puts("Aufgaben zu Alternativen:");
        puts("1: 1 bis 10");
        puts("2: 1 bis 10 Multiplikation");
        puts("3: 2er-Potenz");
        puts("4: Durchschnittsverbrauch");
        puts("5: Buchstabenanzahl");
        puts("6: Buchstabenanzahl mit Satzeingabe");
        puts("7: Buchstabenanzahl Alphabet");
        puts("8: Durchschnittsverbrauch erweitert");
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