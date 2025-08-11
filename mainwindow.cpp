#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidgetItem>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);    // UI initialisieren
    // Tabelle bleibt leer
}

MainWindow::~MainWindow()
{
    delete ui; // UI aufräumen
}

void MainWindow::fillTable() {
    int n = m_model.size();
    qDebug() << "fillTable: Anzahl Zeilen (n) =" << n;

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(n);

    ui->tableWidget->blockSignals(true); // Events blocken

    for(int i = 0; i < n; ++i) {
        const ByteData& b = m_model.get(i);

        // Offset
        QTableWidgetItem* offsetItem = new QTableWidgetItem(QString("%1").arg(i, 8, 16, QChar('0')).toUpper());
        offsetItem->setFlags(offsetItem->flags() & ~Qt::ItemIsEditable);
        ui->tableWidget->setItem(i, 0, offsetItem);

        // Hex
        QTableWidgetItem* hexItem = new QTableWidgetItem(b.toHex());
        ui->tableWidget->setItem(i, 1, hexItem);

        // Bin
        QTableWidgetItem* binItem = new QTableWidgetItem(b.toBin());
        ui->tableWidget->setItem(i, 2, binItem);

        // ASCII
        QTableWidgetItem* asciiItem = new QTableWidgetItem(b.toChar());
        ui->tableWidget->setItem(i, 3, asciiItem);
    }

    ui->tableWidget->blockSignals(false); // Events freigeben
}

void MainWindow::on_btnOpenFile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Datei öffnen");
    if(fileName.isEmpty())
        return;

    if(!m_model.loadFromFile(fileName)) {
        QMessageBox::warning(this, "Fehler", "Konnte Datei nicht laden!");
        return;
    }

    fillTable();

    m_currentFilePath = fileName;
}

void MainWindow::on_btnSaveFile_clicked()
{
    if(m_currentFilePath.isEmpty()) {
        QMessageBox::warning(this, "Fehler", "Keine Datei geladen!");
        return;
    }

    if(!m_model.saveToFile(m_currentFilePath)) {
        QMessageBox::warning(this, "Fehler", "Konnte Datei nicht speichern!");
        return;
    }

    QMessageBox::information(this, "Erfolg", "Datei erfolgreich gespeichert!");
}

void MainWindow::on_tableWidget_itemChanged(QTableWidgetItem *item)
{
    int row = item->row();
    int col = item->column();
    if(row < 0 || row >= m_model.size()) return; // Sicherheitscheck

    ByteData &b = m_model.get(row);

    if(col == 1) {
        b.fromHex(item->text());       // Hex geändert
    }
    else if(col == 2) {
        b.fromBin(item->text());       // Bin geändert
    }
    else if(col == 3) {
        if(item->text().length() > 0)
            b.fromChar(item->text().at(0)); // ASCII geändert
    } else {
        return; // Offset bleibt unverändert
    }

    // Update der Zeile (Signals blockieren)
    ui->tableWidget->blockSignals(true);
    ui->tableWidget->item(row, 1)->setText(b.toHex());
    ui->tableWidget->item(row, 2)->setText(b.toBin());
    ui->tableWidget->item(row, 3)->setText(b.toChar());
    ui->tableWidget->blockSignals(false);
}

void MainWindow::on_btnSearch_clicked()
{
    QString term = ui->lineEditSearch->text().trimmed();
    if(term.isEmpty()) {
        QMessageBox::information(this, "Suche", "Bitte einen Suchbegriff eingeben.");
        return;
    }

    int n = m_model.size();
    for(int i = 0; i < n; ++i) {
        const ByteData& b = m_model.get(i);
        // Suche in Hex, Bin und ASCII
        if (b.toHex().contains(term, Qt::CaseInsensitive) ||
            b.toBin().contains(term) ||
            b.toChar() == term.at(0)) {

            ui->tableWidget->setCurrentCell(i, 0);
            ui->tableWidget->scrollToItem(ui->tableWidget->item(i, 0));
            return;
        }
    }

    QMessageBox::information(this, "Suche", "Kein Treffer gefunden.");
}
