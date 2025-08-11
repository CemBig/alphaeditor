#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qtablewidget.h>
#include "bytedatamodel.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;    // automatisch von Qt generiert
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;    // Qt-UI
    ByteDataModel m_model; // Datenmodell

    void fillTable();      // Tabelle füllen

    QString m_currentFilePath;   // aktueller Dateipfad

private slots:
    void on_btnOpenFile_clicked();           // Datei öffnen
    void on_btnSaveFile_clicked();           // Datei speichern
    void on_tableWidget_itemChanged(QTableWidgetItem *item); // Tabelle geändert
    void on_btnSearch_clicked();             // Suche
};

#endif // MAINWINDOW_H

