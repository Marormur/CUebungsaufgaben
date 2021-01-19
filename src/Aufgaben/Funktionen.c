//
// Created by marvi on 14.01.2021.
//

#include "Funktionen.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../AllgemeineFunktionen.h"
#include "FunktionenAufgabe2.h"

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
    pressAnyKeyMessage();
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
    pressAnyKeyMessage();
    return (0);
}

// FIXME: Es wird nicht auf die erste Eingabe gewartet
int a_teiltextInTextSuchen() {
    printf("Bitte geben Sie den zu durchsuchenden Text ein: ");
    fgets(a_text, a_maxLaengeText, stdin);

    printf("Bitte geben Sie die zu suchende Zeichenfolge ein: ");
    fgets(a_zeichenfolge, a_maxLaengeZeichenfolge, stdin);

    if (strstr(a_text, a_zeichenfolge)) {
        printf("Der eingegebene Text enthält die Zeichenfolge '%s'.\n", a_zeichenfolge);
    } else {
        printf("Der eingegebene Text enthält die Zeichenfolge '%s' nicht.\n", a_zeichenfolge);
    }

    pressAnyKeyMessage();
    return (0);
}

int a_multiplikation() {
    printf("Bitte geben Sie die erste Zahl ein: ");
    scanf("%d", &a_zahl1M);
    printf("Bitte geben Sie die zweite Zahl ein: ");
    scanf("%d", &a_zahl2M);
    a_ergebnisM = a_zahl1M * a_zahl2M;
    printf("Das ergebnis ist: %d \n\n", a_ergebnisM);
    pressAnyKeyMessage();
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
                break;
            case 2:
                a_dateiAnlegen();
                break;
            case 3:
                a_teiltextInTextSuchen();
                break;
            case 4:
                a_multiplikation();
                break;
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
    pressAnyKeyMessage();
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
    pressAnyKeyMessage();
    return (0);
}

int b_teiltextInTextSuchen() {
    int zeichenfolgeLaenge = 128, textLaenge = 1024;
    char* text = malloc(textLaenge);
    char* zeichenfolge = malloc(zeichenfolgeLaenge);
    printf("Bitte geben Sie den zu durchsuchenden Text ein: ");
    text = getString(textLaenge);
    
    printf("Bitte geben Sie die zu suchende Zeichenfolge ein: ");
    zeichenfolge = getString(zeichenfolgeLaenge);
    
    if (strstr(a_text, a_zeichenfolge)) {
        printf("Der eingegebene Text enthält die Zeichenfolge '%s'.\n", zeichenfolge);
    } else {
        printf("Der eingegebene Text enthält die Zeichenfolge '%s' nicht.\n", zeichenfolge);
    }

    pressAnyKeyMessage();
    free(text);
    free(zeichenfolge);
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
    pressAnyKeyMessage();
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
                break;
            case 2:
                b_dateiAnlegen();
                break;
            case 3:
                b_teiltextInTextSuchen();
                break;
            case 4:
                b_multiplikation();
                break;
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
        puts("3: Alle Funktionen erhalten alle Werte, die sie benötigen & liefern Werte zurück");
        puts("4: ");

        puts("0: Zurück zum Hauptmenü");
        printf("\nTreffe eine Auswahl: ");
        int input = (int) strtol(getString(2), NULL, 10);
        switch (input) {
            case 0:
                return;
            case 1:
                a_menue();
                break;
            case 2:
                b_menue();
                break;
            case 3:
                c_menue();
                break;
            case 4:
                break;
            default:
                // Nur zur Unterdrückung einer Warnung
                break;
        }
    }
}
