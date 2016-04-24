#ifndef TEST_GLOBAL_H
#define TEST_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef TEST_LIB
# define TEST_EXPORT Q_DECL_EXPORT
#else
# define TEST_EXPORT Q_DECL_IMPORT
#endif

#endif // TEST_GLOBAL_H
