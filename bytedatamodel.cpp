#include "bytedatamodel.h"
#include <QFile>

ByteDataModel::ByteDataModel() {}

bool ByteDataModel::loadFromFile(const QString& path) {
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
        return false;   // Datei nicht lesbar

    m_data.clear();
    QByteArray bytes = file.readAll();
    for(auto b : bytes) {
        m_data.append(ByteData(static_cast<uint8_t>(static_cast<unsigned char>(b)))); // Byte speichern
    }
    return true;
}

bool ByteDataModel::saveToFile(const QString& path) {
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly))
        return false;   // Datei nicht schreibbar

    QByteArray bytes;
    for(const ByteData& b : m_data) {
        bytes.append(static_cast<char>(b.value())); // Bytes sammeln
    }
    file.write(bytes);
    return true;
}

int ByteDataModel::size() const {
    return m_data.size();    // Anzahl Bytes
}

ByteData& ByteDataModel::get(int index) {
    return m_data[index];    // schreibender Zugriff
}

const ByteData& ByteDataModel::get(int index) const {
    return m_data[index];    // lesender Zugriff
}

void ByteDataModel::append(const ByteData& b) {
    m_data.append(b);        // neues Byte anhängen
}
