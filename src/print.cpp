#include "print.h"

Print::Print(std::vector<Directories> &array) : m_array(array) 
{
    //std::string prevDir;
    //std::cout << "m_array.size() = " << m_array.size() << "\n";
    for (std::size_t i = 0; i < m_array.size(); ++i) {
        for (int k = 0; k < m_array[i].indent + 1; ++k) { std::cout << "  "; }
        std::cout << m_array[i].name << "\n";	
    }	
}

