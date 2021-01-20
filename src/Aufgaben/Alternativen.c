//
// Created by Marvin Temmen on 06.05.20.
//

#include "../AllgemeineFunktionen.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "Alternativen.h"

// Aufgabe 1
void begruessung() {
    clearScreen();
    printf("Bitte geben Sie Ihren Nachnamen ein: ");
    char *nachname = getString(256);
    printf("Bitte geben Sie Ihr Geschlecht (m/w) ein: ");

    // Hier muss ich 2 Zeichen abfragen, da sonst "\n" genommen wird
    char* geschlechtInput = getString(2);
    if (geschlechtInput[0] > 96) { // Wenn ein kleiner Buchstabe eingegeben wurde
        geschlechtInput[0] -= 32; // Dann soll daraus ein großer gemacht werden
    }

    switch (geschlechtInput[0]) {
        case 'M':
            printf("\nGuten Tag, Herr %s\n", nachname);
            break;
        case 'W':
            printf("\nGuten Tag, Frau %s\n", nachname);
            break;
        default:
            puts("Ungültiges Geschlecht!");
            return;
    }

    free(nachname);
    free(geschlechtInput);
    pressAnyKeyMessage();
}

// Aufgabe 2
void notenLookup() {
    clearScreen();
    printf("Geben Sie eine Note (1-6) ein: ");
    char* input = getString(2);
    long note = strtol(input, NULL , 10);
    free(input);
    switch (note) {
        case 1:
            printf("\nSehr gut\n\n");
            break;
        case 2:
            printf("\nGut\n\n");
            break;
        case 3:
            printf("\nBefriedigend\n\n");
            break;
        case 4:
            printf("\nAusreichend\n\n");
            break;
        case 5:
            printf("\nMangelhaft\n\n");
            break;
        case 6:
            printf("\nUngenügend\n\n");
            break;
        default:
            printf("\nDie Eingabe stellt keine Note dar!\n\n");
            break;
    }

    pressAnyKeyMessage();
}

// Aufgabe 3
void menue() {
    clearScreen();
    puts("(1) Daten laden");
    puts("(2) Daten ergänzen");
    puts("(3) Daten löschen");
    puts("(4) Daten auswerten");
    puts("(5) Daten speichern");
    puts("(0) ENDE");
    printf("Ihre Eingabe: ");
    char* menueInput = getString(256);
    long input = strtol(menueInput, NULL, 10);
    free(menueInput);
    switch (input) {
        case 1:
            printf("\nSie haben \"Daten laden\" gewählt.\n");
            break;
        case 2:
            printf("\nSie haben \"Daten ergänzen\" gewählt.\n");
            break;
        case 3:
            printf("\nSie haben \"Daten löschen\" gewählt.\n");
            break;
        case 4:
            printf("\nSie haben \"Daten auswerten\" gewählt.\n");
            break;
        case 5:
            printf("\nSie haben \"Daten speichern\" gewählt.\n");
            break;
        case 0:
            printf("\nSie haben \"ENDE\" gewählt.\n");
            break;
        default:
            printf("\nUngültige Eingabe!\n");
            break;
    }

    pressAnyKeyMessage();
}

void dreiZahlen() {
    clearScreen();
    int zahl1, zahl2, zahl3;
    printf("1. Zahl: ");
    int groessteZahl, kleinsteZahl;
    char* zahl1Input = getString(256);
    zahl1 = (int)strtol(zahl1Input, NULL, 10);
    free(zahl1Input);
    groessteZahl = zahl1;
    kleinsteZahl = zahl1;

    printf("\n2. Zahl: ");
    char* zahl2Input = getString(256);
    zahl2 = (int)strtol(zahl2Input, NULL, 10);
    free(zahl2Input);
    if (zahl2 > zahl1) { // If-Alternative 1
        groessteZahl = zahl2;
    } else {
        kleinsteZahl = zahl2;
    }

    printf("\n3. Zahl: ");
    char* zahl3Input = getString(256);
    zahl3 = (int)strtol(zahl3Input, NULL, 10);
    free(zahl3Input);
    if (zahl3 > groessteZahl) {
        groessteZahl = zahl3;
    } else if (zahl3 < kleinsteZahl) {
        kleinsteZahl = zahl3;
    }

    printf("\n\nKleinste Zahl: %d", kleinsteZahl);
    printf("\nGroesste Zahl: %d\n", groessteZahl);
    pressAnyKeyMessage();
}

void datum() {
    clearScreen();
    int jahr,monat,tag;
    printf("Bitte geben Sie das Jahr ein : ");
    char* jahrInput = getString(5);
    jahr = (int)strtol(jahrInput, NULL, 10);
    free(jahrInput);
    printf("\nBitte geben Sie den Monat ein: ");
    char* monatInput = getString(3);
    monat = (int)strtol(monatInput, NULL, 10);
    free(monatInput);
    printf("\nBitte geben Sie den Tag ein  :");
    char* tagInput = getString(3);
    tag = (int)strtol(tagInput, NULL, 10);
    free(tagInput);
    int gueltigesDatum = 1;
    time_t zeit;
    time(&zeit);
    struct tm *info;
    info = localtime(&zeit);

    // Für mich ist einfach mal jedes Datum in der Zukunft nicht gültig
    if (jahr > (info->tm_year)+1900){
        gueltigesDatum = 0;
    }

    if (monat > 12 || monat < 1) {
        gueltigesDatum = 0;
    }

    if (tag < 1 || tag > 31) {
        gueltigesDatum = 0;
    }

    if (monat == 2){
        if (tag > 29) {
            gueltigesDatum = 0;
        }

        int schaltjahr = 0;
        if (jahr % 4 == 0 && jahr % 100 != 0) {
            schaltjahr = 1;
        } else if (jahr % 4 == 0 &&
                    jahr % 100 == 0 &&
                    jahr % 400 == 0){
            schaltjahr = 1;
        }

        if (!schaltjahr && tag > 28) {
            gueltigesDatum = 0;
        }
    }

    char korrektChar = 127;
    if (!gueltigesDatum){
        korrektChar = 'k';
    }

    printf("\n\n%d.%d.%d ist %cein korrektes Datum\n\n", tag, monat, jahr, korrektChar);
    pressAnyKeyMessage();
}

void alternativenMenue() {
    while (1) {
        clearScreen();
        puts("Aufgaben zu Alternativen:");
        puts("1: Begrüßung");
        puts("2: Schulnoten");
        puts("3: Menü");
        puts("4: Drei Zahlen");
        puts("5: Datum");
        puts("0: Zurück zum Hauptmenü");
        printf("\nTreffe eine Auswahl: ");
        char* menueInput = getString(2);
        int input = (int)strtol(menueInput, NULL, 10);
        free(menueInput);
        switch (input) {
            case 0:
                return;
            case 1:
                begruessung();
                break;
            case 2:
                notenLookup();
                break;
            case 3:
                menue();
                break;
            case 4:
                dreiZahlen();
                break;
            case 5:
                datum();
                break;
            default:
                // Nur zur Unterdrückung einer Warnung
                break;
        }
    }
}