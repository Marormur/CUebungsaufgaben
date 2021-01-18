//
// Created by marvi on 14.01.2021.
//

#include "Funktionen.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../AllgemeineFunktionen.h"

// Aufgabe 1 a)

const int a_maxLaengeZeichenfolge = 128;
const int a_maxLaengeText = 1024;
int a_zahl1, a_zahl2, a_ergebnis, a_zahl1M, a_zahl2M, a_ergebnisM;
char a_wunschname[32], a_dateiname[37], a_text[1024], a_zeichenfolge[128];
char a_dateiEndung[] = ".txt";

int a_addition() {
    printf("Bitte geben Sie die erste Zahl ein: ");
    scanf("%d", &a_zahl1);
    printf("Bitte geben Sie die zweite Zahl ein: ");
    scanf("%d", &a_zahl2);
    a_ergebnis = a_zahl1 + a_zahl2;
    printf("Das ergebnis ist: %d \n\n", a_ergebnis);

    return (0);
}

int a_dateiAnlegen() {
    printf("Bitte geben Sie einen Dateinamen ein: ");
    scanf("%s", a_wunschname);
    strcpy(a_dateiname, a_wunschname);
    strcat(a_dateiname, a_dateiEndung);

    // hier erstellte Dateien werden im Ordner "cmake-build-debug" gespeichert
    FILE *datei;
    datei = fopen(a_dateiname, "w");
    fclose(datei);

    printf("Die Datei mit dem Namen '%s' wurde angelegt. \nDer Name ist %lu Zeichen lang\n", a_dateiname,
           strlen(a_dateiname));

    return (0);
}

// FIXME: Es wird nicht auf die erste Eingabe gewartet
int a_teiltextInTextSuchen() {
    printf("Bitte geben Sie den zu durchsuchenden Text ein: ");
    fgets(a_text, a_maxLaengeText, stdin);

    printf("Bitte geben Sie die zu suchende Zeichenfolge ein: ");
    fgets(a_zeichenfolge, a_maxLaengeZeichenfolge, stdin);

    if (strstr(a_text, a_zeichenfolge)) {
        printf("Der eingegebene Text enth\x84lt die Zeichenfolge '%s'.\n", a_zeichenfolge);
    } else {
        printf("Der eingegebene Text enth\x84lt die Zeichenfolge '%s' nicht.\n", a_zeichenfolge);
    }

    return (0);
}

int a_multiplikation() {
    printf("Bitte geben Sie die erste Zahl ein: ");
    scanf("%d", &a_zahl1M);
    printf("Bitte geben Sie die zweite Zahl ein: ");
    scanf("%d", &a_zahl2M);
    a_ergebnisM = a_zahl1M * a_zahl2M;
    printf("Das ergebnis ist: %d \n\n", a_ergebnisM);

    return (0);
}

void a_menue() {
    while (1) {
        clearScreen();
        puts("Aufgabe 1a)");
        puts("1: Addieren");
        puts("2: Datei anlegen");
        puts("3: Teiltext in Text suchen");
        puts("4: Multiplizieren");

        puts("0: Ende (Zurück zum Hauptmenü)");
        printf("\nTreffe eine Auswahl: ");
        int input = (int) strtol(getString(2), NULL, 10);
        switch (input) {
            case 0:
                return;
            case 1:
                a_addition();
            case 2:
                a_dateiAnlegen();
            case 3:
                a_teiltextInTextSuchen();
            case 4:
                a_multiplikation();
            default:
                // Nur zur Unterdrückung einer Warnung
                break;
        }
    }
}


// Aufgabe 1 b)

int b_addition() {
    int zahl1, zahl2, ergebnis;

    printf("Bitte geben Sie die erste Zahl ein: ");
    scanf("%d", &zahl1);
    printf("Bitte geben Sie die zweite Zahl ein: ");
    scanf("%d", &zahl2);
    ergebnis = zahl1 + zahl2;
    printf("Das ergebnis ist: %d \n\n", ergebnis);

    return (0);
}

