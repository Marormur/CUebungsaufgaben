//
// Created by Marvin Temmen on 12.05.20.
//

#include <stdio.h>
#include <stdlib.h>
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
    int zahlenAnzahl = 0;
    int * zahlen = malloc(1);

    while (weiter) {
        printf("Bitte die %d. Zahl eingeben (Abbruch = 0): ", zahlenAnzahl + 1);
        int eingabe = 0;
        scanf(" %d", &eingabe);
        if (!eingabe) {
            weiter = 0;
            break;
        }

        zahlen[zahlenAnzahl] = eingabe;
        zahlenAnzahl++;
        zahlen = (int *)realloc(zahlen, (zahlenAnzahl + 1) * sizeof(*zahlen));
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

void schleifenUndAlternativenMenue() {
    while (1) {
        clearScreen();
        puts("Aufgaben zu Schleifen und Alternativen:");
        puts("1: Zahlenkette");
        puts("2: Zahlenreihe");
        puts("3: Zahleneingabe"); // Zahlen, Zahlen, Zahlen; hier wurde ich richtig kreativ mit den Namen
        puts("4: Passwort");
        puts("5: ");
        puts("6: ");
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
                break;
            case 6:
                break;
            default:
                // Nur zur Unterdrückung einer Warnung
                break;
        }
    }
}