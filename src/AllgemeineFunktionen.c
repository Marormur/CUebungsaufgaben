//
// Created by Marvin Temmen on 26.03.20.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/// <summary>
/// H�lt die Konsole so lange an, bis der Nutzer eine Taste dr�ckt.
/// </summary>
void pressAnyKeyMessage() {
    fflush(stdin);
    puts("Dr�cke eine beliebige Taste zum Fortfahren...");
    fgetc(stdin);
}

// Diese Funktionen sind f�r die Verwendung unter Windows und macOS angepasst
#pragma region CrossplatformFunktionen
/// <summary>
/// Leert die Konsole.
/// </summary>
void clearScreen() {
#if defined(_WIN32)
    system("cls");
#else
    system("clear");
#endif
}

/// <summary>
/// Erm�glicht die Eingabe eines Strings durch den Nutzer. Der enstehende String sollte sp�ter an free() �bergeben werden.
/// </summary>
/// <param name="length">L�nge des Strings, der gelesen werden soll.</param>
/// <returns>Eingabe des Nutzers</returns>
char*  getString(int length) {
    char *input = malloc(length);

    // TODO: hier sollte wieder Fehlerbehandlung rein, erstmal geht Windows
#if defined (_WIN32)
    return _strdup(gets_s(input, length));
#else // Dies hier m�sste noch unter macOS funktionieren
    fflush(stdin);
    if (fgets(input, length, stdin) == NULL) {
        puts("Fehler mit der Eingabe!");
        puts("Dr�cke eine beliebige Taste zum Fortfahren...");
        fflush(stdin);
        fgetc(stdin);
        return NULL;
    }

    return strdup(input);
#endif
}

/// <summary>
/// Kopiert einen String in einen anderen. Der enstehende String sollte sp�ter an free() �bergeben werden.
/// </summary>
/// <param name="sourceString"></param>
/// <returns></returns>
char* copyString(char* sourceString) {
    char* ausgabeString = malloc(sizeof(sourceString));
#if defined (_WIN32) // F�r Windows kann die sichere Variante verwendet werden
    strcpy_s(ausgabeString, sizeof(sourceString), sourceString);
    return _strdup(ausgabeString);
#else
    strcpy(ausgabeString, sourceString);
    return strdup(ausgabeString);
#endif
}
#pragma endregion