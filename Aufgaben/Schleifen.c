//
// Created by Marvin Temmen on 11.05.20.
//

#include <stdio.h>
#include <stdlib.h>
#include "../AllgemeineFunktionen.h"
#include "Schleifen.h"

// Aufgabe 1
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

// Aufgabe 2
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

// Aufgabe 3
void addition() {
    clearScreen();
    int nochEineAddition = 0;
    do {
        printf("Geben Sie die erste Zahl ein: ");
        double zahl1 = strtod(getString(256), NULL);
        printf("\nGeben Sie die zweite Zahl ein: ");
        double zahl2 = strtod(getString(256), NULL);
        printf("\nErgebnis der Addition beider Zahlen: %lf\nNoch eine Addition? (Y/N) ", zahl1 + zahl2);
        char input = fgetc(stdin);
        nochEineAddition = 0;
        if (input == 'y' || input == 'Y') {
            nochEineAddition = 1;
        }

    } while (nochEineAddition);
    pressAnyKeyMessage();
}

// Aufgabe 4
void zahlenKette() {
    clearScreen();
    printf("Bitte eine Zahl eingeben: ");
    int zahl = (int)strtol(getString(256), NULL, 10);
    puts("\na) Ausgabe:");
    for (int i = 1; i <= zahl; i++) {
        printf("%d", i);
        if (i != zahl) {
            printf(", ");
        }

    }

    puts("\n\nb) Ausgabe:");
    for (int i = 1; i <= zahl; i++) {
        if (i % 2 == 0) {
            printf("%d", i);
            if (i != zahl && i != zahl - 1) {
                printf(", ");
            }
        }
    }

    puts("");
    pressAnyKeyMessage();
}

// Aufgabe 5
void kleinesEinsMalEins() {
    clearScreen();
    for (int i = 1; i <= 10; i++){
        for (int j = 1; j <= 10; j++) {
            printf("%d * %d = %d\n", i, j, i*j);
        }
    }

    puts("");
    pressAnyKeyMessage();
}

// Aufgabe 6
void zahlenpyramide() {
    clearScreen();
    for (int i = 10; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            printf("%d ", j);
            if (j == 0) {
                printf("\n");
            }
        }
    }

    puts("");
    pressAnyKeyMessage();
}

void schleifenMenue() {
    while (1) {
        clearScreen();
        puts("Aufgaben zu Schleifen:");
        puts("1: 0 bis 9");
        puts("2: a bis z");
        puts("3: Addition");
        puts("4: Zahlenkette");
        puts("5: Kleines 1*1");
        puts("6: Zahlenpyramide");
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
            case 3:
                addition();
                break;
            case 4:
                zahlenKette();
                break;
            case 5:
                kleinesEinsMalEins();
                break;
            case 6:
                zahlenpyramide();
                break;
            default:
                // Nur zur Unterdrückung einer Warnung
                break;
        }
    }
}

