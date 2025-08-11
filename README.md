# AlphaEditor – Qt/C++ Hex- und Binär-Editor

## 📌 Projektbeschreibung
Der **AlphaEditor** ist ein in C++ mit **Qt Widgets** entwickelter Datei-Editor,  
der binäre Dateien **auf Byte-Ebene** anzeigen und bearbeiten kann.  
Jedes Byte wird in **Hexadezimal**, **Binär** und **ASCII** dargestellt.  
Änderungen in einer Darstellung werden automatisch in die anderen Formate übernommen.

Das Projekt wurde im Rahmen des IU-Portfolios entwickelt.

---

## 🖥️ Funktionen
- **Dateien öffnen und speichern**
- **Anzeige pro Byte**:
  - Offset (Speicheradresse)
  - Hexadezimalwert
  - Binärwert
  - ASCII-Zeichen
- **Direkte Bearbeitung in der Tabelle**
  - Synchronisierung aller Darstellungen
  - Eingabevalidierung (nur gültige Werte erlaubt)
- **Suchfunktion**
  - Suche nach Zeichen, Hex- oder Binärfolgen
- **Fehlervermeidung**
  - Schutz vor ungültigen Eingaben
  - Verhindern von Endlosschleifen durch Signal-Blockierung

---

## 🔧 Installation & Ausführung

### Voraussetzungen
- **Qt** (Version 6.x empfohlen)
- **Qt Creator** (für komfortables Bauen und Ausführen)
- **C++ Compiler** (z. B. MinGW oder MSVC)

---

### Schritt-für-Schritt-Anleitung

#### 1️⃣ Projekt herunterladen
**Variante A – GitHub Desktop**
1. **GitHub Desktop** öffnen
2. **File → Clone repository...**
3. URL deines Repositories einfügen (z. B. `https://github.com/DEIN-NAME/alphaeditor`)
4. Zielordner auswählen und **Clone** klicken

**Variante B – Direkt von GitHub**
- Auf **Code → Download ZIP** klicken
- ZIP entpacken

---

#### 2️⃣ Projekt in Qt Creator öffnen
1. Qt Creator starten
2. **Datei → Projekt öffnen**
3. Die Datei `CMakeLists.txt` auswählen
4. Beim ersten Öffnen fragt Qt Creator eventuell nach einem **Kit** (Compiler + Qt-Version) → einfach Standard auswählen

---

#### 3️⃣ Build & Run
1. Unten links auf den **grünen Pfeil** klicken
2. Das Programm startet mit der Hauptoberfläche

---

## 📜 Nutzung
1. **Datei öffnen:** Über den Button „Datei öffnen“ eine beliebige Datei auswählen
2. **Bearbeiten:** Werte in Hex, Bin oder ASCII ändern → andere Spalten werden automatisch aktualisiert
3. **Suchen:** Suchbegriff eingeben und mit dem Button „Suchen“ den ersten Treffer finden
4. **Speichern:** Änderungen über „Speichern“ dauerhaft übernehmen

---

## 👨‍💻 Autor
Dieses Projekt wurde im Rahmen des IU-Studiums im Modul „Programmieren mit C++“ erstellt.
