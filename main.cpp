#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);   // Qt App starten
    MainWindow w;                 // Hauptfenster erzeugen
    w.show();                     // anzeigen
    return a.exec();              // Event-Loop
}
