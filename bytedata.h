#ifndef BYTEDATA_H
#define BYTEDATA_H

#include <QString>
#include <cstdint>

// Ein Byte mit Hilfsfunktionen
class ByteData
{
public:
    ByteData(uint8_t v = 0);         // Wert setzen

    QString toHex() const;           // Hex-String
    QString toBin() const;           // Binär-String
    QChar toChar() const;            // ASCII-Zeichen

    void fromHex(const QString& hex);    // Wert aus Hex
    void fromBin(const QString& bin);    // Wert aus Binär
    void fromChar(QChar ch);             // Wert aus Zeichen

    uint8_t value() const;           // Wert zurückgeben

private:
    uint8_t m_value;                 // Aktueller Wert
};

#endif // BYTEDATA_H
