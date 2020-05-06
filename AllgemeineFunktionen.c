//
// Created by Marvin Temmen on 26.03.20.
//

#include "AllgemeineFunktionen.h"
#include <stdlib.h>
#include <stdio.h>

void clearScreen() {
#if defined(_WIN32)
    system("cls");
#else
    system("clear");
#endif
}

void pressAnyKeyMessage(){
    fflush(stdin);
    puts("Drücke eine beliebige Taste zum Fortfahren...");
    fgetc(stdin);
}
