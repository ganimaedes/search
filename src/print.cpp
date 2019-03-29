#include "print.h"

Print::Print(Array<Directories, Files> &array, bool printAllFiles) : m_array(array) 
{
	if (!printAllFiles) {
    	for (std::size_t i = 0; i < m_array.getNDirs(); ++i) {
        	for (int k = 0; k < m_array.getDirs()[i].indent + 1; ++k) { std::cout << "  "; }
        	std::cout << m_array.getDirs()[i].name << "\n";	
    	}	
    } else {
    	printAll(m_array);
    }
}

void Print::printAll(Array<Directories, Files> &array)
{
	std::string prevDir;
	setlocale(LC_CTYPE, "");
	for (std::size_t i = 0; i < array.getNDirs(); ++i) {
		for (std::size_t j = 0; j < array.getNFiles(); ++j) {
			if (j == 0) {
				if (i > 0) {
					prevDir = array.getDirs()[i - 1].name;
				}
				for (int k = 0; k < array.getDirs()[i].indent + 1; ++k) { 
					if (k == array.getDirs()[i].indent) {
						std::cout << collapse << "  ";
					} else {
						std::cout << "  ";
					}
				}
				std::cout << array.getDirs()[i].name << "\n";
			}
			if (array.getDirs()[i].name == array.getFiles()[j].ofDir) {
				for (int n = 0; n < array.getFiles()[j].indent + 2; ++n) { 
					std::cout << (n == array.getFiles()[j].indent + 1 ? "|-" : "  "); 
				}
				std::cout << array.getFiles()[j].name << "\n";
			}	
		}
	}
}
