cmake_minimum_required(VERSION 3.15)
project(CUebungsaufgaben C)

set(CMAKE_C_STANDARD 99)

if(UNIX AND NOT APPLE)
    add_compile_options(-lm)
endif()

add_executable(CUebungsaufgaben "src/main.c" "src/Aufgaben/EinUndAusgabe.c" "src/Aufgaben/EinUndAusgabe.h" "src/AllgemeineFunktionen.c" "src/AllgemeineFunktionen.h" "src/Aufgaben/Alternativen.c" "src/Aufgaben/Alternativen.h" "src/Aufgaben/Schleifen.c" "src/Aufgaben/Schleifen.h" "src/Aufgaben/SchleifenUndAlternativen.c" "src/Aufgaben/SchleifenUndAlternativen.h" "src/Aufgaben/Arrays.c" "src/Aufgaben/Arrays.h" "src/Aufgaben/Sortierverfahren.c" "src/Aufgaben/Sortierverfahren.h" "src/Aufgaben/Structs.c" "src/Aufgaben/Structs.h" "src/Aufgaben/Funktionen.c" "src/Aufgaben/Funktionen.h"   "src/Aufgaben/FunktionenAufgabe2.c" "src/Aufgaben/FunktionenAufgabe2.h")