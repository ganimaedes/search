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

static const std::string red = "\033[31m";
static const std::string reset = "\033[";

struct Directories
{
	std::string name;
	int indent;			
};

struct Files
{
	std::string name;
	std::string ofDir;
	std::string previousDir;
	int indent;
};

class Parcours 
{
	char *m_fn;
    int m_indent;
    
    std::string m_prevDir;
    std::string m_findFile;
    std::string m_findExtension;
    std::string m_strSearchInFile;
    
    bool m_foundExt = false;
    bool m_foundFileName = false;
    
public:
    Parcours();
	void recursiveParcours(char *fn, 
						   int indent, 
						   Array<Directories, Files> &array,
						   std::string prevDir = "",
    	     			   std::string findFile = "", 
    	     			   std::string findExtension = "", 
    	     			   std::string strSearchInFile = "");
    bool matchExtension(char *name, const char *ext);
    void searchFile(Search &search, std::string m_path, struct dirent *m_entry);
   
};

#endif  // PARCOURS_H
