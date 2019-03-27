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
#include <vector>
//#include <map>

//#include "array.h"
#include "search.h"

static const std::string red = "\033[31m";
static const std::string reset = "\033[";

struct Files//: public Directories
{
	std::string name;
	std::string ofDir;
	int indent;	
	int nFiles;
};

struct Directories
{
	std::string name;
	int indent;	
	std::vector<Files> files;
};

class Parcours 
{
    const char *m_fn;
    int m_indent;
    std::vector<Directories> &m_array; // &
    std::string m_prevDir;
    std::string m_findFile;
    std::string m_findExtension;
    std::string m_strSearchInFile;
    
    
    struct dirent *m_entry;
    struct stat m_info;
    std::string m_path;
    int m_count;
    
    bool m_foundExt = false;
    bool m_foundFileName = false;
    
    //std::vector<std::size_t> m_len;
    //std::map<std::size_t, int> m_lenIndent;
    
public:
    Parcours(char *fn, 
    	     int indent, 
    	     std::vector<Directories> &array, 
			 std::string prevDir = "",
    	     std::string findFile = "", 
    	     std::string findExtension = "", 
    	     std::string strSearchInFile = "");
    bool matchExtension(char *name, const char *ext);
    void searchFile(Search &search);
    void printAll(std::vector<Directories> &array);
};

#endif  // PARCOURS_H
