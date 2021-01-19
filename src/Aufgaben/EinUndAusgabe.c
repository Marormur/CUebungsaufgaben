//
// Created by Marvin Temmen on 26.03.20.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
    printf("Das Ergebnis der Division lautet      : %f\n\n", (float) zahl1 / (float) zahl2);

    puts("Sch\x94ner sind die Ausgaben so:");
    printf("Das Ergebnis von 100 + 120 = %d\n", zahl2 + zahl1);
    printf("Das Ergebnis von 120 - 100 = %d\n", zahl1 - zahl2);
    printf("Das Ergebnis von 100 * 120 = %d\n", zahl2 * zahl1);
    printf("Das Ergebnis von 120 / 100 = %f\n\n", (float) zahl1 / (float) zahl2);
    pressAnyKeyMessage();
}

// Aufgabe 2
void spareinlageAufgabe() {
    clearScreen();

    // Bei Geld nimmt man immer lieber mal einen double
    printf("Bitte geben Sie ihr Startkapital ein: ");
    double startkapital = strtod(getString(256), NULL);

    printf("Bitte geben Sie den Zinssatz an     : ");
    double zinssatz = strtod(getString(256), NULL);

    // Mit ".2" vor dem "lf" kann man in einem formatierten String die Nachkommastellen eines doubles (oder auch float) auf 2 Stellen begrenzen
    printf("\nDas Endkapital nach 3 Jahren bel\x84uft sich auf %.2lf\n\n", startkapital * pow(1 + zinssatz / 100, 3));
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
    long fixKosten = strtol(getString(256), NULL, 10);
    printf("\nBitte geben Sie die Kosten fuer ein Produkt ein: ");
    long produktKosten = strtol(getString(256), NULL, 10);
    printf("\nBitte geben Sie den Erloes fuer ein Produkt ein: ");
    long produktErloes = strtol(getString(256), NULL, 10);
    printf("\nWie viele Produkte sollen hergestellt werden:\t");
    long anzahlProdukte = strtol(getString(256), NULL, 10);
    long produktionsKosten = produktKosten * anzahlProdukte;
    long gesamtErloes = produktErloes * anzahlProdukte;
    long gewinn = gesamtErloes - (produktionsKosten + fixKosten);
    printf("\n\nDer Gewinn betraegt: %ld Euro\n\n", gewinn);
    pressAnyKeyMessage();
}

// Aufgabe 5
void lineareGleichung() {
    puts("Lineare Gleichung Version 1.0");

    // Wert A abfragen
    printf("\nBitte den Wert für a eingeben: ");
    long wertA = strtol(getString(256), NULL, 10);

    // Wert B abfragen
    printf("\nBitte den Wert für b eingeben: ");
    long wertB = strtol(getString(256), NULL, 10);

    // Nach der Gleichung "ax + b = 0" den Wert für x ausrechnen
    long ergebnis = (0 - wertB) / wertA;
    printf("\n\nDie Loesung lautet: %ld\n\n", ergebnis);
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
        puts("0: Zur\x81 \bck zum Hauptmen\x81");
        printf("\nTreffe eine Auswahl: ");
        long input = strtol(getString(2), NULL, 10);
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
            default:
                // Nur zur Unterdrückung einer Warnung
                break;
        }
    }
}