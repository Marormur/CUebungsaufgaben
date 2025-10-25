# C Übungsaufgaben / C Programming Exercises

[![CMake](https://github.com/Marormur/CUebungsaufgaben/workflows/CMake/badge.svg?event=push)](https://github.com/Marormur/CUebungsaufgaben/actions)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

Eine Sammlung von C-Übungsaufgaben, die im Informatikunterricht entstanden sind. Dieses Projekt deckt grundlegende Konzepte der C-Programmierung ab und dient als Lernressource für Programmieranfänger.

## 📚 Themenübersicht

Das Projekt ist modular aufgebaut und behandelt folgende Themenbereiche:

- **Ein- und Ausgabe** - Grundlagen der Konsoleninteraktion
- **Alternativen** - if/else Verzweigungen und switch-case
- **Schleifen** - for, while, do-while Konstrukte
- **Arrays** - Ein- und mehrdimensionale Arrays
- **Pointer** - Zeiger und Speicherverwaltung
- **Funktionen** - Funktionsdefinition und -aufrufe
- **Sortierverfahren** - Implementierung klassischer Sortieralgorithmen
- **Structs** - Strukturierte Datentypen

## 🚀 Schnellstart

### Voraussetzungen

- CMake (Version 3.8 oder höher)
- Ein C-Compiler (GCC, Clang, MSVC)

### Kompilieren und Ausführen

```bash
# Build-Verzeichnis erstellen
mkdir build
cd build

# CMake konfigurieren
cmake ..

# Projekt kompilieren
cmake --build .

# Programm ausführen (Windows)
.\Debug\CUebungsaufgaben.exe

# Programm ausführen (Linux/Mac)
./CUebungsaufgaben
```

## 💡 Verwendung

Nach dem Start präsentiert das Programm ein interaktives Menü, über das Sie die verschiedenen Übungsaufgaben auswählen und ausführen können. Jede Kategorie enthält mehrere Aufgaben mit Lösungen.

## 📂 Projektstruktur

```
CUebungsaufgaben/
├── src/
│   ├── main.c                    # Hauptprogramm mit Menüsteuerung
│   ├── AllgemeineFunktionen.c/h  # Hilfsfunktionen
│   └── Aufgaben/                 # Übungsaufgaben nach Themen
│       ├── EinUndAusgabe.c/h
│       ├── Alternativen.c/h
│       ├── Schleifen.c/h
│       ├── Arrays.c/h
│       ├── Pointer.c/h
│       ├── Funktionen.c/h
│       ├── Sortierverfahren.c/h
│       └── Structs.c/h
├── CMakeLists.txt                # Build-Konfiguration
└── README.md
```

## 📝 Implementierungsstatus

<details>
<summary>Klicken zum Aufklappen</summary>

- [x] **Ein- und Ausgabebefehle**
- [x] **Alternativen**
- [x] **Schleifen**
- [x] **Schleifen und Alternativen**
- [ ] **Arrays**
    - [ ] Eindimensional
        - [x] Aufgabe 1
        - [x] Aufgabe 2
        - [x] Aufgabe 3
        - [x] Aufgabe 4
        - [x] Aufgabe 5
        - [x] Aufgabe 6
        - [ ] Aufgabe 7
        - [ ] Aufgabe 8
    - [ ] Mehrdimensional
        - [x] Aufgabe 1
        - [ ] Aufgabe 2
- [ ] **Sortierverfahren**
    - [x] Aufgabe 1 
    - [x] Aufgabe 2 
    - [ ] Aufgabe 3 
    - [ ] Aufgabe 4 
    - [ ] Aufgabe 5 
    - [x] Aufgabe 6 
    - [ ] Aufgabe 7 
    - [ ] Aufgabe 8
- [ ] **Stringverarbeitung**
    - [ ] Aufgabe 1
    - [ ] Aufgabe 2
    - [ ] Aufgabe 3
- [ ] **Structs**
    - [ ] Aufgabe 1
    - [ ] Aufgabe 2
    - [ ] Aufgabe 3
    - [ ] Aufgabe 4
- [x] **Funktionen**
- [ ] **Pointer**

</details>

## 🎓 Lernziele

Dieses Projekt demonstriert:

- Modulare Programmstruktur in C
- Verwendung von Header-Dateien
- Build-Management mit CMake
- Plattformübergreifende Entwicklung (Windows/Linux/Mac)
- Klassische Algorithmen und Datenstrukturen

## 🤝 Beiträge

Dies ist ein Lernprojekt. Feedback und Verbesserungsvorschläge sind willkommen!

## 📄 Lizenz

Dieses Projekt steht unter der MIT-Lizenz - siehe [LICENSE](LICENSE) für Details.

## ℹ️ Hinweis

Dieses Projekt entstand im Rahmen des Informatikunterrichts und dient ausschließlich Lernzwecken.