int b_dateiAnlegen() {
    char wunschname[32], dateiname[37];
    char dateiEndung[] = ".txt";

    printf("Bitte geben Sie einen Dateinamen ein: ");
    scanf("%s", wunschname);
    strcpy(dateiname, wunschname);
    strcat(dateiname, dateiEndung);

    // hier erstellte Dateien werden im Ordner "cmake-build-debug" gespeichert
    FILE *datei;
    datei = fopen(dateiname, "w");
    fclose(datei);

    printf("Die Datei mit dem Namen '%s' wurde angelegt. \nDer Name ist %lu Zeichen lang\n", dateiname,
           strlen(dateiname));

    return (0);
}

// FIXME: Es wird nicht auf die erste Eingabe gewartet
int b_teiltextInTextSuchen() {
    char zeichenfolge[128], text[1024];

    printf("Bitte geben Sie den zu durchsuchenden Text ein: ");
    fgets(text, sizeof(text) / sizeof(text[0]), stdin);

    printf("Bitte geben Sie die zu suchende Zeichenfolge ein: ");
    fgets(zeichenfolge, sizeof(zeichenfolge) / sizeof(zeichenfolge[0]), stdin);

    if (strstr(a_text, a_zeichenfolge)) {
        printf("Der eingegebene Text enth\x84lt die Zeichenfolge '%s'.\n", zeichenfolge);
    } else {
        printf("Der eingegebene Text enth\x84lt die Zeichenfolge '%s' nicht.\n", zeichenfolge);
    }

    return (0);
}

int b_multiplikation() {
    int zahl1, zahl2, ergebnis;

    printf("Bitte geben Sie die erste Zahl ein: ");
    scanf("%d", &zahl1);
    printf("Bitte geben Sie die zweite Zahl ein: ");
    scanf("%d", &zahl2);
    ergebnis = zahl1 * zahl2;
    printf("Das ergebnis ist: %d \n\n", ergebnis);

    return (0);
}

void b_menue() {
    while (1) {
        clearScreen();
        puts("Aufgabe 1b)");
        puts("1: Addieren");
        puts("2: Datei anlegen");
        puts("3: Teiltext in Text suchen");
        puts("4: Multiplizieren");

        puts("0: Ende (Zurück zum Hauptmenü)");
        printf("\nTreffe eine Auswahl: ");
        int input = (int) strtol(getString(2), NULL, 10);
        switch (input) {
            case 0:
                return;
            case 1:
                b_addition();
            case 2:
                b_dateiAnlegen();
            case 3:
                b_teiltextInTextSuchen();
            case 4:
                b_multiplikation();
            default:
                // Nur zur Unterdrückung einer Warnung
                break;
        }
    }
}


// Aufgabe 1 c)

int c_addition(int zahl1, int zahl2) {
    return zahl1 + zahl2;
}

int c_additionWrapper() {
    int zahl1, zahl2, ergebnis;

    printf("Bitte geben Sie die erste Zahl ein: ");
    scanf("%d", &zahl1);
    printf("Bitte geben Sie die zweite Zahl ein: ");
    scanf("%d", &zahl2);

    ergebnis = c_addition(zahl1, zahl2);
    printf("Rückgabewert: %d\n", ergebnis);

    printf("Das ergebnis ist: %d \n\n", ergebnis);

    return (0);
}

int c_dateiAnlegen(char wunschname[32]) {
    char dateiname[37];
    char dateiEndung[] = ".txt";

    strcpy(dateiname, wunschname);
    strcat(dateiname, dateiEndung);

    // hier erstellte Dateien werden im Ordner "cmake-build-debug" gespeichert
    FILE *datei;
    datei = fopen(dateiname, "w");
    fclose(datei);

    printf("Die Datei mit dem Namen '%s' wurde angelegt. \n", dateiname);

    return strlen(dateiname);
}

