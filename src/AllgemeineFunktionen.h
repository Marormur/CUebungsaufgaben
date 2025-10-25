/**
 * @file AllgemeineFunktionen.h
 * @brief Sammlung allgemeiner Hilfsfunktionen
 * @author Marvin Temmen
 * @date 26.03.2020
 * 
 * Enthält plattformübergreifende Hilfsfunktionen für Ein-/Ausgabe
 * und String-Verarbeitung.
 */

#ifndef CUEBUNGSAUFGABEN_ALLGEMEINEFUNKTIONEN_H
#define CUEBUNGSAUFGABEN_ALLGEMEINEFUNKTIONEN_H

/**
 * @brief Löscht den Bildschirminhalt der Konsole
 * 
 * Plattformübergreifende Implementierung:
 * - Windows: Verwendet "cls"
 * - Unix/Linux/Mac: Verwendet "clear"
 */
void clearScreen();

/**
 * @brief Zeigt "Drücke eine beliebige Taste..." und wartet auf Eingabe
 * 
 * Nützlich zum Pausieren des Programms, damit der Benutzer
 * Ausgaben lesen kann bevor der Bildschirm gelöscht wird.
 */
void pressAnyKeyMessage();

/**
 * @brief Liest einen String von der Standardeingabe
 * 
 * @param length Maximale Länge des einzulesenden Strings (inklusive \0)
 * @return Dynamisch allokierter String (muss vom Aufrufer freigegeben werden)
 * 
 * @note Der zurückgegebene String muss mit free() freigegeben werden!
 */
char* getString(int length);

/**
 * @brief Erstellt eine Kopie eines Strings
 * 
 * @param sourceString Quell-String der kopiert werden soll
 * @return Dynamisch allokierte Kopie des Strings
 * 
 * @note Der zurückgegebene String muss mit free() freigegeben werden!
 */
char* copyString(char* sourceString);

#endif // CUEBUNGSAUFGABEN_ALLGEMEINEFUNKTIONEN_H
