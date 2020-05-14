//
// Created by Marvin Temmen on 12.05.20.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SchleifenUndAlternativen.h"
#include "../AllgemeineFunktionen.h"

// Aufgabe 1
void zahlenkette() {
    clearScreen();
    printf("Bitte eine Zahl eingeben: ");
    long zahl = strtol(getString(256), NULL, 10);
    printf("\nAusgabe: ");
    for (long i = 1; i <= zahl; ++i) {
        printf("%ld, ", i);
    }

    for (long j = zahl-1; j > 0; j--) {
        printf("%ld",j);
        if(j != 1) {
            printf(", ");
        }
    }

    puts("\n");
    pressAnyKeyMessage();
}

int checkForPrimeNumber(int n) {
    int flag = 0;
    for (int i = 2; i <= n / 2; ++i) {

        // condition for non-prime
        if (n % i == 0) {
            flag = 1;
            break;
        }
    }

    if (n == 1) {
        return -1; // Weder noch
    }
    else {
        if (flag == 0)
            return 1; // Primzahl
        else
            return 0; // Keine Primzahl
    }
}

// Aufgabe 2
void zahlenreihe() {
    clearScreen();
    printf("2, 3, ");
    for (int i = 0; i <= 20; ++i) {
        if (!checkForPrimeNumber(i)) {
            printf("%d", i);

            if (i != 20) {
                printf(", ");
            } else {
                puts("\n");
            }
        }
    }

    pressAnyKeyMessage();
}

// Aufgabe 3
void zahleneingabe() {
    clearScreen();
    int weiter = 1;
    size_t zahlenAnzahl = 0;
    int ** zahlen = (int **)malloc(zahlenAnzahl * sizeof(int *));

    while (weiter) {
        printf("Bitte die %lu. Zahl eingeben (Abbruch = 0): ", zahlenAnzahl + 1);
        int eingabe = 0;
        scanf(" %d", &eingabe);
        if (!eingabe) {
            weiter = 0;
            break;
        }

        zahlen[zahlenAnzahl] = eingabe;
        zahlen = (int **)realloc(zahlen, (++zahlenAnzahl) * sizeof(int *));
    }

    int i,j,temp;
    for(i=1;i< sizeof(zahlen);++i){
        for(j=0;j<(sizeof(zahlen)-i);++j)
        {
            if(zahlen[j]>zahlen[j+1])
            {
                temp=zahlen[j];
                zahlen[j]=zahlen[j+1];
                zahlen[j+1]=temp;
            }
        }
    }

    pressAnyKeyMessage();
}

// Aufgabe 4
void passwort() {
    clearScreen();
    puts("Passwort-Eingabe 1");
    char buchstaben[4];
    for (int i = 1; i <= 4; i++) {
        printf("Bitte geben Sie den %d. Buchstaben Ihres Passworts ein: ", i);
        fflush(stdin);
        buchstaben[i - 1] = (char)getc(stdin);

        // Wenn das Zeichen in den Bereich für kleine Buchstaben fällt
        if (buchstaben[i - 1] > 96) {

            // Dann soll daraus ein großer Buchstabe gemacht werden
            buchstaben[i - 1] = (char)(buchstaben[i - 1] - 32);
        }
    }

    // Sortiere die Zeichen der Eingabe
    int i,j,temp;
    for(i=1;i< sizeof(buchstaben);++i){
        for(j=0;j<(sizeof(buchstaben)-i);++j)
        {
            if(buchstaben[j]>buchstaben[j+1])
            {
                temp=buchstaben[j];
                buchstaben[j]=buchstaben[j+1];
                buchstaben[j+1]=temp;
            }
        }
    }

    char password[] = "GOPR";
    int richtigesPasswort = 1;
    for (int k = 0; k < 4; ++k) {
        if (buchstaben[k] != password[k]) {
            richtigesPasswort = 0;
        }
    }

    if (richtigesPasswort) {
        puts("\nLOGIN korrekt\n");
    } else {
        puts("\nLOGIN nicht korrekt\n");
    }

    pressAnyKeyMessage();
}

// Aufgabe 5
void benutzereingabe() {
    clearScreen();
    printf("Bitte geben Sie eine 5 stellige Zahl ein: ");
    char eingabe[256];
    strcpy(eingabe, getString(256));
    long eingabeZahl = strtol(eingabe, NULL, 10);
    if (eingabeZahl >= 100000 || eingabeZahl <=9999) {
        puts("\nUngültige Eingabe! Die Zahl muss 5stellig sein.");
        pressAnyKeyMessage();
        return;
    }

    if(eingabeZahl % 3 == 0) {
        puts("\nUngültige Eingabe! Die Zahl darf nicht durch 3 teilbar sein.");
        pressAnyKeyMessage();
        return;
    }

    if(eingabeZahl % 5 == 0) {
        puts("\nUngültige Eingabe! Die Zahl darf nicht durch 5 teilbar sein.");
        pressAnyKeyMessage();
        return;
    }

    if(eingabeZahl % 7 == 0) {
        puts("\nUngültige Eingabe! Die Zahl darf nicht durch 7 teilbar sein.");
        pressAnyKeyMessage();
        return;
    }

    if (eingabe[0] == 1 && eingabe[4] != 1) {
        puts("\nUngültige Eingabe! Eine Zahl, die mit 1 anfängt, muss auch mit 1 enden.");
        pressAnyKeyMessage();
        return;
    }

    int summeDerErstenZiffern = 0;
    for (int i = 0; i<4;i++) {
        summeDerErstenZiffern += eingabe[i] - '0';
    }

    if (summeDerErstenZiffern % 7 != eingabe[4] - '0') {
        puts("\nUngültige Eingabe! Die 5. Ziffer ist nicht der Rest der Division der Summe der ersten Ziffern durch 7.");
        pressAnyKeyMessage();
        return;
    }

    puts("Eingabe korrekt!");
    pressAnyKeyMessage();
}

void schleifenUndAlternativenMenue() {
    while (1) {
        clearScreen();
        puts("Aufgaben zu Schleifen und Alternativen:");
        puts("1: Zahlenkette");
        puts("2: Zahlenreihe");
        puts("3: Zahleneingabe"); // Zahlen, Zahlen, Zahlen; hier wurde ich richtig kreativ mit den Namen
        puts("4: Passwort");
        puts("5: Benutzereingabe");
        puts("0: Zurück zum Hauptmenü");
        printf("\nTreffe eine Auswahl: ");
        int input = (int)strtol(getString(2), NULL, 10);
        switch (input) {
            case 0:
                return;
            case 1:
                zahlenkette();
                break;
            case 2:
                zahlenreihe();
                break;
            case 3:
                zahleneingabe();
                break;
            case 4:
                passwort();
                break;
            case 5:
                benutzereingabe();
                break;
            default:
                // Nur zur Unterdrückung einer Warnung
                break;
        }
    }
}