#include "print.h"

Print::Print(std::vector<Directories> &array, bool printAllFiles) : m_array(array) 
{
	if (!printAllFiles) {
    	for (std::size_t i = 0; i < m_array.size(); ++i) {
        	for (int k = 0; k < m_array[i].indent + 1; ++k) { std::cout << "  "; }
        	std::cout << m_array[i].name << "\n";	
    	}	
    } else {
    	printAll(m_array);
    }
}

void Print::printAll(std::vector<Directories> &array)
{
	std::string prevDir;
    for (std::size_t i = 0; i < array.size(); ++i) {
        for (std::size_t j = 0; j < array[i].files.size(); ++j) {
            if (j == 0) {
                if (i > 0) {
                        prevDir = array[i - 1].name;
                }
                for (int k = 0; k < array[i].indent + 1; ++k) { std::cout << "  "; }
                std::cout << array[i].name << "\n";
            }
            if (array[i].name == array[i].files[j].ofDir) {
                for (int n = 0; n < array[i].files[j].indent + 2; ++n) { 
                    std::cout << (n == array[i].files[j].indent + 1 ? "|-" : "  "); 
                }
                std::cout << array[i].files[j].name << "\n";
            }	
        }
    }
}
