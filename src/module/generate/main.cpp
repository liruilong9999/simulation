#include "idl_parser.h"
#include "code_generator.h"
#include <QDebug>

int main()
{
    // 解析 IDL 文件
    QString filePath = "idl/test.idl";
    IDLInfo idlInfo  = IDLParser::parse(filePath);

    // 生成头文件 (.h)
    QString headerFilePath = idlInfo.packageName + ".h";
    CodeGenerator::generateHeaderFile(idlInfo, headerFilePath);

    // 生成源文件 (.cpp)
    QString cppFilePath = idlInfo.packageName + ".cpp";
    CodeGenerator::generateCppFile(idlInfo, cppFilePath);

    qDebug() << "Code generation completed.";
    return 0;
}
