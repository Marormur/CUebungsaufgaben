#include <stdio.h>
#include <stdlib.h>
#include "../AllgemeineFunktionen.h"
#include "Schleifen.h"

struct rechnungstype {
    int zahl1, zahl2, zahl3, zahl4;
    char rechenzeichen1, rechenzeichen2;
};

int Add_1(int a, int b) {
    return a + b;
}

void Add_Mul_1(int a, int b, int *aErg, int *mErg) {
    *aErg = a + b;
    *mErg = a * b;
}

void Add_Mul_2(int zahlen[2], int *aErg, int *mErg) {
    *aErg = zahlen[0] + zahlen [1];
    *mErg = zahlen[0] * zahlen [1];
}

int * Add_Mul_3(int zahlen[2]) {
    int ergebnis[2];

    ergebnis[0] = zahlen[0] + zahlen [1];
    ergebnis[1] = zahlen[0] * zahlen [1];

    return ergebnis;
}

struct rechnungstype Add_Mul_4(struct rechnungstype RT) {
    // Unklar, wie rechenzeichen aus Strings verwendet werden können
    RT.zahl3 = RT.zahl1 + RT.zahl2;
    RT.zahl4 = RT.zahl1 * RT.zahl2;

    return RT;
}


int mehrereUebergabeparameter() {

    int Zahl1, Zahl2, Zahl3, Zahl4;
    int Zahlen[2];
    struct rechnungstype rechnung;

    printf("Hinweis: \nAlle Funktionen dieser Aufgabe werden hintereinander ausgeführt.\n"
           "Bitte geben Sie 2 Zahlen ein, mit denen das Programm arbeiten soll: \n");
    scanf("%d", &Zahl1);
    scanf("%d", &Zahl2);

    // Add_1
    printf("Die Funktion ´Add_1´ bekommt 2 Zahlen. Diese werden addiert. Die Rückgabe erfolgt in Einzelwerten.\n"
           "Das ergebnis der Addition ist: %d\n\n", Add_1(Zahl1, Zahl2));

    // Add_Mul_1
    Add_Mul_1(Zahl1, Zahl2, &Zahl3, &Zahl4);
    printf("Die Funktion ´Add_Mul_1´ bekommt 2 Zahlen. Diese werden addiert und multipliziert. Die Rückgabe erfolgt in Einzelwerten.\n"
           "Das ergebnis der Addition ist: %d \nDas Ergebnis der Multiplikation ist: %d\n\n", Zahl3, Zahl4);

    // Add_Mul_2
    Zahlen[0] = Zahl1;
    Zahlen[1] = Zahl2;

    Add_Mul_2(Zahlen, &Zahl3, &Zahl4);
    printf("Die Funktion ´Add_Mul_2´ bekommt ein Zahlen-Array. Die enthaltenen Zahlen werden addiert und multipliziert. Die Rückgabe erfolgt in Einzelwerten.\n"
           "Das ergebnis der Addition ist: %d \nDas Ergebnis der Multiplikation ist: %d\n\n", Zahl3, Zahl4);

    // Add_Mul_3
    int *ergebnisMul3 = Add_Mul_3(Zahlen);
    printf("Die Funktion ´Add_Mul_3´ bekommt ein Zahlen-Array. Die enthaltenen Zahlen werden addiert und multipliziert. Die Rückgabe erfolgt als Array. \n"
           "Das ergebnis der Addition ist: %d \nDas Ergebnis der Multiplikation ist: %d\n\n", ergebnisMul3[0], ergebnisMul3[1]);

    // Add_Mul_4
    rechnung.zahl1 = Zahl1;
    rechnung.zahl2 = Zahl2;
    rechnung.rechenzeichen1 = '+';
    rechnung.rechenzeichen2 = '*';

    struct rechnungstype ergebnisRechnung = Add_Mul_4(rechnung);
    printf("Die Funktion ´Add_Mul_4´ bekommt ein Struct. Die enthaltenen Zahlen werden addiert und multipliziert. Die Rückgabe erfolgt als Struct. \n"
           "Das ergebnis der Addition ist: %d \nDas Ergebnis der Multiplikation ist: %d\n\n", ergebnisRechnung.zahl3, ergebnisRechnung.zahl4);


    return (0);
}

void pointerMenue() {
    while (1) {
        clearScreen();
        puts("Aufgaben zu Pointer:");
        puts("0: Zur�ck zum Hauptmen�");
        puts("1: Mehrere Uebergabeparameter");
        printf("\nTreffe eine Auswahl: ");
        int input = (int)strtol(getString(2), NULL, 10);
        switch (input) {
        case 0:
            return;
        case 1:
            mehrereUebergabeparameter();
            break;
        default:
            // Nur zur Unterdr�ckung einer Warnung
            break;
        }
    }
}
