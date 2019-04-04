# Process this file with autoconf to produce a configure script.
AC_PREREQ([2.69])
AC_INIT([search], [0.1], [jenmedal1000@gmx.fr])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([./src/main.cpp]) 
AC_CONFIG_HEADERS([./src/config.h])
AC_CONFIG_MACRO_DIRS([m4])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AX_CXX_COMPILE_STDCXX() 

# Checks for libraries.
LT_INIT
AC_ENABLE_SHARED
AC_DISABLE_STATIC
AC_PROG_LIBTOOL(libtool)

# Output Makefile files.
AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
