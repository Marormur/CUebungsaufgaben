# Beitragen / Contributing

Danke für Ihr Interesse an diesem Projekt! 

## 🐛 Fehler melden

Wenn Sie einen Fehler finden:
1. Überprüfen Sie, ob der Fehler bereits gemeldet wurde
2. Erstellen Sie ein neues Issue mit:
   - Beschreibung des Problems
   - Schritte zur Reproduktion
   - Erwartetes vs. tatsächliches Verhalten
   - Ihre Umgebung (OS, Compiler-Version)

## 💡 Verbesserungsvorschläge

Haben Sie Ideen für Verbesserungen?
- Öffnen Sie ein Issue zur Diskussion
- Beschreiben Sie den Nutzen Ihrer Idee
- Falls möglich, skizzieren Sie eine mögliche Umsetzung

## 🔧 Code-Beiträge

1. Forken Sie das Repository
2. Erstellen Sie einen Feature-Branch (`git checkout -b feature/NeueAufgabe`)
3. Committen Sie Ihre Änderungen (`git commit -m 'Füge neue Aufgabe hinzu'`)
4. Pushen Sie den Branch (`git push origin feature/NeueAufgabe`)
5. Öffnen Sie einen Pull Request

### Code-Richtlinien

- Verwenden Sie 4 Leerzeichen für Einrückungen
- Kommentieren Sie komplexe Logik
- Testen Sie Ihre Änderungen vor dem Commit
- Halten Sie die modulare Struktur ein

## 📚 Neue Aufgaben hinzufügen

Beim Hinzufügen neuer Übungsaufgaben:

1. Erstellen Sie entsprechende `.c` und `.h` Dateien in `src/Aufgaben/`
2. Fügen Sie die Aufgabe zum Menü in `main.c` hinzu
3. Aktualisieren Sie die README mit dem neuen Thema
4. Fügen Sie Kommentare hinzu, die den Lernzweck erklären

Beispielstruktur für eine neue Aufgabe:

```c
// NeuesThema.h
#ifndef NEUESTHEMA_H
#define NEUESTHEMA_H

/**
 * @brief Hauptmenü für das Thema "Neues Thema"
 * 
 * Zeigt ein Untermenü mit allen Aufgaben zu diesem Thema
 */
void neuesThemaMenue(void);

#endif // NEUESTHEMA_H
```

## ❓ Fragen?

Bei Fragen können Sie gerne ein Issue öffnen!
