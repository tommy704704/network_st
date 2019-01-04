#pragma once

#include <QtCore/qglobal.h>

#ifndef QT_STATIC
# if defined(FILETRANSPORTDLL_LIB)
#  define FILETRANSPORTDLL_EXPORT Q_DECL_EXPORT
# else
#  define FILETRANSPORTDLL_EXPORT Q_DECL_IMPORT
# endif
#else
# define FILETRANSPORTDLL_EXPORT
#endif
