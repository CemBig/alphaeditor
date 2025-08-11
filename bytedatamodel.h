#ifndef BYTEDATAMODEL_H
#define BYTEDATAMODEL_H

#include <QVector>
#include <QString>
#include "bytedata.h"

// Liste von ByteData-Objekten
class ByteDataModel
{
public:
    ByteDataModel();

    bool loadFromFile(const QString& path);   // Datei laden
    bool saveToFile(const QString& path);     // Datei speichern

    int size() const;                         // Länge
    ByteData& get(int index);                 // Zugriff schreibend
    const ByteData& get(int index) const;     // Zugriff lesend
    void append(const ByteData& b);           // Byte anhängen

private:
    QVector<ByteData> m_data;                 // Byte-Liste
};

#endif // BYTEDATAMODEL_H
