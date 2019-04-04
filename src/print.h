#ifndef PRINT_H
#define PRINT_H

#include "parcours.h"
#include <locale.h>

#include <unistd.h>
#include <pwd.h>
#include <string.h>
#include <iostream>

class Print
{
    Array<Directories, Files> &m_array;
    //const char *showWD();
public:
    Print(Array<Directories, Files> &array, bool printAllFiles);
    void printOnlyIndent(Array<Directories, Files> &array);
    void printEffective(Array<Directories, Files> &array, bool printFiles);
};

#endif	// PRINT_H

