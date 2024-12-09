#include "code_generator.h"
#include <QTextStream>
#include <QFile>

void CodeGenerator::generateHeaderFile(const IDLInfo & idlInfo, const QString & outputPath)
{
    QFile file(outputPath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qFatal("Failed to open header file for writing: %s", qPrintable(outputPath));
    }

    QTextStream stream(&file);

    // 生成头文件内容
    stream << "#ifndef " << idlInfo.packageName.toUpper() << "_H\n";
    stream << "#define " << idlInfo.packageName.toUpper() << "_H\n\n";

    stream << "namespace " << idlInfo.packageName << " {\n";

    // 生成结构体定义
    for (const StructInfo & structInfo : idlInfo.structs)
    {
        stream << "    struct " << structInfo.structName << " {\n";
        for (auto it = structInfo.attributes.begin(); it != structInfo.attributes.end(); ++it)
        {
            stream << "        " << it.value() << " " << it.key() << ";\n";
        }
        stream << "    };\n";
    }

    stream << "}\n";

    stream << "#endif // " << idlInfo.packageName.toUpper() << "_H\n";
}

void CodeGenerator::generateCppFile(const IDLInfo & idlInfo, const QString & outputPath)
{
    QFile file(outputPath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qFatal("Failed to open cpp file for writing: %s", qPrintable(outputPath));
    }

    QTextStream stream(&file);

    // 生成 cpp 文件内容
    stream << "#include \"" << idlInfo.packageName << ".h\"\n";
    stream << "#include \"handle_manager.h\"\n\n";

    for (auto it = idlInfo.handleMap.begin(); it != idlInfo.handleMap.end(); ++it)
    {
        stream << "HANDLE " << it.key() << " = HandleManager::instance().registerHandle(\""
               << it.key() << "\", \"" << it.value() << "\");\n";
    }
}
