#ifndef TYPE_REGISTRY_H
#define TYPE_REGISTRY_H

#include <QString>
#include <QVariant>
#include <functional>
#include <QMap>

// ÀàÐÍ×¢²á±í
class TypeRegistry
{
public:
    static TypeRegistry & instance();

    template <typename T>
    void registerType(const QString & name);

    QVariant createInstance(const QString & name) const;

private:
    TypeRegistry() = default;

    QMap<QString, std::function<QVariant()>> typeFactory;
};

#endif // TYPE_REGISTRY_H
