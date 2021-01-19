#include <stdio.h>
#include <stdlib.h>
#include "AllgemeineFunktionen.h"

// Die einzelnen Übungsblätter sind zur Ordnung in andere Dateien ausgelagert
#include "Aufgaben/EinUndAusgabe.h"
#include "Aufgaben/Alternativen.h"
#include "Aufgaben/Schleifen.h"
#include "Aufgaben/SchleifenUndAlternativen.h"
#include "Aufgaben/Arrays.h"
#include "Aufgaben/Sortierverfahren.h"
#include "Aufgaben/Structs.h"
#include "Aufgaben/Funktionen.h"

int main() {
    // Aktiviere UTF-8 für die Windows CMD, damit man einfach Umlaute in Strings verwenden kann
#if defined (_WIN32)
    system("CHCP 65001");
#endif
    
    int exitProgram = 0;
    while (!exitProgram) {
        clearScreen();
        puts("==== Lösungen zu den C Übungsaufgaben ====");
        puts("1: Ein- und Ausgabe");
        puts("2: Alternativen");
        puts("3: Schleifen");
        puts("4: Schleifen und Alternativen");
        puts("5: Arrays");
        puts("6: Sortierverfahren");
        puts("7: Structs");
        puts("8: Funktionen");
        puts("0: Programm beenden");
        printf("Treffe eine Auswahl: ");

        // Der endptr kann hier auf NULL, da er immer das nächste Zeichen nach der Zahl zurück gibt
        // In diesem Fall wäre das höchstwahrscheinlich "\n" und das brauche ich hier nicht
        int eingabe = (int)strtol(getString(2), NULL, 10); // Da das zweite Zeichen das "\n" ist, kann ich einfach den geparsten long zu einem Integer casten, ohne Informationen zu verlieren
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
            case 3:
                schleifenMenue();
                break;
            case 4:
                schleifenUndAlternativenMenue();
                break;
            case 5:
                arraysMenue();
                break;
            case 6:
                sortierVerfahrenMenue();
                break;
            case 7:
                structsMenue();
                break;
            case 8:
                funktionenMenue();
                break;
            default:
                // Unbehandelt, da man im Menü bleiben soll
                // Dieser Fall dient nur zur Unterdrückung einer Warnung
                break;
        }
    }

    return 0;
}
