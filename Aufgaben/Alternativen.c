//
// Created by Marvin Temmen on 06.05.20.
//

#include "../AllgemeineFunktionen.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// Aufgabe 1
void begruessung() {
    clearScreen();
    printf("Bitte geben Sie Ihren Nachnamen ein: ");
    char *nachname = getString(256);
    printf("Bitte geben Sie Ihr Geschlecht (m/w) ein: ");

    // Hier muss ich 2 Zeichen abfragen, da sonst "\n" genommen wird
    char geschlecht = getString(2)[0]; // Index 0, weil ich kein Interesse an "\n" habe
    if (geschlecht > 96) { // Wenn ein kleiner Buchstabe eingegeben wurde
        geschlecht -= 32; // Dann soll daraus ein großer gemacht werden
    }

    switch (geschlecht) {
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
    pressAnyKeyMessage();
}

// Aufgabe 2
void notenLookup() {
    clearScreen();
    printf("Geben Sie eine Note (1-6) ein: ");
    long note = strtol(getString(2), NULL , 10);
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
    long input = strtol(getString(256), NULL, 10);
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
    zahl1 = (int)strtol(getString(2), NULL, 10);
    printf("\n2. Zahl: ");
    zahl2 = (int)strtol(getString(2), NULL, 10);
    printf("\n3. Zahl: ");
    zahl3 = (int)strtol(getString(2), NULL, 10);
    int groessteZahl = zahl1, kleinsteZahl = zahl2;

    // TODO


    printf("\n\nKleinste Zahl: %d", kleinsteZahl);
    printf("\nGroesste Zahl: %d\n", groessteZahl);
    pressAnyKeyMessage();
}

void datum() {
    clearScreen();
    int jahr,monat,tag;
    printf("Bitte geben Sie das Jahr ein : ");
    jahr = (int)strtol(getString(5), NULL, 10);
    printf("\nBitte geben Sie den Monat ein: ");
    monat = (int)strtol(getString(3), NULL, 10);
    printf("\nBitte geben Sie den Tag ein  :");
    tag = (int)strtol(getString(3), NULL, 10);
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
        int input = (int)strtol(getString(2), NULL, 10);
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