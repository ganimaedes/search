#ifndef PRINT_H
#define PRINT_H

#include "parcours.h"
#include <locale.h>

#include <iostream>

static const char *collapse = "🗁";

class Print
{
	Array<Directories, Files> &m_array;
public:
	Print(Array<Directories, Files> &array, bool printAllFiles);
	void printAll(Array<Directories, Files> &array);
};

#endif	// PRINT_H

