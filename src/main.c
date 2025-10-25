/**
 * @file main.c
 * @brief Hauptprogramm für C-Übungsaufgaben
 * 
 * Interaktives Menüsystem zur Auswahl und Ausführung verschiedener
 * C-Programmier-Übungen aus dem Informatikunterricht.
 */

#include <stdio.h>
#include <stdlib.h>
#include "AllgemeineFunktionen.h"

// Modulare Organisation: Jedes Thema in separaten Dateien
#include "Aufgaben/EinUndAusgabe.h"
#include "Aufgaben/Alternativen.h"
#include "Aufgaben/Schleifen.h"
#include "Aufgaben/SchleifenUndAlternativen.h"
#include "Aufgaben/Arrays.h"
#include "Aufgaben/Sortierverfahren.h"
#include "Aufgaben/Structs.h"
#include "Aufgaben/Funktionen.h"
#include "Aufgaben/Pointer.h"

/**
 * @brief Haupteinstiegspunkt des Programms
 * 
 * Zeigt ein interaktives Menü mit allen verfügbaren Übungsthemen
 * und ermöglicht die Navigation zwischen verschiedenen Aufgabenbereichen.
 * 
 * @return 0 bei erfolgreicher Ausführung
 */
int main() {
    // Aktiviere UTF-8 für Windows-Konsole (ermöglicht Umlaute)
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
        puts("9: Pointer");
        puts("0: Programm beenden");
        printf("Treffe eine Auswahl: ");

        // Sichere Eingabe-Konvertierung: String -> Long -> Int
        // endptr auf NULL gesetzt, da das Folgezeichen (\n) hier nicht relevant ist
        int eingabe = (int)strtol(getString(2), NULL, 10);
        
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
            case 9:
                pointerMenue();
                break;
            default:
                // Ungültige Eingabe: Verbleibe im Menü
                break;
        }
    }

    return 0;
}
