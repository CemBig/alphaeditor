# AlphaEditor – Qt/C++ Hex- und Binär-Editor

## 📌 Projektbeschreibung
Der **AlphaEditor** ist ein in C++ mit **Qt Widgets** entwickelter Datei-Editor,  
der binäre Dateien **auf Byte-Ebene** anzeigen und bearbeiten kann.  
Jedes Byte wird in **Hexadezimal**, **Binär** und **ASCII** dargestellt.  
Änderungen in einer Darstellung werden automatisch in die anderen Formate übernommen.

---

## 🖥️ Funktionsweise – Kurzanleitung
1. **Datei laden** (kleine Testdatei, z. B. `.txt` oder Binärdatei)  
2. Werte in den **Hex-, Binär- oder ASCII-Spalten** bearbeiten  
   - Änderungen werden automatisch auf die anderen Spalten synchronisiert  
3. Über das **Suchfeld** gezielt nach Bytes oder Zeichen suchen  
   - Die Tabelle springt direkt zum ersten Treffer  
4. Änderungen speichern und Datei erneut laden  
   - Alle Änderungen bleiben erhalten

---

## 📂 Struktur der Software

### **Hauptmodule**
- **MainWindow**  
  - Verwaltet die Benutzeroberfläche und die Interaktion zwischen GUI und Datenmodell  
  - Funktionen: Datei öffnen, speichern, Suchfunktion, Synchronisierung der Hex-/Binär-/ASCII-Darstellung in der Tabelle  
  - Enthält die Signal-Slot-Logik für Änderungen in der Tabelle

- **ByteDataModel**  
  - Datenmodell, das den Inhalt der geöffneten Datei als Liste von ByteData-Objekten speichert  
  - Schnittstellen zum Laden, Speichern und gezielten Zugriff auf einzelne Bytes

- **ByteData**  
  - Repräsentiert ein einzelnes Byte  
  - Methoden zur Umwandlung zwischen **Hexadezimal**, **Binär** und **ASCII**  
  - Enthält Validierungslogik, um nur gültige Werte zu übernehmen

- **GUI-Dateien (`.ui`, erstellt im Qt Designer)**  
  - Layout der Benutzeroberfläche  
  - **QTableWidget** für Byte-Daten  
  - Buttons für Dateioperationen (Öffnen, Speichern)  
  - Suchfeld für gezieltes Auffinden von Daten

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
3. URL deines Repositories einfügen (`https://github.com/CemBig/alphaeditor.git`)
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
Dieses Projekt wurde im Rahmen des IU-Studiums im Modul „Programmierung mit C/C++“ erstellt.
