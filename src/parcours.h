#ifndef PARCOURS_H
#define PARCOURS_H

#include <dirent.h>
#include <errno.h>
#include <sys/param.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <iostream>
#include <string.h>
#include <string>

#include "array.h"
#include "search.h"

const std::string red("\033[0;31m");
const std::string reset("\033[0m");

struct Directories
{
    std::string name;
    int space;			
};

struct Files
{
    std::string name;
    std::string ofDir;
    std::string previousDir;
    std::size_t lenPreviousDir;
    int space;
};

class Parcours 
{
    char *m_name;
    int m_space;
    
    std::string m_prevDir;
    std::string m_findFile;
    std::string m_findExtension;
    std::string m_strSearchInFile;
    
    bool m_foundExt = false;
    bool m_foundFileName = false;
    
public:
    Parcours();
    void recursiveParcours(char *name, 
                           int space, 
                           Array<Directories, Files> &array,
                           std::string prevDir = "",
                           std::string findFile = "", 
                           std::string findExtension = "", 
                           std::string strSearchInFile = "");
	std::string toLowerStr(std::string &str);
	std::size_t findPositionBegin(std::string &pathToPrint);
	bool foundStr(std::string fileNameToSearch, std::string entry, const bool regardlessOfCaps);
    bool matchExtension(char *name, const char *ext);
    void searchFile(Search &search, std::string &m_path, struct dirent *m_listDir);
};

#endif  // PARCOURS_H
