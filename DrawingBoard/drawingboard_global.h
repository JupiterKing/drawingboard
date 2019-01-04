#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(DRAWINGBOARD_LIB)
#  define DRAWINGBOARD_EXPORT Q_DECL_EXPORT
# else
#  define DRAWINGBOARD_EXPORT Q_DECL_IMPORT
# endif
#else
# define DRAWINGBOARD_EXPORT
#endif
