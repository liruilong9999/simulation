#include "idl_parser.h"
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>

IDLInfo IDLParser::parse(const QString & filePath)
{
    IDLInfo idlInfo;
    QFile   file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qFatal("Failed to open file: %s", qPrintable(filePath));
    }

    QTextStream stream(&file);
    QString     content = stream.readAll();

    // 解析包名
    QRegularExpression      packageRegex(R"(package\s+(\w+))");
    QRegularExpressionMatch packageMatch = packageRegex.match(content);
    if (packageMatch.hasMatch())
    {
        idlInfo.packageName = packageMatch.captured(1);
    }

    // 解析结构体
    QRegularExpression              structRegex(R"(struct\s+(\w+)\s*{([^}]*)})");
    QRegularExpressionMatchIterator structMatches = structRegex.globalMatch(content);
    while (structMatches.hasNext())
    {
        QRegularExpressionMatch structMatch = structMatches.next();
        StructInfo              structInfo;
        structInfo.structName = structMatch.captured(1);

        QString                         body = structMatch.captured(2).trimmed();
        QRegularExpression              attributeRegex(R"((\w+)\s+(\w+);)");
        QRegularExpressionMatchIterator attrMatches = attributeRegex.globalMatch(body);
        while (attrMatches.hasNext())
        {
            QRegularExpressionMatch attrMatch            = attrMatches.next();
            structInfo.attributes[attrMatch.captured(2)] = attrMatch.captured(1);
        }
        idlInfo.structs.append(structInfo);
    }

    // 解析句柄
	QRegularExpression handleRegex("\\[\"(.*?)\"\\]\\s*HANDLE\\s+(\\w+)\\s*=\\s*(\\w+::\\w+);");
    QRegularExpressionMatchIterator handleMatches = handleRegex.globalMatch(content);
    while (handleMatches.hasNext())
    {
        QRegularExpressionMatch handleMatch        = handleMatches.next();
        idlInfo.handleMap[handleMatch.captured(2)] = handleMatch.captured(3);
    }

    return idlInfo;
}

