#ifndef CODE_GENERATOR_H
#define CODE_GENERATOR_H

#include "idl_parser.h"
#include <QString>

class CodeGenerator
{
public:
    static void generateHeaderFile(const IDLInfo & idlInfo, const QString & outputPath);
    static void generateCppFile(const IDLInfo & idlInfo, const QString & outputPath);
};

#endif // CODE_GENERATOR_H
