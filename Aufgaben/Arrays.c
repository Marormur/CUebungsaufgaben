//
// Created by Marvin Temmen on 09.06.20.
//

#include "Arrays.h"
#include "../AllgemeineFunktionen.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
    int eingaben[20][2];

    // Versuche jede Mögliche Eingabe abzufragen
    for (int i = 0; i < 20; i++) {
        printf("Geben Sie eine Liter-Zahl an: ");
        int literEingabe = (int)strtol(getString(32), NULL, 0);
        printf("Geben Sie eine KM-Zahl ein: ");
        int kilometerEingabe = (int)strtol(getString(32), NULL, 0);

        // Wenn beides 0 ist, soll die Eingabe beendet werden
        if (literEingabe == 0 && kilometerEingabe == 0) {
            break;
        }

        eingaben[i][0] = literEingabe;
        eingaben[i][1] = kilometerEingabe;
    }

    // TODO: schauen, wie ich das rechne; bin gerade zu faul

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
        puts("9: Sortierverfahren");
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
                break;
            case 7:
                break;
            case 8:
                break;

            // Ist Aufgabe 8 von Blatt für Sortierverfahren
            case 9:
                break;
            default:
                // Nur zur Unterdrückung einer Warnung
                break;
        }
    }
}