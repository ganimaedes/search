#include "print.h"
#include "stats.h"

const char *collapse = "🗁";

Print::Print(Array<Directories, Files> &array, bool printAllFiles) : m_array(array) 
{
    printEffective(m_array, printAllFiles);
}

void Print::printOnlyIndent(Array<Directories, Files> &array)
{
    for (std::size_t i = 0; i < array.getNDirs(); ++i) {
        for (int j = 0; j < array.getDirs()[i].space + 1; ++j) {
            std::cout << "  ";
        }
        std::cout << array.getDirs()[i].space << "\n";
    }
}

void Print::printEffective(Array<Directories, Files> &array, bool printFiles)
{
    Stats s;
    std::string curDir, 
                rootFolder,
                sign = "|-",
                espace = "  ";
    setlocale(LC_CTYPE, "");
    std::size_t lenHome = strlen(s.showWD()), 
                rootFolderLen = 0,
                total = 0, 
                totalFiles = 0;
    for (std::size_t i = 0; i < array.getNDirs(); ++i) {
        for (std::size_t j = 0; j < array.getNFiles(); ++j) {
             if (i > 0) {
                curDir = s.folderRearrange(array, i);
            } else {
                rootFolder = s.folderRearrange(array, i);
                rootFolderLen = rootFolder.length();
            }
            if (i == 0 && j == 0) {
                std::cout << array.getDirs()[i].name << "\n";
            }
            if (j == 0) {
                total = lenHome + rootFolderLen + (std::size_t)array.getDirs()[i].space;
                std::size_t k;
                for (k = 0; k < total; ++k) {
                    if (k < lenHome + rootFolderLen) {
                    std::cout << " ";
                } 
                if (k == total - 1) {
                    std::cout << sign + collapse + espace;
                } else if (k >= lenHome + rootFolderLen) { 					
                    std::cout << "|  ";
                } 
            }
            std::cout << curDir << "\n";
            } 
            if (printFiles) {
                if (array.getDirs()[i].name == array.getFiles()[j].ofDir) {
                    totalFiles = lenHome + rootFolderLen + (std::size_t)array.getFiles()[j].space;
                    for (std::size_t a = 0; a < totalFiles; ++a) {
                        if (a < lenHome + rootFolderLen) {
                            std::cout << " ";
                        }
                        if (a >= lenHome + rootFolderLen) {
                            std::cout << "|  ";
                        } else if (a == totalFiles - 1) {
                            std::cout << espace + sign;
                        } 
                    }
                    std::cout << array.getFiles()[j].name << "\n";
                }	
            }
        }
    }
}

