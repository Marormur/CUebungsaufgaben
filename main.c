#include <stdio.h>
#include <stdlib.h>
#include "AllgemeineFunktionen.h"

// Die einzelnen Übungsblätter sind zur Ordnung in andere Dateien ausgelagert
#include "Aufgaben/EinUndAusgabe.h"
#include "Aufgaben/Alternativen.h"

int main() {
    int exitProgram = 0;
    while (!exitProgram) {
        clearScreen();
        puts("==== Lösungen zu den C Übungsaufgaben ====");
        puts("1: Ein- und Ausgabe");
        puts("2: Alternativen");

        puts("0: Programm beenden");

        char eingabeString[256];
        printf("Treffe eine Auswahl: ");
        if (fgets(eingabeString, 256, stdin) == NULL) {

            // Leere den Inputstream, damit das fgetc nicht übersprungen wird
            fflush(stdin); // Das ist nicht wirklich dokumentiertes Verhalten, funktioniert für meine Zwecke aber trotzden
            puts("Drücke eine beliebige Taste zum Fortfahren...");

            // Hier lese ich so anstatt mit "scanf" aus, damit per Druck auf "Enter" ein "\n" angenommen werden kann
            fgetc(stdin);
            continue;
        }

        long eingabe;

        // Der endptr kann hier auf NULL, da er immer das nächste Zeichen nach der Zahl zurück gibt
        // In diesem Fall wäre das höchstwahrscheinlich "\n" und das brauche ich hier nicht
        eingabe = strtol(eingabeString, NULL, 10);
        switch (eingabe) {
            case 0:
                exitProgram = 1;
                break;
            case 1:
                einUndAusgabeMenue();
                break;
            case 2:
                alternativenMenue();
                break;
            default:
                // Unbehandelt, da man im Menü bleiben soll
                // Dieser Fall dient nur zur Unterdrückung einer Warnung
                break;
        }

        fflush(stdin);
    }

    return 0;
}
