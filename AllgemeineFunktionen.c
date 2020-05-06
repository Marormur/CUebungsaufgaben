//
// Created by Marvin Temmen on 26.03.20.
//

#include <stdlib.h>
#include <stdio.h>

void clearScreen() {
#if defined(_WIN32)
    system("cls");
#else
    system("clear");
#endif
}

void pressAnyKeyMessage() {
    fflush(stdin);
    puts("Drücke eine beliebige Taste zum Fortfahren...");
    fgetc(stdin);
}

char*  getString(int length){
    char input[length];
    fflush(stdin);
    if (fgets(input, length, stdin) == NULL) {
        puts("Fehler mit der Eingabe!");
        puts("Drücke eine beliebige Taste zum Fortfahren...");
        fflush(stdin);
        fgetc(stdin);
        return NULL;
    }

    return input;
}