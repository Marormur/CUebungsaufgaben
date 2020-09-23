//
// Created by Marvin Temmen on 09.06.20.
//

#include "Arrays.h"
#include "../AllgemeineFunktionen.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Aufgabe 1
void einsBisZehn() {
    clearScreen();
    int zahlen[] = { 1,2,3,4,5,6,7,8,9,10};
    int arrayLaenge = sizeof(zahlen) / sizeof(*zahlen); // Einfach weil ich keine 10 harcoden will
    for (int i = 0; i < arrayLaenge; i++) {
        printf("%d", *zahlen+i);
        if (i == arrayLaenge-1) {
            puts("");
        } else {
            printf(", ");
        }
    }

    for (int j = arrayLaenge-1; j >= 0; j--) {
        printf("%d", *zahlen+j);
        if (j == 0) {
            puts("");
        } else {
            printf(", ");
        }
    }

    puts("");
    pressAnyKeyMessage();
}

// Aufgabe 2
void einsBisZehnMultiplikation() {
    clearScreen();
    int zahlen[] = { 1,2,3,4,5,6,7,8,9,10};
    int arrayLaenge = sizeof(zahlen) / sizeof(*zahlen); // Einfach weil ich keine 10 harcoden will
    for (int i = 0; i < arrayLaenge; i++) {
        printf("%d", *zahlen+i);
        if (i != arrayLaenge-1) {
            printf(" * ");
        }
    }

    int ergebnis = 1*2;
    for(int i = 2; i < arrayLaenge; i++) {
        ergebnis = ergebnis * (*zahlen+i);
    }

    printf(" = %d\n\n", ergebnis);

    pressAnyKeyMessage();
}

// Aufgabe 3
void zweierPotenz() {
    clearScreen();
    printf("Welche 2er-Potenz wollen Sie sich anzeigen lassen? 2 hoch ");
    int eingabe = (int)strtol(getString(3), NULL, 10);
    int potenzen[] = {1,2,4,8,16,32,64,128,256,512,1024};
    if (eingabe < 0 || eingabe > (sizeof(potenzen) / sizeof(*potenzen))) {
        printf("Die Eingabe muss zwischen 0 und 10 sein!\n\n");
        pressAnyKeyMessage();
        return;
    }

    printf("2 hoch %d ist: %d\n\n", eingabe, potenzen[eingabe]);
    pressAnyKeyMessage();
}

// Aufgabe 4
void durchschnittverbrauch() {
    clearScreen();
    float wertePaare[20][2];
    float liter = 0;
    float km = 0;
    for (int i = 0; i < 20; ++i) {
        printf("Geben Sie eine Liter-Zahl ein: ");
        scanf("%f", &wertePaare[i][0]);
        printf("Geben Sie eine KM-Zahl ein: ");
        scanf("%f", &wertePaare[i][1]);
        liter = liter + wertePaare[i][0];
        km = km + wertePaare[i][1];
        if (wertePaare[i][0] == 0 && wertePaare[i][1] == 0) {
            i = 20;
        }
    }
    float verbrauch = liter / km * 100;
    printf("Ihr Auto verbraucht %f Liter auf 100Km", verbrauch);
    pressAnyKeyMessage();
}

// Aufgabe 5
void buchstabenanzahl() {
    clearScreen();
    printf("Geben Sie ein Wort ein: ");
    int stringLaenge = 1024;
    char wortEingabe[stringLaenge];
    strcpy(wortEingabe, getString(stringLaenge));
    printf("Geben Sie einen Buchstaben ein: ");
    char buchstabe = *getString(2);
    int buchstabenGefunden = 0;
    char buchstabeZumArbeiten = buchstabe;

    // Wenn es sich um einen kleinen Buchstaben handelt, soll dieser groß gemacht werden
    if (buchstabeZumArbeiten > 96) {
        buchstabeZumArbeiten = (char)(buchstabeZumArbeiten-32);
    }

    for (int i = 0; i < strlen(wortEingabe); ++i) {

        // Groß- und Kleinschreibung ist bei mir egal, also prüfe ich auf beides
        if (wortEingabe[i] == buchstabeZumArbeiten || (char)(wortEingabe[i] - 32) == buchstabeZumArbeiten) {
            buchstabenGefunden++;
        }
    }

    printf("\n\"%c\" ist %d mal in dem Wort enthalten.\n\n", buchstabe, buchstabenGefunden);
    pressAnyKeyMessage();
}

// Aufgabe 6
void buchstabenanzahlSatz() {
    char eingabeString[33];
    char eingabeBuchstabe;
    int bstCount = 0;
    printf("Geben Sie einen Satz ein (max 32 zeichen): ");
    gets(eingabeString);
    printf("Geben Sie einen Buchstaben ein: ");
    scanf(" %c", &eingabeBuchstabe);
    char eingBst = tolower(eingabeBuchstabe);
    for (int i = 0; i < 32; ++i) {
        char strCheck = tolower(eingabeString[i]);
        if (strCheck == eingBst) {
            bstCount++;
        }
    }
    printf("%c ist %i mal in dem Satz enthalten", eingabeBuchstabe, bstCount);
}

// Mehrdimensionale Arrays
// Aufgabe 1
void summen() {
    clearScreen();

    int zahlen[5][5];

    for (int i = 0; i < 9; i-=-1) {
        printf("Geben Sie Wert &d ein: ", i);
        int input = (int)strtol(getString(32), NULL, 10);

    }


    pressAnyKeyMessage();
}

void arraysMenue() {
    while (1) {
        clearScreen();
        puts("Eindimensionale Arrays:");
        puts("1: 1 bis 10");
        puts("2: 1 bis 10 Multiplikation");
        puts("3: 2er-Potenz");
        puts("4: Durchschnittsverbrauch");
        puts("5: Buchstabenanzahl");
        puts("6: Buchstabenanzahl mit Satzeingabe");
        puts("7: Buchstabenanzahl Alphabet");
        puts("8: Durchschnittsverbrauch erweitert");
        puts("\nMehrdimensionale Arrays:");
        puts("9: Summen");

        puts("0: Zurück zum Hauptmenü");
        printf("\nTreffe eine Auswahl: ");
        int input = (int)strtol(getString(2), NULL, 10);
        switch (input) {
            case 0:
                return;
            case 1:
                einsBisZehn();
                break;
            case 2:
                einsBisZehnMultiplikation();
                break;
            case 3:
                zweierPotenz();
                break;
            case 4:
                durchschnittverbrauch();
                break;
            case 5:
                buchstabenanzahl();
                break;
            case 6:
                buchstabenanzahlSatz();
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            default:
                // Nur zur Unterdrückung einer Warnung
                break;
        }
    }
}