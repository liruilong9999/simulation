#include "type_registry.h"

TypeRegistry & TypeRegistry::instance()
{
    static TypeRegistry registry;
    return registry;
}

QVariant TypeRegistry::createInstance(const QString & name) const
{
    if (typeFactory.contains(name))
    {
        return typeFactory[name]();
    }
    return QVariant();
}
