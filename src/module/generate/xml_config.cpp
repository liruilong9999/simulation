#include "xml_config.h"
#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QVariant>

void XMLConfig::saveConfig(const QString & filePath, const QMap<QString, QVariant> & properties)
{
    QFile file(filePath);
    if (file.open(QFile::WriteOnly))
    {
        QXmlStreamWriter writer(&file);
        writer.writeStartElement("config");
        for (auto it = properties.begin(); it != properties.end(); ++it)
        {
            writer.writeStartElement("property");
            writer.writeAttribute("name", it.key());
            writer.writeAttribute("value", it.value().toString());
            writer.writeEndElement();
        }
        writer.writeEndElement();
    }
}

QMap<QString, QVariant> XMLConfig::loadConfig(const QString & filePath)
{
    QMap<QString, QVariant> properties;
    QFile                   file(filePath);
    if (file.open(QFile::ReadOnly))
    {
        QXmlStreamReader reader(&file);
        while (!reader.atEnd())
        {
            if (reader.isStartElement() && reader.name() == "property")
            {
                QString name     = reader.attributes().value("name").toString();
                QString value    = reader.attributes().value("value").toString();
                properties[name] = value;
            }
            reader.readNext();
        }
    }
    return properties;
}
