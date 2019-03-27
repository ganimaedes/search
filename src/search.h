#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Search
{
    std::string m_find;
    std::string m_fileName;
    bool m_foundMatch = false;
    std::string m_fileNameReturn;
    std::vector<unsigned int> m_linesFound;
    unsigned int m_lineNumber;
public:
    Search(std::string &find, std::string &fileName);
    ~Search();
    std::string getResult();
    
    bool getFoundMatch();
    std::string getFileName();
    unsigned int getLineNumber();
    std::vector<unsigned int> getLinesFound();
};

#endif  // SEARCH_H
