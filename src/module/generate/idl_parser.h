#ifndef IDL_PARSER_H
#define IDL_PARSER_H

#include <QString>
#include <QMap>
#include <QVector>

struct StructInfo
{
    QString                structName;
    QMap<QString, QString> attributes; // 属性名 -> 类型
};

struct IDLInfo
{
    QString                packageName;
    QVector<StructInfo>    structs;
    QMap<QString, QString> handleMap; // 句柄名 -> 类型
};

class IDLParser
{
public:
    static IDLInfo parse(const QString & filePath);
};

#endif // IDL_PARSER_H
