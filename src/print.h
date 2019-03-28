#ifndef PRINT_H
#define PRINT_H

#include "parcours.h"

#include <iostream>
#include <vector>

class Print
{
	std::vector<Directories> &m_array;
public:
	Print(std::vector<Directories> &array, bool printAllFiles);
	void printAll(std::vector<Directories> &array);
};

#endif	// PRINT_H

