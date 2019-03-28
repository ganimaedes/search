# Process this file with autoconf to produce a configure script.
AC_PREREQ([2.69])
AC_INIT([search], [0.1], [jenmedal1000@gmx.fr])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([./src/main.cpp]) # ./src/parcours.cpp ./src/print.cpp ./src/search.cpp
AC_CONFIG_HEADERS([./src/config.h])
AC_CONFIG_MACRO_DIRS([m4])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
#AC_CONFIG_FILES([Makefile])
#AX_CXX_COMPILE_STDCXX_11([noext], [mandatory])
AX_CXX_COMPILE_STDCXX() 

# Checks for libraries.
LT_INIT
AC_ENABLE_SHARED
AC_DISABLE_STATIC
AC_PROG_LIBTOOL(libtool)

# Checks for typedefs, structures, and compiler characteristics.
#AC_HEADER_STDBOOL
#AC_C_INLINE
#AC_TYPE_SIZE_T

# Output Makefile files.
AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
