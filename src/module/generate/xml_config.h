#ifndef XML_CONFIG_H
#define XML_CONFIG_H

#include <QString>
#include <QMap>
#include <QVariant>

class XMLConfig
{
public:
    static void saveConfig(const QString & filePath, const QMap<QString, QVariant> & properties);

    static QMap<QString, QVariant> loadConfig(const QString & filePath);
};

#endif // XML_CONFIG_H
