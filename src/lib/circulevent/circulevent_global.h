#ifndef COMMUNATEMODULE_GLOBAL_H
#define COMMUNATEMODULE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CIRCULEVENT_LIBRARY)
#  define CIRCULEVENT_EXPORT Q_DECL_EXPORT
#else
#  define CIRCULEVENT_EXPORT Q_DECL_IMPORT
#endif

#endif // COMMUNATEMODULE_GLOBAL_H