#include "parcours.h"

#include <cstdlib>

Parcours::Parcours() 
    : m_fn(nullptr), 
      m_indent(0), 
      m_prevDir(""),
      m_findFile(""), 
      m_findExtension(""), 
      m_strSearchInFile("") 
{}

void Parcours::recursiveParcours(char *fn, 
								 int indent, 
								 Array<Directories, Files> &array,
								 std::string prevDir,
                   				 std::string findFile, 
                   				 std::string findExtension, 
                   				 std::string strSearchInFile)
{
	DIR *dir;
	struct dirent *entry;
	struct stat info;
	std::string path;
	Directories direct = {};
	Files files = {};
	
	if (array.getNDirs() == 0) {
		direct.name = fn;
		direct.indent = indent;
		array.addDir(&direct);
	}
	
    if ((dir = opendir(fn)) == nullptr) {
            std::cerr << "opendir error\n";
    } else {
        while ((entry = readdir(dir)) != nullptr) {
            if (entry->d_name[0] != '.') {
                path = fn;
                path += "/";
                path += entry->d_name;
                if (stat(path.c_str(), &info) != 0) {
                    std::cerr << "Error " << path << " " << errno << "\n";
                } else if (entry->d_type == DT_REG) {
                
                	if (!m_findExtension.empty() && matchExtension(entry->d_name, m_findExtension.c_str())) {
                        m_foundExt = true;
                    }
                    std::string name_entry = entry->d_name;
                    if (!m_findFile.empty() && name_entry.find(m_findFile) != std::string::npos) { 
                    // si on veut str exact : m_findFile.compare(m_entry->d_name) == 0
                        m_foundFileName = true;
                    }
                    
                    if (!m_strSearchInFile.empty() && (m_foundExt || m_foundFileName)) {
                        std::string name = path;
                        Search search(m_strSearchInFile, name);
                        searchFile(search, name, entry);
                    }
                    
                
					files.name = entry->d_name;
					files.indent = indent;
					
					files.ofDir = fn;
					files.previousDir = fn;
					array.addFile(&files); // 2
					
                    m_foundExt = false;
                    m_foundFileName = false;
                    
                } else if (S_ISDIR(info.st_mode)) {
					direct.name = path;
					direct.indent = indent;
					array.addDir(&direct);
                
                    if (!m_findExtension.empty() || !m_strSearchInFile.empty()) {
                        recursiveParcours(const_cast<char *>(path.c_str()), 
                        				  indent + 1, 
                        				  array, 
                        				  m_prevDir, 
                        				  "", 
                        				  m_findExtension, 
                        				  m_strSearchInFile);
                    } else if (!m_findFile.empty()) {
                       
                        recursiveParcours(const_cast<char *>(path.c_str()), 
                        				  indent + 1, 
                        				  array, 
                        				  m_prevDir, 
                        				  m_findFile, 
                        				  "", 
                        				  m_strSearchInFile);
                    }
                   
                	recursiveParcours(const_cast<char *>(path.c_str()), indent + 1, array); // , m_prevDir
                    //recursiveParcours(const_cast<char *>(path.c_str()), indent + 1, array);
                }
            }
        }
        (void)closedir(dir);
    }
}

bool Parcours::matchExtension(char *name, const char *ext)
{
    std::size_t namelen = strlen(name), extlen = strlen(ext);
    return namelen >= extlen && !strcmp(name + namelen - extlen, ext);
}

void Parcours::searchFile(Search &search, std::string m_path, struct dirent *m_entry)
{
    if (!search.getLinesFound().empty()) {
        if (!m_findExtension.empty() || !m_findFile.empty()) {
            std::cout << m_path << "\n";
        }
        std::size_t len = m_path.length() - strlen(m_entry->d_name);
        for (std::size_t i = 0; i < search.getLinesFound().size(); ++i) {
            for (std::size_t j = 0; j < len; ++j) { std::cout << " "; }
            std::cout << red << "l. " << search.getLinesFound()[i] << "\033[m "  
                        << m_strSearchInFile << "\n"; 
        }
    } else if (!search.getFileName().empty()) {
        std::cout << "String not found in " << search.getFileName() << "\n";
    }   
}
