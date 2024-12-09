#include "handle_manager.h"

HandleManager & HandleManager::instance()
{
    static HandleManager manager;
    return manager;
}

HANDLE HandleManager::registerHandle(const QString & name, const QString & typeName)
{
    HANDLE handle           = generateHandle();
    handleToTypeMap[handle] = typeName;
    return handle;
}

QString HandleManager::getTypeName(HANDLE handle) const
{
    return handleToTypeMap.value(handle, "Unknown");
}

HANDLE HandleManager::generateHandle()
{
    return nextHandle++;
}
