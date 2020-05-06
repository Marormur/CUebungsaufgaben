//
// Created by Marvin Temmen on 26.03.20.
//

#include <stdio.h>
#include <stdlib.h>
#include "EinUndAusgabe.h"
#include "../AllgemeineFunktionen.h"

// Aufgabe 1
void halloWeltAufgabe() {
    clearScreen();
    puts("==== Einfacher Ausgabe-Befehl ====");
    puts("Hallo Welt!!! Dies ist mein erstes Programm.");

    puts("\n==== Einfache Ausgabe-Befehle ====");
    puts("Hallo Welt!!!");
    puts("\t\tHallo Welt!!!");
    puts("\t\t\t\tHallo Welt!!!");
    puts("\t\t\t\t\t\tHallo Welt!!!");

    puts("\n==== Ausgabe-Befehle \\t und \\n ====");

    // Hier verwende ich mal printf, damit das \n manuell angegeben werden muss und das dann mehr der Aufgabenstellung entspricht
    printf("Hallo Welt!!!\t\t\t\t\tHallo Welt!!!\n");
    printf("\t\t\tHallo Welt!!!\n");
    printf("Hallo Welt!!!\t\t\t\t\tHallo Welt!!!\n");

    puts("\n==== Ausgabe-Befehle zur Ausgabe von Variablen und Text ====");
    puts("Ich stehe direkt in einem Ausgabebefehl");
    char Text1[] = "Ich stehe direkt in einer Variablen \"Text1\", die in einem Ausgabebefehl steht.";
    printf("%s\n", Text1);
    int zahl1, zahl2;
    zahl1 = 120;
    zahl2 = 100;
    printf("Diesse Zahl steht in der Variablen zahl1: %d\n", zahl1);
    printf("Diesse Zahl steht in der Variablen zahl2: %d\n\n", zahl2);

    puts("Mit uns kann man in Ausgabebefehlen rechnen!");
    printf("Das Ergebnis der Addition lautet      : %d\n", zahl1 + zahl2);
    printf("Das Ergebnis der Subtraktion lautet   : %d\n", zahl1 - zahl2);
    printf("Das Ergebnis der Multiplikation lautet: %d\n", zahl1 * zahl2);
    printf("Das Ergebnis der Division lautet      : %f\n\n", (float)zahl1 / zahl2);

    puts("Schöner sind die Ausgaben so:");
    printf("Das Ergebnis von 100 + 120 = %d\n", zahl2 + zahl1);
    printf("Das Ergebnis von 120 - 100 = %d\n", zahl1 - zahl2);
    printf("Das Ergebnis von 100 * 120 = %d\n", zahl2 * zahl1);
    printf("Das Ergebnis von 120 / 100 = %f\n\n", (float)zahl1 / zahl2);
    pressAnyKeyMessage();
}

// Aufgabe 2
void spareinlageAufgabe() {
    clearScreen();

    // Bei Geld nimmt man immer lieber mal einen double
    double startkapital, zinssatz;
    printf("Bitte geben Sie ihr Startkapital ein: ");
    int eingabeResult = scanf(" %lf\n", &startkapital);
    if (eingabeResult == EOF || eingabeResult == 0) {
        puts("Fehler mit der Eingabe!");
        puts("Drücke eine beliebige Taste zum Fortfahren...");
        fgetc(stdin);
        return;
    }

    printf("Bitte geben Sie den Zinssatz an     : ");
    eingabeResult = scanf("%lf", &zinssatz);
    if (eingabeResult == EOF || eingabeResult == 0) {
        puts("Fehler mit der Eingabe!");
        puts("Drücke eine beliebige Taste zum Fortfahren...");
        fflush(stdin);
        fgetc(stdin);
        return;
    }

    // Mit ".2" vor dem "lf" kann man in einem formatierten String die Nachkommastellen eines doubles (oder auch float) auf 2 Stellen begrenzen
    printf("\nDas Endkapital nach 3 Jahren beläuft sich auf %.2lf\n\n", startkapital * pow(1 + zinssatz / 100, 3));

    pressAnyKeyMessage();
}

// Aufgabe 3 (2 auf dem Blatt, hier wurde wohl nicht richtig hoch gezählt)
void abbaAufgabe() {
    clearScreen();

    // jeder Integer kann in einen Char gecastet werden und dann wird einfach das Zeichen, das dem ASCI-Code entspricht genommen
    printf("%c%c%c%c\n\n", 65, 66, 66, 65);

    pressAnyKeyMessage();
}

