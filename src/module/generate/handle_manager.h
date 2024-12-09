#ifndef HANDLE_MANAGER_H
#define HANDLE_MANAGER_H

#include <QString>
#include <QMap>

// HANDLE ÀàÐÍ
using HANDLE = unsigned int;

// ¾ä±ú¹ÜÀíÆ÷
class HandleManager
{
public:
    static HandleManager & instance();

    HANDLE  registerHandle(const QString & name, const QString & typeName);
    QString getTypeName(HANDLE handle) const;

private:
    HandleManager() = default;
    HANDLE generateHandle();

    QMap<HANDLE, QString> handleToTypeMap;
    HANDLE                nextHandle = 1;
};

#endif // HANDLE_MANAGER_H
