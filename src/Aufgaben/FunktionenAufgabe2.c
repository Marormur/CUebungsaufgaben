#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../AllgemeineFunktionen.h"

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
    pressAnyKeyMessage();

    return (0);
}

int c_dateiAnlegen(char wunschname[32]) {
    char dateiname[37];
    char dateiEndung[] = ".txt";

    strcpy(dateiname, wunschname);
    strcat(dateiname, dateiEndung);

    // hier erstellte Dateien werden im Ordner "cmake-build-debug" gespeichert
    FILE* datei;
    datei = fopen(dateiname, "w");
    fclose(datei);

    printf("Die Datei mit dem Namen '%s' wurde angelegt. \n", dateiname);
    pressAnyKeyMessage();

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
    pressAnyKeyMessage();

    return (0);
}

bool c_teiltextInTextSuchen(char text[1024], char zeichenfolge[128]) {
    return strstr(text, zeichenfolge);
}

int c_teiltextInTextSuchenWrapper() {
    int zeichenfolgeLaenge = 128, textLaenge = 1024;
    char* zeichenfolge = malloc(zeichenfolgeLaenge);
    char* text = malloc(textLaenge);
    bool enthalten;

    printf("Bitte geben Sie den zu durchsuchenden Text ein: ");
    text = getString(textLaenge);

    printf("Bitte geben Sie die zu suchende Zeichenfolge ein: ");
    zeichenfolge = getString(zeichenfolgeLaenge);

    enthalten = c_teiltextInTextSuchen(text, zeichenfolge);
    fputs(enthalten ? "Rückgabewert: true\n" : "Rückgabewert: flase\n", stdout);

    if (enthalten) {
        printf("Der eingegebene Text enthält die Zeichenfolge '%s'.\n", zeichenfolge);
    }
    else {
        printf("Der eingegebene Text enthält die Zeichenfolge '%s' nicht.\n", zeichenfolge);
    }

    pressAnyKeyMessage();
    free(zeichenfolge);
    free(text);
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

    pressAnyKeyMessage();
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
        int input = (int)strtol(getString(2), NULL, 10);
        switch (input) {
        case 0:
            return;
        case 1:
            c_additionWrapper();
            break;
        case 2:
            c_dateiAnlegenWrapper();
            break;
        case 3:
            c_teiltextInTextSuchenWrapper();
            break;
        case 4:
            c_multiplikationWrapper();
            break;
        default:
            // Nur zur Unterdrückung einer Warnung
            break;
        }
    }
}