// Aufgabe 4
void herstellungskostenAufgabe() {
    clearScreen();
    puts("Gewinnberechnung Version 1.0");
    printf("\nBitte geben Sie die fixen Kosten ein: ");
    long fixKosten;
    char fixKostenInput[256];
    fflush(stdin);
    if (fgets(fixKostenInput, sizeof(fixKostenInput), stdin) == NULL) {
        puts("Fehler mit der Eingabe!");
        puts("Drücke eine beliebige Taste zum Fortfahren...");
        fflush(stdin);
        fgetc(stdin);
        return;
    }

    fixKosten = strtol(fixKostenInput, NULL, 10);
    printf("\nBitte geben Sie die Kosten fuer ein Produkt ein: ");
    long produktKosten;
    char produktKostenInput[256];
    fflush(stdin);
    if (fgets(produktKostenInput, sizeof(produktKostenInput), stdin) == NULL) {
        puts("Fehler mit der Eingabe!");
        puts("Drücke eine beliebige Taste zum Fortfahren...");
        fflush(stdin);
        fgetc(stdin);
        return;
    }

    produktKosten = strtol(produktKostenInput, NULL, 10);
    printf("\nBitte geben Sie den Erloes fuer ein Produkt ein: ");
    long produktErloes;
    char produktErloesInput[256];
    fflush(stdin);
    if (fgets(produktErloesInput, sizeof(produktErloesInput), stdin) == NULL) {
        puts("Fehler mit der Eingabe!");
        puts("Drücke eine beliebige Taste zum Fortfahren...");
        fflush(stdin);
        fgetc(stdin);
        return;
    }

    produktErloes = strtol(produktErloesInput, NULL, 10);
    printf("\nWie viele Produkte sollen hergestellt werden:\t");
    long anzahlProdukte;
    char anzahlProdukteInput[256];
    fflush(stdin);
    if (fgets(anzahlProdukteInput, sizeof(anzahlProdukteInput), stdin) == NULL) {
        puts("Fehler mit der Eingabe!");
        puts("Drücke eine beliebige Taste zum Fortfahren...");
        fflush(stdin);
        fgetc(stdin);
        return;
    }

    anzahlProdukte = strtol(anzahlProdukteInput, NULL, 10);

    long produktionsKosten = produktKosten * anzahlProdukte;
    long gesamtErloes = produktErloes * anzahlProdukte;
    long gewinn = gesamtErloes - (produktionsKosten + fixKosten);
    printf("\n\nDer Gewinn betraegt: %d Euro\n\n", gewinn);
    pressAnyKeyMessage();
}

// Aufgabe 5
void lineareGleichung() {
    puts("Lineare Gleichung Version 1.0");
    printf("\nBitte den Wert für a eingeben: ");
    long wertA;
    char wertAInput[256];
    fflush(stdin);
    if (fgets(wertAInput, sizeof(wertAInput), stdin) == NULL) {
        puts("Fehler mit der Eingabe!");
        puts("Drücke eine beliebige Taste zum Fortfahren...");
        fflush(stdin);
        fgetc(stdin);
        return;
    }

    wertA = strtol(wertAInput, NULL, 10);
    printf("\nBitte den Wert für b eingeben: ");
    long wertB;
    char wertBInput[256];
    fflush(stdin);
    if (fgets(wertBInput, sizeof(wertBInput), stdin) == NULL) {
        puts("Fehler mit der Eingabe!");
        puts("Drücke eine beliebige Taste zum Fortfahren...");
        fflush(stdin);
        fgetc(stdin);
        return;
    }

    wertB = strtol(wertBInput, NULL, 10);

    long ergebnis = (0 - wertB) / wertA;

    printf("\n\nDie Loesung lautet: %d\n\n", ergebnis);
    pressAnyKeyMessage();
}

void einUndAusgabeMenue() {
    while (1) {
        clearScreen();
        puts("Aufgaben zur Ein- und Ausgabe:");
        puts("1: Hallo Welt");
        puts("2: Spareinlage");
        puts("3: ABBA");
        puts("4: Herstellungskosten");
        puts("5: lineare Gleichung");
        puts("0: Zurück zum Hauptmenü");
        printf("\nTreffe eine Auswahl: ");
        int input;
        int inputResult = scanf(" %d", &input);
        if (inputResult != EOF && inputResult != 0) {
            switch (input) {
                case 0:
                    return;
                case 1:
                    halloWeltAufgabe();
                    break;
                case 2:
                    spareinlageAufgabe();
                    break;
                case 3:
                    abbaAufgabe();
                    break;
                case 4:
                    herstellungskostenAufgabe();
                    break;
                case 5:
                    lineareGleichung();
                    break;
            }
        }

    }
}