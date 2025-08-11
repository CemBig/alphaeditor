#include "bytedata.h"
#include <bitset>

ByteData::ByteData(uint8_t v) : m_value(v) {}

QString ByteData::toHex() const {
    return QString("%1").arg(m_value, 2, 16, QChar('0')).toUpper(); // Hex als String
}

QString ByteData::toBin() const {
    return QString::fromStdString(std::bitset<8>(m_value).to_string()); // Binär als String
}

QChar ByteData::toChar() const {
    return QChar(m_value); // ASCII-Zeichen
}

void ByteData::fromHex(const QString& hex) {
    bool ok;
    int val = hex.toInt(&ok, 16);
    if(ok && val >= 0 && val <= 255)
        m_value = static_cast<uint8_t>(val); // Wert setzen aus Hex
}

void ByteData::fromBin(const QString& bin) {
    bool ok;
    int val = bin.toInt(&ok, 2);
    if(ok && val >= 0 && val <= 255)
        m_value = static_cast<uint8_t>(val); // Wert setzen aus Binär
}

void ByteData::fromChar(QChar ch) {
    m_value = ch.unicode() & 0xFF; // Wert aus Zeichen
}

uint8_t ByteData::value() const {
    return m_value; // Wert zurückgeben
}
