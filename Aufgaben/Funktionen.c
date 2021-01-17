//
// Created by marvi on 14.01.2021.
//

#include "Funktionen.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../AllgemeineFunktionen.h"

// Aufgabe 1 a)

const int a_maxLaengeZeichenfolge = 128;
const int a_maxLaengeText = 1024;
int a_zahl1, a_zahl2, a_ergebnis, a_zahl1M, a_zahl2M, a_ergebnisM;
char a_wunschname[32], a_dateiname[37], a_text[a_maxLaengeText], a_zeichenfolge[a_maxLaengeZeichenfolge];
char a_dateiEndung[] = ".txt";

void a_addition() {
    printf("Bitte geben Sie die erste Zahl ein: ");
    scanf("%d", &a_zahl1);
    printf("Bitte geben Sie die zweite Zahl ein: ");
    scanf("%d", &a_zahl2);
    a_ergebnis = a_zahl1 + a_zahl2;
    printf("Das ergebnis ist: %d \n\n", a_ergebnis);
}

void a_dateiAnlegen() {
    printf("Bitte geben Sie einen Dateinamen ein: ");
    scanf("%s", a_wunschname);
    strcpy(a_dateiname, a_wunschname);
    strcat(a_dateiname, a_dateiEndung);

    // hier erstellte Dateien werden im Ordner "cmake-build-debug" gespeichert
    FILE * datei;
    datei = fopen(a_dateiname, "w");
    fclose(datei);

    printf("Die Datei mit dem Namen '%s' wurde angelegt. \nDer Name ist %lu Zeichen lang\n", a_dateiname, strlen(a_dateiname));
}

// FIXME: Es wird nicht auf die erste Eingabe gewartet
void a_teiltextInTextSuchen() {
    printf("Bitte geben Sie den zu durchsuchenden Text ein: ");
    fgets(a_text, a_maxLaengeText, stdin);

    printf("Bitte geben Sie die zu suchende Zeichenfolge ein: ");
    fgets(a_zeichenfolge, a_maxLaengeZeichenfolge, stdin);

    if (strstr(a_text, a_zeichenfolge)) {
        printf("Der eingegebene Text enthält die Zeichenfolge '%s'.\n", a_zeichenfolge);
    } else {
        printf("Der eingegebene Text enthält die Zeichenfolge '%s' nicht.\n", a_zeichenfolge);
    }
}

void a_multiplikation() {
    printf("Bitte geben Sie die erste Zahl ein: ");
    scanf("%d", &a_zahl1M);
    printf("Bitte geben Sie die zweite Zahl ein: ");
    scanf("%d", &a_zahl2M);
    a_ergebnisM = a_zahl1M * a_zahl2M;
    printf("Das ergebnis ist: %d \n\n", a_ergebnisM);
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
        int input = (int)strtol(getString(2), NULL, 10);
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

void b_addition() {
    int zahl1, zahl2, ergebnis;

    printf("Bitte geben Sie die erste Zahl ein: ");
    scanf("%d", &zahl1);
    printf("Bitte geben Sie die zweite Zahl ein: ");
    scanf("%d", &zahl2);
    ergebnis = zahl1 + zahl2;
    printf("Das ergebnis ist: %d \n\n", ergebnis);
}

void b_dateiAnlegen() {
    char wunschname[32], dateiname[37];
    char dateiEndung[] = ".txt";

    printf("Bitte geben Sie einen Dateinamen ein: ");
    scanf("%s", wunschname);
    strcpy(dateiname, wunschname);
    strcat(dateiname, dateiEndung);

    // hier erstellte Dateien werden im Ordner "cmake-build-debug" gespeichert
    FILE * datei;
    datei = fopen(dateiname, "w");
    fclose(datei);

    printf("Die Datei mit dem Namen '%s' wurde angelegt. \nDer Name ist %lu Zeichen lang\n", dateiname, strlen(dateiname));
}

// FIXME: Es wird nicht auf die erste Eingabe gewartet
void b_teiltextInTextSuchen() {
    const int maxLaengeZeichenfolge = 128;
    const int maxLaengeText = 1024;
    char zeichenfolge[maxLaengeZeichenfolge], text[maxLaengeText];

    printf("Bitte geben Sie den zu durchsuchenden Text ein: ");
    fgets(text, maxLaengeText, stdin);

    printf("Bitte geben Sie die zu suchende Zeichenfolge ein: ");
    fgets(zeichenfolge, maxLaengeZeichenfolge, stdin);

    if (strstr(a_text, a_zeichenfolge)) {
        printf("Der eingegebene Text enthält die Zeichenfolge '%s'.\n", zeichenfolge);
    } else {
        printf("Der eingegebene Text enthält die Zeichenfolge '%s' nicht.\n", zeichenfolge);
    }
}

void b_multiplikation() {
    int zahl1, zahl2, ergebnis;

    printf("Bitte geben Sie die erste Zahl ein: ");
    scanf("%d", &zahl1);
    printf("Bitte geben Sie die zweite Zahl ein: ");
    scanf("%d", &zahl2);
    ergebnis = zahl1 * zahl2;
    printf("Das ergebnis ist: %d \n\n", ergebnis);
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
        int input = (int)strtol(getString(2), NULL, 10);
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


void funktionenMenue() {
    while (1) {
        clearScreen();
        puts("Aufgaben zu Funktionen:");
        puts("1: Funktionen erhalten / liefern keine Werte, alle Variablen global");
        puts("2: Funktionen erhalten / liefern keine Werte, alle Variablen lokal");
        puts("3: ");
        puts("4: ");

        puts("0: Zurück zum Hauptmenü");
        printf("\nTreffe eine Auswahl: ");
        int input = (int)strtol(getString(2), NULL, 10);
        switch (input) {
            case 0:
                return;
            case 1:
                a_menue();
            case 2:
                b_menue();
            case 3:
                break;
            case 4:
                break;
            default:
                // Nur zur Unterdrückung einer Warnung
                break;
        }
    }
}
