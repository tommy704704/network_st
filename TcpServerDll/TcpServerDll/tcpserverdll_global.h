#ifndef TCPSERVERDLL_GLOBAL_H
#define TCPSERVERDLL_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef TCPSERVERDLL_LIB
# define TCPSERVERDLL_EXPORT Q_DECL_EXPORT
#else
# define TCPSERVERDLL_EXPORT Q_DECL_IMPORT
#endif

#endif // TCPSERVERDLL_GLOBAL_H