int c_dateiAnlegenWrapper() {
    char wunschname[32];
    int laengeGesamtname;

    printf("Bitte geben Sie einen Dateinamen ein: ");
    scanf("%s", wunschname);

    laengeGesamtname = c_dateiAnlegen(wunschname);
    printf("Rückgabewert: %d\n", laengeGesamtname);

    printf("Der Name ist %d Zeichen lang\n", laengeGesamtname);

    return (0);
}

bool c_teiltextInTextSuchen(char text[1024], char zeichenfolge[128]) {
    return strstr(text, zeichenfolge);
}

// FIXME: Es wird nicht auf die erste Eingabe gewartet
int c_teiltextInTextSuchenWrapper() {
    char zeichenfolge[128], text[1024];
    bool enthalten;

    printf("Bitte geben Sie den zu durchsuchenden Text ein: ");
    fgets(text, sizeof(text) / sizeof(text[0]), stdin);

    printf("Bitte geben Sie die zu suchende Zeichenfolge ein: ");
    fgets(zeichenfolge, sizeof(zeichenfolge) / sizeof(zeichenfolge[0]), stdin);

    enthalten = c_teiltextInTextSuchen(text, zeichenfolge);
    fputs(enthalten ? "Rückgabewert: true\n" : "Rückgabewert: flase\n", stdout);

    if (enthalten) {
        printf("Der eingegebene Text enth\x84lt die Zeichenfolge '%s'.\n", zeichenfolge);
    } else {
        printf("Der eingegebene Text enth\x84lt die Zeichenfolge '%s' nicht.\n", zeichenfolge);
    }

    return (0);
}

int c_multiplikation(int zahl1, int zahl2) {
    return zahl1 * zahl2;
}

int c_multiplikationWrapper() {
    int zahl1, zahl2, ergebnis;

    printf("Bitte geben Sie die erste Zahl ein: ");
    scanf("%d", &zahl1);
    printf("Bitte geben Sie die zweite Zahl ein: ");
    scanf("%d", &zahl2);

    ergebnis = c_multiplikation(zahl1, zahl2);
    printf("Rückgabewert: %d", ergebnis);

    printf("Das ergebnis ist: %d \n\n", ergebnis);

    return (0);
}

void c_menue() {
    while (1) {
        clearScreen();
        puts("Aufgabe 1b)");
        puts("1: Addieren");
        puts("2: Datei anlegen");
        puts("3: Teiltext in Text suchen");
        puts("4: Multiplizieren");

        puts("0: Ende (Zurück zum Hauptmenü)");
        printf("\nTreffe eine Auswahl: ");
        int input = (int) strtol(getString(2), NULL, 10);
        switch (input) {
            case 0:
                return;
            case 1:
                c_additionWrapper();
            case 2:
                c_dateiAnlegenWrapper();
            case 3:
                c_teiltextInTextSuchenWrapper();
            case 4:
                c_multiplikationWrapper();
            default:
                // Nur zur Unterdrückung einer Warnung
                break;
        }
    }
}

void funktionenMenue() {
    while (1) {
        clearScreen();
        puts("Aufgaben zu Funktionen:");
        puts("1: Funktionen erhalten / liefern keine Werte, alle Variablen global");
        puts("2: Funktionen erhalten / liefern keine Werte, alle Variablen lokal");
        puts("3: Alle Funktionen erhalten alle Werte, die sie ben\x94tigen & liefern Werte zurück");
        puts("4: ");

        puts("0: Zur\x81 \bck zum Hauptmen\x81");
        printf("\nTreffe eine Auswahl: ");
        int input = (int) strtol(getString(2), NULL, 10);
        switch (input) {
            case 0:
                return;
            case 1:
                a_menue();
            case 2:
                b_menue();
            case 3:
                c_menue();
            case 4:
                break;
            default:
                // Nur zur Unterdrückung einer Warnung
                break;
        }
    }
}
