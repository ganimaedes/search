#include "search.h"
#include <locale>

Search::Search(std::string &find, std::string &fileName) : m_find(find), m_fileName(fileName) 
{
    std::ifstream file_str;
    file_str.open(m_fileName.c_str());
    if (!file_str.is_open()) {
        std::cerr << "Unable to open file " << m_fileName << "\n";
        exit(-1);
    }
    std::string read_line;
    m_lineNumber = 0;
    std::string lower_read_line;
    while (file_str >> read_line) {
        if (file_str.peek() == '\n' || file_str.peek() == '\r') { ++m_lineNumber; }
        for (std::size_t i = 0; i < read_line.length(); ++i) {
            lower_read_line += std::tolower(read_line[i]);
        }
        if (lower_read_line.find(m_find) != std::string::npos) { 
            m_foundMatch = true;
            m_fileNameReturn = m_fileName;
            m_linesFound.push_back(m_lineNumber);
         }
         lower_read_line.clear();
         read_line.clear();
    }
    file_str.close();
}

Search::~Search(){}

std::string Search::getResult() { return m_find; }

std::string Search::getFileName() { return m_fileNameReturn; }

unsigned int Search::getLineNumber() { return m_lineNumber; }

std::vector<unsigned int> Search::getLinesFound() { return m_linesFound; }

bool Search::getFoundMatch() { return m_foundMatch; }
